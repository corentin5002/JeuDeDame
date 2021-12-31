all:	main

main :  main.o
	gcc -Wall -Wextra -o main main.o

main.o : main.c main.h
	gcc -c main.c
