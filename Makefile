APP=test_xml
CXX=g++
CC=gcc
CFLAGS= -Wall -c
CXXFLAGS= -Wall -c

CSOURCES= main.c
CXXSOURCES= pugixml.cpp config.cpp



all: $(APP)

$(APP): main.o pugixml.o config.o
	$(CXX) -Wall pugixml.o config.o main.o -o $(APP)

pugixml.o: pugixml.cpp
	$(CXX) $(CXXFLAGS) pugixml.cpp 

config.o: config.cpp
	$(CXX) $(CXXFLAGS) config.cpp 

main.o: main.c
	$(CC) $(CFLAGS) main.c 

dep:
	echo 'Do nothing'

clean:
	rm -f $(APP) *.o

