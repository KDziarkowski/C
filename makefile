
output: main.o polynomial.o
	g++ main.o polynomial.o -o output
main.o: main.cpp
	g++ -c main.cpp
polynomial.o: polynomial.cpp polynomial.h
	g++ -c polynomial.cpp
clean:
	rm *.o output
