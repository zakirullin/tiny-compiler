CC = gcc
CFLAGS = -Wall -g

compiler: main.c
	$(CC) $(CFLAGS) -o compiler main.c

clean:
	rm -f compiler