CC := g++ -Wall
BUILD := build
SHARED_OBJ_FILES := libassign.so libwrite.so libset.so
.PHONY: all

all: ${SHARED_OBJ_FILES}

libassign.so: Assign.cpp
	${CC} -fPIC -c Assign.cpp -o Assign.o
	${CC} -shared -Wl,-soname,libassign.so -o libassign.so Assign.o

libset.so: Set.cpp
	${CC} -fPIC -c Set.cpp -o Set.o
	${CC} -shared -Wl,-soname,libset.so -o libset.so Set.o

libwrite.so: Write.cpp
	${CC} -fPIC -c Write.cpp -o Write.o
	${CC} -shared -Wl,-soname,libwrite.so -o libwrite.so Write.o

clean:
	$(RM) -r $(BUILD)

