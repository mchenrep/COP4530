CXX = g++
CXXFLAGS = -Wall -pedantic

proj5.x: proj5.o passserver.o
	$(CXX) $(CXXFLAGS) -o $@ proj5.o passserver.o -lcrypt

proj5.o: proj5.cpp passserver.h hashtable.h
	$(CXX) $(CXXFLAGS) -c -o $@ proj5.cpp

passserver.o: passserver.cpp passserver.h hashtable.h hashtable.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ passserver.cpp

clean:
	rm -f *.o *.x core.*

.SUFFIXES:
	.x

.PHONY: 
	clean
