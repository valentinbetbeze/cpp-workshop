CXX=-Wall -Wextra -Werror -pedantic -std=c++14

all : bst.o main.o
	g++ bst.o main.o -o main

bst.o : clean
	g++ ${CXX} -c bst.cc -o bst.o

main.o :
	g++ ${CXX} -c main.cc -o main.o

clean :
	-rm bst.o main.o main
