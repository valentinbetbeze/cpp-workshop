CXXFLAGS=-Wall -Wextra -pedantic -std=c++14

all : clean engine.o inheritance.o
	g++ ${CXXFLAGS} engine.o inheritance.o -o inheritance

engine.o :
	g++ ${CXXFLAGS} -c engine.cc -o engine.o

inheritance.o :
	g++ ${CXXFLAGS} -c inheritance.cc -o inheritance.o

clean :
	-rm engine.o inheritance.o inheritance
