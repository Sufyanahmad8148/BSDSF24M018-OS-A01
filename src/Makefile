CC = gcc
CFLAGS = -I../include
LIB = ../lib/libmyutils.so
TARGET = ../bin/client_dynamic

all: $(TARGET)

$(TARGET): ../obj/main.o $(LIB)
	gcc ../obj/main.o -L../lib -lmyutils -o $(TARGET)

$(LIB): ../obj/mystrfunctions.o ../obj/myfilefunctions.o
	gcc --shared ../obj/mystrfunctions.o ../obj/myfilefunctions.o -o $(LIB)

../obj/main.o: main.c
	gcc $(CFLAGS) -c main.c -o ../obj/main.o

../obj/mystrfunctions.o: mystrfunctions.c
	gcc -fPIC $(CFLAGS) -c mystrfunctions.c -o ../obj/mystrfunctions.o

../obj/myfilefunctions.o: myfilefunctions.c
	gcc -fPIC $(CFLAGS) -c myfilefunctions.c -o ../obj/myfilefunctions.o

clean:
	rm -f ../obj/*.o $(LIB) $(TARGET)
