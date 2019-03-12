lab1: all

all: main.o mystring.o
	gcc main.o mystring.o -o lab1

main.o: main.c
	gcc -c main.c

mystring.o: mystring.c
	gcc -c mystring.c

clean:
	rm -rf *.o lab1
