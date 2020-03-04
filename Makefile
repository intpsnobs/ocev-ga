all:
	g++ ./src/main.cpp -std=c++11 -o ./bin/main
clear:
	rm -rf ./bin/*
