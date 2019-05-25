/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GenesysShell.cpp
 * Author: rlcancian
 * 
 * Created on 23 de Maio de 2019, 13:02
 */

#include "GenesysShell.h"
#include "Simulator.h"
#include "Assign.h"
#include <regex>

GenesysShell::GenesysShell() {
    _commands->setSortFunc([](const ShellCommand* a, const ShellCommand * b) {
        return a->shortname < b->shortname;
    });
    _commands->insert(new ShellCommand("q", "quit", "Quit ReGenesys shell. Same as exit.", DefineExecuterMember<GenesysShell>(this, &GenesysShell::cmdQuit)));
    _commands->insert(new ShellCommand("x", "exit", "Exit ReGenesys shell. Same as quit.", DefineExecuterMember<GenesysShell>(this, &GenesysShell::cmdQuit)));
    _commands->insert(new ShellCommand("h", "help", "Show help for commands.", DefineExecuterMember<GenesysShell>(this, &GenesysShell::cmdHelp)));
    _commands->insert(new ShellCommand("lm", "modelload", "Show help for commands.", DefineExecuterMember<GenesysShell>(this, &GenesysShell::cmdModelLoad)));
}

GenesysShell::GenesysShell(const GenesysShell& orig) {
}

GenesysShell::~GenesysShell() {
}

void GenesysShell::cmdHelp() {
    ShellCommand* command;
    Trace("List of commands:");
    Trace("" + Util::SetW("Short", 6) + "" + Util::SetW("Long", 20) + "  " + "Description");

    for (std::list<ShellCommand*>::iterator it = _commands->getList()->begin(); it != _commands->getList()->end(); it++) {
        //Trace("Unknown command. Type \"-h\" or \"help\" for help on possible commands.");
        command = (*it);
        Trace("" + Util::SetW(command->shortname, 6) + "" + Util::SetW(command->longname, 20) + ": " + command->descrition);
    }
}

void GenesysShell::cmdQuit() {
    Trace("Quiting/Exiting. Goodbye");
    exit(0);
}

void GenesysShell::cmdModelLoad() {
    this->_parameters;
}

void GenesysShell::Trace(std::string message) {
    std::cout << message << std::endl;
}

void GenesysShell::run(List<std::string>* arguments) {
    Trace("ReGenesys Shell is running. Type your command. For help, type the command \"h\" or \"help\".");
    std::string typedCommandStr, inputText;
    ShellCommand* command;
    bool found;
    std::regex regex{R"([\s]+)"}; // split on space
    while (true) {
        if (!arguments->empty()) {
            inputText = arguments->first();
            arguments->pop_front();
        } else {
            std::cout << _prompt << " ";
            std::cin >> inputText;
        }
        std::sregex_token_iterator it{inputText.begin(), inputText.end(), regex, -1};
        std::vector<std::string> words{it,{}};
        _parameters = &words;
        typedCommandStr = *words.begin();
        std::transform(typedCommandStr.begin(), typedCommandStr.end(), typedCommandStr.begin(), ::tolower);
        if (typedCommandStr.substr(0, 1) != "#") {
            found = false;
            for (std::list<ShellCommand*>::iterator it = _commands->getList()->begin(); it != _commands->getList()->end(); it++) {
                //Trace("Unknown command. Type \"-h\" or \"help\" for help on possible commands.");
                command = (*it);
                if (typedCommandStr == "" + command->shortname || typedCommandStr == "" + command->longname) {
                    command->executer();
                    found = true;
                    break;
                }
            }
            if (!found) {
                Trace("Command not found. Type \"h\" or \"help\" for help.");
            }
        }
    }
}

int GenesysShell::main(int argc, char** argv) {
    List<std::string>* arguments = new List<std::string>();
    for (unsigned short i = 1; i < argc; i++) {
        std::string arg = argv[i];
        arguments->insert(arg);
    }
    this->run(arguments);
    return 0;
}