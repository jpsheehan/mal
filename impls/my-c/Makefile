CC=gcc
CFLAGS=-Werror -Wall -g
LFLAGS=-lreadline

all: step1_read_print

clean:
	rm -f *.o
	rm -f step0_repl step1_read_print

step0_repl: step0_repl.c
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

step1_read_print: step1_read_print.c reader.c list.c
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

.PHONY: clean all step0_repl


