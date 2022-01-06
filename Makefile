all: client serveur

client: client.o
	gcc -Wall -Wextra -o client client.o
	rm client.o

clean:
	rm -f fctReseau.o fctJdDame.o
