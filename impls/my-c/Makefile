CC=gcc
CFLAGS=-Werror -Wall -g
LFLAGS=-lreadline

all: mal

clean:
	rm -f *.o
	rm -f mal
	rm -f step0_repl

mal: main.c
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

step0_repl: main.c
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

.PHONY: clean all step0_repl


