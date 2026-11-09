CFLAGS = -Wall -Wextra -pedantic -std=c99
CC = gcc

test : main.o dvector_ptr.o
	$(CC) $(CFLAGS) main.o dvector_ptr.o -o test

dvector_ptr.o : dvector_ptr.c dvector.h
	$(CC) $(CFLAGS) -c dvector_ptr.c -o dvector_ptr.o

main.o : main.c dvector.h
	$(CC) $(CFLAGS) -c main.c -o main.o
