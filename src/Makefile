CC = gcc
CFLAGS = -Wall -I../include
TARGET = ../bin/client
SOURCES = main.c mystrfunctions.c myfilefunctions.c

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)

