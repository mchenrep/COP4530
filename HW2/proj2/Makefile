CXX=g++
#CXXFLAGS=-std=c++11 -Wall -pedantic
CXXFLAGS=-Wall -pedantic

test_list.x: List.hpp List.h test_list.cpp
	$(CXX) $(CXXFLAGS) -o $@ test_list.cpp

proj2.x: List.hpp List.h mem_manager.o MyMemoryBlock.o MyMemory.o
	$(CXX) $(CXXFLAGS) -o $@ mem_manager.o MyMemoryBlock.o MyMemory.o

mem_manager.o: List.hpp List.h mem_manager.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ mem_manager.cpp

MyMemory.o: List.hpp List.h MyMemory.h MyMemory.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ MyMemory.cpp

MyMemoryBlock.o: List.hpp List.h MyMemoryBlock.h MyMemoryBlock.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ MyMemoryBlock.cpp

.SUFFIXES: 
	.x

.PHONY: 
	clean

clean:
	rm -f *.o *.x core.*

%.x : %.c
	$(CC) -o $@ $<

%.x : %.cpp
	$(CXX) -o $@ $<
