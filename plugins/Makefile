PLUGINBUILD=build

PLUGINFILES= \
	${PLUGINBUILD}/libAssign.so \
	${PLUGINBUILD}/libFormula.so

all: ${PLUGINFILES}

${PLUGINBUILD}/libAssign.so:
	mkdir -p ${PLUGINBUILD}
	g++ -fPIC -c Assign.cpp -o ${PLUGINBUILD}/Assign.o
	g++ -shared -Wl,-soname,${PLUGINBUILD}/libAssign.so -o ${PLUGINBUILD}/libAssign.so ${PLUGINBUILD}/Assign.o

${PLUGINBUILD}/libFormula.so:
	mkdir -p ${PLUGINBUILD}
	g++ -fPIC -c Formula.cpp -o ${PLUGINBUILD}/Formula.o
	g++ -shared -Wl,-soname,${PLUGINBUILD}/libFormula.so -o ${PLUGINBUILD}/libFormula.so ${PLUGINBUILD}/Formula.o


clean:
	rm -r build/