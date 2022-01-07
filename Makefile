all: Client Serveur

Client: Client.c fonctions.o
	gcc -o Client Client.c fonctions.o

Serveur: Serveur.c fonctions.o
	gcc -o Serveur Serveur.c fonctions.o -lpthread

fonctions.o : fonctions.c fonctions.h
	gcc -c fonctions.c
clean:
	rm -f *.o
