all:	main client

client: client.o
	gcc -Wall -Wextra -o client client.o
	rm client.o
client.o: main.h main.c
	gcc -c client.c

main :  main.o
	gcc -Wall -Wextra -o main main.o
	rm main.o

main.o : main.c main.h
	gcc -c main.c
