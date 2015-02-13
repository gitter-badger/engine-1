CC=g++
CFLAGS=-c -Wall

all: matchingEngine

matchingEngine: matchingEngine.o orderBook.o heap.o
	$(CC) matchingEngine.o orderBook.o heap.o -o matchingEngine

main.o: matchingEngine.cpp
	$(CC) $(CFLAGS) matchingEngine.cpp

orderBook.o: orderBook.cpp
	$(CC) $(CFLAGS) orderBook.cpp

heap.o: heap.cpp
	$(CC) $(CFLAGS) heap.cpp

clean:
	rm *o matchingEngine