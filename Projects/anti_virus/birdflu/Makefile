flags=-O2 -Wall -std=c23
# No external libraries needed by default.
# You can override from the command line, e.g.:
# make ldflags="-lfoo"
ldflags?=

.PHONY: all clean

all: clean birdflu

birdflu: birdflu.o
	cc $(flags) $^ -o $@ $(ldflags)

birdflu.o: birdflu.c birdflu.h
	cc $(flags) -c $<

clean:
	rm -f *.o birdflu
