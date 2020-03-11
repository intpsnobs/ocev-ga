all:
	g++ ./src/main.cpp -std=c++17 -o ./bin/main -g
clear:
	rm -rf ./bin/*
