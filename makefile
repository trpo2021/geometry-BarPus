CC=g++
CFLAGS=-Wall -Wextra -Werror 
main: isGoodCircle.o CircleRadius.o PerimeterArea.o main.o
	$(CC) $(CFLAGS) -o $@ $^
isGoodCircle.o: isGoodCircle.cpp
	$(CC) -c $(CFLAGS) -o $@ $<
CircleRadius.o: CircleRadius.cpp
	$(CC) -c $(CFLAGS) -o $@ $<
PerimeterArea.o: PerimeterArea.cpp
	$(CC) -c $(CFLAGS) -o $@ $<
main.o: main.cpp
	$(CC) -c $(CFLAGS) -o $@ $<
