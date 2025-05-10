CC = gcc
CFLAGS = -Wall

compiler: main.c
	$(CC) $(CFLAGS) -o compiler main.c

clean:
	rm -f compiler