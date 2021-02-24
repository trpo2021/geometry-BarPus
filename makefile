CC=g++
CFLAGS=-Wall -Werror
all: main
main: geometry.cpp
	$(CC) $(CFLAGS) geometry.cpp
