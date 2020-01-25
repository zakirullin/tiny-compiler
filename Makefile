flags := -std=c99 -O3 -Wall

src := $(wildcard src/*.c)
obj := $(src:.c=.o)
out := compiler

compiler: $(obj)
	gcc $(flags) $(obj) -o $(out)

%.d: %.c
	gcc -MM -MT '$(@:.d=.o)' $< > $@

ifneq ($(MAKECMDGOALS),clean)
-include $(src:.c=.d)
endif

%.o: %.c
	gcc $(flags) -c $< -o $@

clean:
	rm -rf $(out) src/*.o src/*.d