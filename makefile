CC=G++
SRC=src
TESTS=tests


all: List.o Test.o

Test.o: $(TESTS)/Test.h
	$(CC) -c $(TESTS)/Test.cpp

Runs.o: Test.o $(TESTS)/testList.hpp
	$(CC) -c $(TESTS)/Run.cpp