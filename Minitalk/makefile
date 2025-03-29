CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJ = minitalk_utils.o
TARGETS = client server

all: $(TARGETS)

client: client.o $(OBJ)
	$(CC) $(CFLAGS) -o client client.o $(OBJ)

server: server.o $(OBJ)
	$(CC) $(CFLAGS) -o server server.o $(OBJ)

minitalk_utils.o: minitalk_utils.c minitalk.h
	$(CC) $(CFLAGS) -c minitalk_utils.c

client.o: client.c minitalk.h
	$(CC) $(CFLAGS) -c client.c

server.o: server.c minitalk.h
	$(CC) $(CFLAGS) -c server.c

clean:
	rm -f *.o

fclean: clean
	rm -f $(TARGETS)

re: fclean all
