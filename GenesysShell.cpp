/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GenesysShell.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 23 de Maio de 2019, 13:02
 */

#include "GenesysShell.h"
#include "Simulator.h"
#include "Assign.h"
#include <regex>
#include <fstream>
#include <assert.h>

#include "ProbDistrib.h"

GenesysShell::GenesysShell() {
    _commands->setSortFunc([](const ShellCommand* a, const ShellCommand * b) {
        return a->shortname < b->shortname;
    });
    _commands->insert(new ShellCommand("q", "quit", "", "Quit ReGenesys shell. Same as exit.", DefineExecuterMember<GenesysShell>(this, &GenesysShell::cmdQuit)));
    _commands->insert(new ShellCommand("x", "exit", "", "Exit ReGenesys shell. Same as quit.", DefineExecuterMember<GenesysShell>(this, &GenesysShell::cmdQuit)));
    _commands->insert(new ShellCommand("h", "help", "", "Show help for commands.", DefineExecuterMember<GenesysShell>(this, &GenesysShell::cmdHelp)));
    _commands->insert(new ShellCommand("sm", "modelsave", "<filename>", "Save model.", DefineExecuterMember<GenesysShell>(this, &GenesysShell::cmdModelSave)));
    _commands->insert(new ShellCommand("lm", "modelload", "<filename>", "Load Model.", DefineExecuterMember<GenesysShell>(this, &GenesysShell::cmdModelLoad)));
    _commands->insert(new ShellCommand("rf", "readfile", "<filename>", "Read and execute shell command from file.", DefineExecuterMember<GenesysShell>(this, &GenesysShell::cmdScript)));
    _commands->insert(new ShellCommand("v", "version", "", "Show the version.", DefineExecuterMember<GenesysShell>(this, &GenesysShell::cmdVersion)));
}

GenesysShell::GenesysShell(const GenesysShell& orig) {
}

GenesysShell::~GenesysShell() {
}

void GenesysShell::cmdHelp() {
    ShellCommand* command;
    Trace("List of commands:");
    Trace(Util::SetW("Short", 6) + Util::SetW("Long", 12) + Util::SetW("Parameters", 15) + "Description");
    for (std::list<ShellCommand*>::iterator it = _commands->getList()->begin(); it != _commands->getList()->end(); it++) {
        //Trace("Unknown command. Type \"-h\" or \"help\" for help on possible commands.");
        command = (*it);
        Trace(Util::SetW(command->shortname, 6) + Util::SetW(command->longname, 12) + Util::SetW(command->parameters, 15) + command->descrition);
    }
}

void GenesysShell::cmdQuit() {
    Trace("Quiting/Exiting. Goodbye");
    exit(0);
}

void GenesysShell::cmdVersion() {
    Trace("ReGenesys Shell version 2019.0528");
}

void GenesysShell::cmdModelLoad() {
    Trace("Model load");
    try {
        std::string filename = _parameter;
        Model* model = new Model(this->_simulator);
        model->loadModel(filename);
    } catch (...) {
        //        _commands
    }
}

void GenesysShell::cmdModelSave() {
    this->_parameter;
}

void GenesysShell::cmdScript() {
    std::string filename = this->_parameter;
    //List<std::string>* arguments = new List<std::string>();
    std::ifstream commandfile;
    std::string inputText;
    try {
        commandfile.open(filename);
        while (getline(commandfile, inputText)) {
            this->tryExecuteCommand(inputText, "", "", " ");
        }
        commandfile.close();
    } catch (...) {
    }
}

void GenesysShell::Trace(std::string message) {
    std::cout << message << std::endl;
}

void GenesysShell::run(List<std::string>* commandlineArgs) {
    Trace("ReGenesys Shell is running. Type your command. For help, type the command \"h\" or \"help\".");
    std::string inputText; //, shortPrefix, longPrefix, separator;
    while (true) {
        if (!commandlineArgs->empty()) {
            inputText = commandlineArgs->first();
            commandlineArgs->pop_front();
            tryExecuteCommand(inputText, "-", "--", "=");
        } else {
            std::cout << _prompt << " ";
            std::cin >> inputText;
            tryExecuteCommand(inputText, "", "", " ");

        }
    }
}

void GenesysShell::tryExecuteCommand(std::string inputText, std::string shortPrefix, std::string longPrefix, std::string separator) {
    std::regex regex{R"([=]+)"}; // split on space R"([\s]+)"
    std::sregex_token_iterator it{inputText.begin(), inputText.end(), regex, -1};
    std::vector<std::string> fields{it,{}};
    std::string typedCommandStr = fields[0];
    if (fields.size() > 1) { // its a comnd and a paramater in the form command=parameter
        assert(fields.size() == 2);
        _parameter = fields[1];
    } else {
        _parameter = "";
    }
    ShellCommand* command;
    bool found;
    std::transform(typedCommandStr.begin(), typedCommandStr.end(), typedCommandStr.begin(), ::tolower);
    if (typedCommandStr.substr(0, 1) != "#") {
        found = false;
        for (std::list<ShellCommand*>::iterator it = _commands->getList()->begin(); it != _commands->getList()->end(); it++) {
            //Trace("Unknown command. Type \"-h\" or \"help\" for help on possible commands.");
            command = (*it);
            if (typedCommandStr == shortPrefix + command->shortname || typedCommandStr == longPrefix + command->longname) {
                command->executer();
                found = true;
                break;
            }
        }
        if (!found) {
            Trace("Command \"" + typedCommandStr + "\" not found. Type \"h\" or \"help\" for help.");
        }
    }

}

int GenesysShell::main(int argc, char** argv) {
    //double res;
    //for (double x = -3.0; x <= 3.0; x += 0.05) {
    //    res = ProbDistrib::tStudent(x, 0, 1, 100);
    //    std::cout << x << ": " << res << std::endl;
    //}
    //return 0;
    List<std::string>* commandlineArgs = new List<std::string>();
    for (unsigned short i = 1; i < argc; i++) {
        std::string arg = argv[i];
        commandlineArgs->insert(arg);
    }
    commandlineArgs->insert("-rf=temp/script.txt");
    this->run(commandlineArgs);
    return 0;
}