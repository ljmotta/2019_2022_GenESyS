all: parser lexer

parser:
#	bison --update --graph=bisongraph.dot --locations --verbose --xml=bisonreport.xml --defines=../GenesysParser.h -o ../GenesysParser.cpp bisonparser.yy
	bison --locations --verbose --defines=../GenesysParser.h -o ../GenesysParser.cpp bisonparser.yy

lexer:
	flex --full -o ../Genesys++-scanner.cpp lexerparser.ll
