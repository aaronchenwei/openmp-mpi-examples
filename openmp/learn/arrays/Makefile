CC=gcc

RM=rm

CFLAGS=-fopenmp -Wall --std=c11 -O3

LDFLAGS=-lm

SOURCES=$(wildcard *.c)

OBJECTS=$(SOURCES:.c=.o)

EXECS=$(SOURCES:%.c=%)

.PHONY: all
all: $(OBJECTS) $(EXECS)

.c.o:
	$(CC) -c $(CFLAGS) $< -o $@

.o:
	$(CC) $(LDFLAGS) $(CFLAGS) $^ -o $@

.PHONY: clean
clean:
	-@ $(RM) -f *.o
	-@ $(RM) -f $(EXECS)
