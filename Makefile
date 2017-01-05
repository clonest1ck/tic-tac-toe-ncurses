# Makefile
CFLAGS=-lncurses
COMP=gcc

all: 
	$(COMP)  -o tic-tac-toe tic-tac-toe.cpp $(CFLAGS)
