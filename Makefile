all: main.o PermutedInteger.o
	g++ -o ./bin/main main.o PermutedInteger.o
	make clean

main.o:
	g++ -c ./src/main.cpp

Allele.o:
	g++ -c ./src/allele/Allele.cpp

PermutedInteger.o:
	g++ -c ./src/allele/PermutedInteger.cpp

clean:
	rm -f *.o
