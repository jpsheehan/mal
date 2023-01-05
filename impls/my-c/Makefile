CC=gcc
CFLAGS=-Werror -Wall -g
LFLAGS=-lreadline

clean:
	rm -f *.o
	rm -f mal

all: step0_repl

step0_repl: main.c
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

.PHONY: clean all step0_repl


