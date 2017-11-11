CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic -O2 -g

all: ooc

ooc: main.o buffer.o class.o string.o
	${CC} -o $@ $^ ${LIBS}

main.o: main.c

buffer.o: buffer.c

class.o: class.c

string.o: string.c

.PHONY: clean
clean:
	@rm -f *.o
