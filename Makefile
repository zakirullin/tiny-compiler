flags := -std=c99 -O3 -Wall

src := $(wildcard src/*.c)
obj := $(src:.c=.o)
out := compiler

compiler: $(obj)
	cc $(flags) $(obj) -o $(out)

%.d: %.c
	cc -MM -MT '$(@:.d=.o)' $< > $@

ifneq ($(MAKECMDGOALS),clean)
-include $(src:.c=.d)
endif

%.o: %.c
	cc $(flags) -c $< -o $@

clean:
	rm -rf $(out) src/*.o src/*.d
