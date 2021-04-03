CC := g++ -Wall
BUILD := build
SHARED_OBJ_FILES := libassign.so \
	libwrite.so \
	libset.so \
	libqueue.so \
	librelease.so \
	libseize.so \
	libvariable.so \
	libdecide.so \
	libresource.so \
	libdelay.so \
	libdispose.so \
	libcreate.so

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

libqueue.so: Queue.cpp
	${CC} -fPIC -c Queue.cpp -o Queue.o
	${CC} -shared -Wl,-soname,libqueue.so -o libqueue.so Queue.o

librelease.so: Release.cpp
	${CC} -fPIC -c Release.cpp -o Release.o
	${CC} -shared -Wl,-soname,librelease.so -o librelease.so Release.o

libseize.so: Seize.cpp
	${CC} -fPIC -c Seize.cpp -o Seize.o
	${CC} -shared -Wl,-soname,libseize.so -o libseize.so Seize.o

libvariable.so: Variable.cpp
	${CC} -fPIC -c Variable.cpp -o Variable.o
	${CC} -shared -Wl,-soname,libvariable.so -o libvariable.so Variable.o

libdecide.so: Decide.cpp
	${CC} -fPIC -c Decide.cpp -o Decide.o
	${CC} -shared -Wl,-soname,libdecide.so -o libdecide.so Decide.o

libresource.so: Resource.cpp
	${CC} -fPIC -c Resource.cpp -o Resource.o
	${CC} -shared -Wl,-soname,libresource.so -o libresource.so Resource.o

libdelay.so: Delay.cpp
	${CC} -fPIC -c Delay.cpp -o Delay.o
	${CC} -shared -Wl,-soname,libdelay.so -o libdelay.so Delay.o

libdispose.so: Dispose.cpp
	${CC} -fPIC -c Dispose.cpp -o Dispose.o
	${CC} -shared -Wl,-soname,libdispose.so -o libdispose.so Dispose.o

libcreate.so: Create.cpp
	${CC} -fPIC -c Create.cpp -o Create.o
	${CC} -shared -Wl,-soname,libcreate.so -o libcreate.so Create.o

clean:
	$(RM) -r $(BUILD)

