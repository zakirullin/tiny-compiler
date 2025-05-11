CC = gcc
CFLAGS = -Wall

HEADERS = src/*.h
SRCS = src/main.c

compiler: $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) -o compiler $(SRCS)

clean:
	rm -f compiler
