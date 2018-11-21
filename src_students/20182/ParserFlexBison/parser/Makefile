all: parser lexer

parser:
	bison --defines=../Genesys++-parser.h -o ../Genesys++-parser.cpp Genesys++-parser.yy

lexer:
	flex -o ../Genesys++-scanner.cpp Genesys++-scanner.ll
