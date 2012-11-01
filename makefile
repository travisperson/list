CC=clang++
SRC=src
TESTS=tests
BINS=bin

all: Run

Run: Run.o
	$(CC) Test.o Run.o -o $(BINS)/run

Test.o: $(TESTS)/Test.h
	$(CC) -c $(TESTS)/Test.cpp

Run.o: Test.o $(TESTS)/testList.hpp
	$(CC) -c $(TESTS)/Run.cpp