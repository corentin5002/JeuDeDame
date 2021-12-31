all:	main

main :  main.o
	gcc -Wall -Wextra -o main main.o

gridControl.o : main.c main.h
	gcc -c main.c
