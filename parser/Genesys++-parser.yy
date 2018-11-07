%skeleton "lalr1.cc" /* -*- C++ -*- */
%require "3.0.5"
%defines
%define parser_class_name {genesyspp_parser} //Name of the parses class
%define api.token.constructor //let that way or change YY_DECL prototype
%define api.value.type variant
%define parse.assert //Checks for constructor and destructor(?)
%code requires
{
#include <string>
#include <cmath>
#include "obj_t.h"
#include "Util.h"
#include "Variable.h"
#include "Queue.h"
#include "Resource.h"
class genesyspp_driver;

}

//%define api.value.type {obj_t} //c++ types for semantic values
 //c++ types for semantic values
// The parsing context.
%param { genesyspp_driver& driver } //aditional params for yylex/yyparse
%locations // allows for more accurate syntax error messages.
%initial-action
{
  // Initialize the initial location.
  @$.begin.filename = @$.end.filename = &driver.getFile();
};
%define parse.trace //for debugging
%define parse.error verbose //error level to show
%code
{
# include "Genesys++-driver.h"

}

%token <obj_t> NUMD
%token <obj_t> NUMH
%token <obj_t> ATRIB
%token <obj_t> VARI
%token <obj_t> FORM
%token <obj_t> QUEUE
%token <obj_t> RES
%token <obj_t> oLE
%token <obj_t> oGE
%token <obj_t> oEQ
%token <obj_t> oNE
%token <obj_t> oAND
%token <obj_t> oOR
%token <obj_t> oNOT
%token <obj_t> fSIN
%token <obj_t> fCOS
%token <obj_t> fAINT
%token <obj_t> fMOD
%token <obj_t> fINT
%token <obj_t> fFRAC
%token <obj_t> fEXPO
%token <obj_t> fNORM
%token <obj_t> fUNIF
%token <obj_t> fWEIB
%token <obj_t> fLOGN
%token <obj_t> fGAMM
%token <obj_t> fERLA
%token <obj_t> fTRIA
%token <obj_t> fBETA
%token <obj_t> fDISC
%token <obj_t> fTNOW
%token <obj_t> fTFIN
%token <obj_t> fNR
%token <obj_t> fMR
%token <obj_t> fIRF
%token <obj_t> fRESSEIZES
%token <obj_t> fSTATE
%token <obj_t> fNQ
%token <obj_t> fFIRSTINQ
%token <obj_t> fLASTINQ
%token <obj_t> cIF
%token <obj_t> cELSE
%token <obj_t> cFOR
%token <obj_t> cTO
%token <obj_t> cDO
%token <obj_t> ILLEGAL     /* illegal token */
%token <obj_t> TESTE
%token LPAREN "("
%token RPAREN ")"
%token PLUS "+"
%token MINUS "-"
%token STAR "*"
%token SLASH "/"
%token LESS "<"
%token GREATER ">"
%token ASSIGN "="
%token COMMA ","
//%token <obj_t> END //EOF
%token END 0 "end of file" //need to declare, as bison doesnt in especific situation

%type <obj_t> tes
%type <obj_t> input
%type <obj_t> programa
%type <obj_t> expressao
%type <obj_t> aritmetica
%type <obj_t> relacional
%type <obj_t> comando
%type <obj_t> comandoIF
%type <obj_t> comandoFOR
%type <obj_t> funcao
%type <obj_t> numero
%type <obj_t> atributo
%type <obj_t> atribuicao
%type <obj_t> variavel
%type <obj_t> formula
%type <obj_t> funcaoTrig
%type <obj_t> funcaoArit
%type <obj_t> funcaoProb
%type <obj_t> funcaoStrc
%type <obj_t> funcaoUser
%type <obj_t> listaparm
%type <obj_t> illegal

%left oNOT
%left oAND oOR
%left oLE oGE oEQ oNE '<' '>'
%left '+' '-'
%left '*' '/'
%left fAINT fMOD fINT fFRAC

%right MINUS

//%printer { yyoutput << $$; } <*>; //prints whren something
%%

input	    : /* empty */
           | input '\n' {YYACCEPT;}
           | input programa                                     { driver.setResult($2.valor); driver.getModel()->trace(Util::TraceLevel::mostDetailed, std::string("Resultado"));}
           | illegal
           | error '\n'                                         { yyerrok; }
           ;

programa   : expressao                                          { $$.valor = $1.valor;}
     	     ;

expressao   : aritmetica                                        {$$.valor = $1.valor;}
            | relacional                                        {$$.valor = $1.valor;}
            | "(" expressao ")"                                 {$$.valor = $2.valor;}
            | funcao                                            {$$.valor = $1.valor;}
            | ATRIB                                             {$$.valor = $1.valor;}
            | variavel                                          {$$.valor = $1.valor;}
            | formula                                           {$$.valor = $1.valor;}
            | numero                                            {$$.valor = $1.valor;}
            | comando                                           {}
            ;

numero      : NUMD                                              { $$.valor = $1.valor;}
            | NUMH                                              { $$.valor = $1.valor;}
            ;

aritmetica  : expressao "+" expressao                           { $$.valor = $1.valor + $3.valor;}
            | expressao "-" expressao                           { $$.valor = $1.valor - $3.valor;}
            | expressao "/" expressao                           { $$.valor = $1.valor / $3.valor;}
            | expressao "*" expressao                           { $$.valor = $1.valor * $3.valor;}
            ;

relacional  : expressao oAND expressao                          { $$.valor = (int) $1.valor && (int) $3.valor;}
            | expressao oOR  expressao                          { $$.valor = (int) $1.valor || (int) $3.valor;}
            | expressao "<"  expressao                          { $$.valor = $1.valor < $3.valor ? 1 : 0;}
            | expressao oLE  expressao                          { $$.valor = $1.valor <= $3.valor ? 1 : 0;}
            | expressao ">"  expressao                          { $$.valor = $1.valor > $3.valor ? 1 : 0;}
            | expressao oGE  expressao                          { $$.valor = $1.valor >= $3.valor ? 1 : 0;}
            | expressao oEQ  expressao                          { $$.valor = $1.valor == $3.valor ? 1 : 0;}
            | expressao oNE  expressao                          { $$.valor = $1.valor != $3.valor ? 1 : 0;}
            ;

comando     : comandoIF
            | comandoFOR
            ;

comandoIF   : cIF "(" expressao ")" expressao cELSE expressao   {$$.valor = $3.valor != 0 ? $5.valor : $7.valor;}
            | cIF "(" expressao ")" expressao                   {$$.valor = $3.valor != 0 ? $5.valor : 0;}
            ;
//Check for function/need, for now will let cout
comandoFOR  : cFOR variavel "=" expressao cTO expressao cDO atribuicao  {$$.valor = 0; 																							std::cout << "FOR " << $4.valor << " TO " << $6.valor << " DO " << $8.valor << '\n';}
            | cFOR atributo "=" expressao cTO expressao cDO atribuicao  {$$.valor = 0; 																							std::cout << "FOR " << $4.valor << " TO " << $6.valor << " DO " << $8.valor << '\n';}
            ;

funcao      : funcaoArit                                        { $$.valor = $1.valor; }
            | funcaoTrig                                        { $$.valor = $1.valor; }
            | funcaoProb                                        { $$.valor = $1.valor; }
            | funcaoStrc                                        { $$.valor = $1.valor; }
            | funcaoUser                                        { $$.valor = $1.valor; }
            ;


//Attribute not fully implemented on GenESyS, for now does nothing
atributo    : ATRIB                                             { $$.valor = $1.valor; }
            ;

//Check if want to set the atributo or variavel with expressao or just return the expressao value, for now just returns expressao value
atribuicao  : atributo "=" expressao                            { $$.valor = $3.valor; }
            | variavel "=" expressao                            { $$.valor = $3.valor; }
            ;
//My implementation, check with teacher
variavel    : VARI                                              { $$.valor = ((Variable*)(driver.getModel()->getInfrastructure(Util::TypeOf<Variable>(), $1.id)))->getValue();} //change
            | VARI "[" expressao "]"                            { $$.valor = ((Variable*)(driver.getModel()->getInfrastructure(Util::TypeOf<Variable>(), $1.id)))->getValue(std::to_string($3.valor));}
            | VARI "[" expressao "," expressao "]"              { std::string index(std::to_string($3.valor)); index.append(","); index.append(std::to_string($5.valor)); $$.valor = ((Variable*)(driver.getModel()->getInfrastructure(Util::TypeOf<Variable>(), $1.id)))->getValue(index);}
            ;

//Formula not implemented, so will just receive a number
formula     : NUMD                                              { $$.valor = $1.valor;} //Formula not implemented on GenESyS
            ;

funcaoTrig  : fSIN   "(" expressao ")"                          { $$.valor = sin($3.valor);                                         std::cout << "Sin(" << $3.valor << "):" << $$.valor << '\n';}
            | fCOS   "(" expressao ")"                          { $$.valor = cos($3.valor); 																				std::cout << "Cos(" << $3.valor << "):" << $$.valor << '\n';}
            ;

funcaoArit  : fAINT  "(" expressao ")"                          { $$.valor = (int) $3.valor;}
            | fFRAC  "(" expressao ")"                          { $$.valor = $3.valor - (int) $3.valor;}
            | fINT   "(" expressao ")"                          { $$.valor = (int) $3.valor;}
            | fMOD   "(" expressao "," expressao ")"            { $$.valor = (int) $3.valor % (int) $5.valor; }
            ;

funcaoProb  : fEXPO  "(" expressao ")"                                            { $$.valor = driver.getProbs().exponential(0,$3.valor); $$.tipo = "Exponencial";}
            | fNORM  "(" expressao "," expressao ")"                              { $$.valor = driver.getProbs().normal(0,$3.valor,$5.valor); $$.tipo = "Normal"; }
            | fUNIF  "(" expressao "," expressao ")"                              { $$.valor = driver.getProbs().uniform(0,$3.valor,$5.valor); $$.tipo = "Unificada"; }
            | fWEIB  "(" expressao "," expressao ")"                              { $$.valor = driver.getProbs().weibull(0,$3.valor,$5.valor); $$.tipo = "Weibull"; }
            | fLOGN  "(" expressao "," expressao ")"                              { $$.valor = driver.getProbs().logNormal(0,$3.valor,$5.valor); $$.tipo = "LOGNormal"; }
            | fGAMM  "(" expressao "," expressao ")"                              { $$.valor = driver.getProbs().gamma(0,$3.valor,$5.valor); $$.tipo = "Gamma"; }
            | fERLA  "(" expressao "," expressao ")"                              { $$.valor = driver.getProbs().erlang(0,$3.valor,$5.valor); $$.tipo = "Erlang"; }
            | fTRIA  "(" expressao "," expressao "," expressao ")"                { $$.valor = driver.getProbs().triangular(0,$3.valor,$5.valor,$7.valor); $$.tipo = "Triangular"; }
            | fBETA  "(" expressao "," expressao ")"                              { $$.valor = driver.getProbs().beta(0,$3.valor,$5.valor); $$.tipo = "Beta"; }
            | fDISC  "(" listaparm ")"
            ;

funcaoStrc  : fNQ       "(" QUEUE ")"                           { $$.valor = ((Queue*)(driver.getModel()->getInfrastructure(Util::TypeOf<Queue>(), $3.id)))->size();}
            | fLASTINQ  "(" QUEUE ")"                           {/*For now does nothing because need acces to list of QUEUE, or at least the last element*/ }
            | fFIRSTINQ "(" QUEUE ")"                           { if (((Queue*)(driver.getModel()->getInfrastructure(Util::TypeOf<Queue>(), $3.id)))->size() > 0){
                                                                    $$.valor = ((Queue*)(driver.getModel()->getInfrastructure(Util::TypeOf<Queue>(), $3.id)))->first()->getEntity()->getId();
                                                                  }else{
                                                                    $$.valor = 0;
                                                                  }
                                                                }
           | fMR        "(" RES ")"                            { $$.valor = ((Resource*)driver.getModel()->getInfrastructure(Util::TypeOf<Resource>(), $3.id))->getCapacity();}
           | fNR        "(" RES ")"                            { $$.valor = ((Resource*)driver.getModel()->getInfrastructure(Util::TypeOf<Resource>(), $3.id))->getNumberBusy();}
           | fRESSEIZES "(" RES ")"                            { /*For now does nothing because needs get Seizes, check with teacher*/}
           | fSTATE     "(" RES ")"                            {  switch(((Resource*)driver.getModel()->getInfrastructure(Util::TypeOf<Resource>(), $3.id))->getResourceState()){
                                                                    case Resource::ResourceState::rsIDLE:
                                                                      $$.valor = -1;
                                                                      break;
                                                                    case Resource::ResourceState::rsBUSY:
                                                                      $$.valor = -2;
                                                                      break;
                                                                    case Resource::ResourceState::rsFAILED:
                                                                      $$.valor = -4;
                                                                      break;
                                                                    case Resource::ResourceState::rsINACTIVE:
                                                                      $$.valor = -3;
                                                                    default:
                                                                      $$.valor = -5;
                                                                      break;
                                                                  }
                                                                }

           | fIRF       "(" RES ")"                            { $$.valor = ((Resource*)driver.getModel()->getInfrastructure(Util::TypeOf<Resource>(), $3.id))->getResourceState() == Resource::ResourceState::rsFAILED ? 1 : 0; }
           | fTNOW                                             { $$.valor = driver.getModel()->getSimulatedTime();}
           | fTFIN                                             { $$.valor = driver.getModel()->getReplicationLength();}
           ;

//Maybe user defined functions, check if continues on the parser, for now returns the value of expressao
funcaoUser  : "USER" "(" expressao ")"                          { $$.valor = $3.valor; }
            ;

//Probably returns parameters for something, check if continues on the parser, for now does nothing
listaparm   : listaparm "," expressao "," expressao
            | expressao "," expressao
            ;
//If illegal token, verifies if throws exception or set error message
illegal     : ILLEGAL                                           {
                                                                  driver.setResult(-1);
                                                                  if(driver.getThrowsException()){
                                                                    if($1.valor == 0){
                                                                      throw std::string("Literal nao encontrado");
                                                                    }else if($1.valor == 1){
                                                                      throw std::string("Caracter invalido encontrado");
                                                                    }
                                                                  }else{
                                                                    if($1.valor == 0){
                                                                      driver.setErrorMessage(std::string("Literal nao encontrado"));
                                                                    }else if($1.valor == 1){
                                                                      driver.setErrorMessage(std::string("Caracter invalido encontrado"));
                                                                    }
                                                                  }
                                                                }
            ;

%%
void
yy::genesyspp_parser::error (const location_type& l,
                          const std::string& m)
{
  driver.error (l, m);
}
