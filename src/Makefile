CC=gcc
CFLAGS=-c -Wall -march=nocona -O4 -pipe
DIRECTFBLIBS=$(shell dfb++-config --libs)
DIRECTFBCFLAGS=$(shell directfb-config  --cflags)
LDFLAGS=-lm -lstdc++ -ldfb++
SOURCES=CBBuffer.cpp CBMatrix.cpp CBTriangle.cpp CBView.cpp CBMoff.cpp CBScreenSaver.cpp CBVertex.cpp CBBitmap.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=CBScreenSaver

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) $(DIRECTFBLIBS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $(DIRECTFBCFLAGS) $< -o $@

clean:
	rm -rf *o CBScreenSaver
