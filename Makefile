all:
	g++ ./src/main.cpp -std=c++11 -o ./bin/main -g
clear:
	rm -rf ./bin/*
