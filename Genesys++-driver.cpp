#include "Genesys++-driver.h"
#include <string>


genesyspp_driver::genesyspp_driver ()
{
}

genesyspp_driver::genesyspp_driver(Model* model, bool throws)
{
  _model = model;
  probs = ProbDistrib();
  throwsException = throws;
}

genesyspp_driver::~genesyspp_driver ()
{
}

int
genesyspp_driver::parse_file (const std::string &f)
{
  result = 0;
  file = f;
  scan_begin_file();
  yy::genesyspp_parser parser (*this);
  int res = parser.parse();
  scan_end_file();
  return res;
}

int
genesyspp_driver::parse_str (const std::string &str)
{
  result = 0;
  str_to_parse = str;
  scan_begin_str();
  yy::genesyspp_parser parser(*this);
  int res = parser.parse();
  scan_end_str();
  return res;
}

void genesyspp_driver::setResult(double value)
{
    result = value;
}

double genesyspp_driver::getResult(){
  return result;
}

bool genesyspp_driver::getThrowsException(){
  return throwsException;
}

void genesyspp_driver::setThrowsException(bool throws){
  throwsException = throws;
}

void genesyspp_driver::setErrorMessage(std::string message){
  errorMessage = message;
}

std::string genesyspp_driver::getErrorMessage(){
  return errorMessage;
}

Model* genesyspp_driver::getModel(){
  return _model;
}

ProbDistrib genesyspp_driver::getProbs(){
  return probs;
}

std::string genesyspp_driver::getFile(){
  return file;
}

void genesyspp_driver::setFile(std::string f){
  file = f;
}

std::string genesyspp_driver::getStrToParse(){
  return str_to_parse;
}

void genesyspp_driver::setStrToParse(std::string str){
  str_to_parse = str;
}


void
genesyspp_driver::error (const yy::location& l, const std::string& m)
{
  //std::string erro(l);
  std::string erro(m);
  //erro.append(":");
  //erro.append(m);
  erro.append("\n");
  _model->getTracer()->trace(Util::TraceLevel::errors,erro);
}

void
genesyspp_driver::error (const std::string& m)
{
  _model->getTracer()->trace(Util::TraceLevel::errors,m);
}
