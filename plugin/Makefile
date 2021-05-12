CC := g++ -Wall
BUILD := build
SHARED_OBJ_FILES := libassign.so \
	libwrite.so \
	libset.so \
	libenter.so \
	libroute.so \
	libqueue.so \
	librelease.so \
	libseize.so \
	libvariable.so \
	libdecide.so \
	libresource.so \
	libdelay.so \
	libdispose.so \
	libformula.so \
	libcreate.so

.PHONY: all

all: check-build ${SHARED_OBJ_FILES}

check-build:
	if [ ! -d "./build" ]; then mkdir build; fi

libassign.so: Assign.cpp
	${CC} -fPIC -c Assign.cpp -o build/Assign.o
	${CC} -shared -Wl,-soname,libassign.so -o build/libassign.so build/Assign.o

libset.so: Set.cpp
	${CC} -fPIC -c Set.cpp -o build/Set.o
	${CC} -shared -Wl,-soname,libset.so -o build/libset.so build/Set.o

libwrite.so: Write.cpp
	${CC} -fPIC -c Write.cpp -o build/Write.o
	${CC} -shared -Wl,-soname,libwrite.so -o build/libwrite.so build/Write.o

libqueue.so: Queue.cpp
	${CC} -fPIC -c Queue.cpp -o build/Queue.o
	${CC} -shared -Wl,-soname,libqueue.so -o build/libqueue.so build/Queue.o

librelease.so: Release.cpp
	${CC} -fPIC -c Release.cpp -o build/Release.o
	${CC} -shared -Wl,-soname,librelease.so -o build/librelease.so build/Release.o

libseize.so: Seize.cpp
	${CC} -fPIC -c Seize.cpp -o build/Seize.o
	${CC} -shared -Wl,-soname,libseize.so -o build/libseize.so build/Seize.o

libvariable.so: Variable.cpp
	${CC} -fPIC -c Variable.cpp -o build/Variable.o
	${CC} -shared -Wl,-soname,libvariable.so -o build/libvariable.so build/Variable.o

libdecide.so: Decide.cpp
	${CC} -fPIC -c Decide.cpp -o build/Decide.o
	${CC} -shared -Wl,-soname,libdecide.so -o build/libdecide.so build/Decide.o

libresource.so: Resource.cpp
	${CC} -fPIC -c Resource.cpp -o build/Resource.o
	${CC} -shared -Wl,-soname,libresource.so -o build/libresource.so build/Resource.o

libdelay.so: Delay.cpp
	${CC} -fPIC -c Delay.cpp -o build/Delay.o
	${CC} -shared -Wl,-soname,libdelay.so -o build/libdelay.so build/Delay.o

libdispose.so: Dispose.cpp
	${CC} -fPIC -c Dispose.cpp -o build/Dispose.o
	${CC} -shared -Wl,-soname,libdispose.so -o build/libdispose.so build/Dispose.o

libcreate.so: Create.cpp
	${CC} -fPIC -c Create.cpp -o build/Create.o
	${CC} -shared -Wl,-soname,libcreate.so -o build/libcreate.so build/Create.o

libformula.so: Formula.cpp
	${CC} -fPIC -c Formula.cpp -o build/Formula.o
	${CC} -shared -Wl,-soname,libformula.so -o build/libformula.so build/Formula.o

libroute.so: Route.cpp
	${CC} -fPIC -c Route.cpp -o build/Route.o
	${CC} -shared -Wl,-soname,libroute.so -o build/libroute.so build/Route.o

libenter.so: Enter.cpp
	${CC} -fPIC -c Enter.cpp -o build/Enter.o
	${CC} -shared -Wl,-soname,libenter.so -o build/libenter.so build/Enter.o

clean:
	$(RM) -r $(BUILD)
