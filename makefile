CC      = g++
CFLAGS  = -Wall -O3 -std=c++0x
RM      = rm -f

default: all

all: paralelotopo

paralelotopo: main.cpp
	$(CC) main.cpp -o main.o $(CFLAGS)
