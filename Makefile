PREFIX = /usr/local/bin
CC = g++
CFLAGS = -Wall -Wno-trigraphs -lncurses
SOURCES = main.cpp GameWorld.cpp Vehicle.cpp
OBJECTS = main.o GameWorld.o Vehicle.o
EXECUTABLE = aroad

.PHONY: all clean

all: $(EXECUTABLE)

clean:
	@rm -rf $(EXECUTABLE) $(OBJECTS)

$(OBJECTS):
	@$(CC) -c $(CFLAGS) $(SOURCES)

$(EXECUTABLE): $(OBJECTS)
	@$(CC) $(CFLAGS) -o $(EXECUTABLE) $(OBJECTS)
