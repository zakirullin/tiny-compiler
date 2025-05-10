CC = gcc
CFLAGS = -Wall

HEADERS = *.h
SRCS = main.c

compiler: $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) -o compiler $(SRCS)

clean:
	rm -f compiler