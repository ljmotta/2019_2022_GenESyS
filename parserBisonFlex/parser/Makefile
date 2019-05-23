all: parser lexer

parser:
	bison --graph=bisongraph.dot --xml=bisonreport.xml --defines=../GenesysParser.h -o ../GenesysParser.cpp bisonparser.yy

lexer:
	flex -o ../Genesys++-scanner.cpp lexerparser.ll
