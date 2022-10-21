CC := gcc -c -Wall -std=c99 -pedantic
output: main.o
	gcc main.o -o output
main.o: main.c
	$(CC)  main.c
clean:
	rm *.o
