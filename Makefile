all: run

run: main.o
	g++ main.o -o run

main.o: 
	g++ -c main.cpp

