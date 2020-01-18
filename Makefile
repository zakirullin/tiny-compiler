flags := -std=c99 -O3 -Wall

src := $(wildcard src/*.c)
obj := $(src:.c=.o)
out := compiler

compiler: $(obj)
	gcc $(flags) $(obj) -o $(out)

%.o: %.c %.h 
	gcc $(flags) -c $< -o $@

clean:
	rm -rf $(out) *.o