all: comp run

comp: main.cpp
	g++ main.cpp -o main
	
run: main
	./main
	
