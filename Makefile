# Makefile
CFLAGS=-lncurses

all:	tic-tac-toe : cc  -o tic-tac-toe tic-tac-toe.cpp $(CFLAGS)
