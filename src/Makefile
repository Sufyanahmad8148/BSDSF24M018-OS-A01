CC = gcc
CFLAGS = -I../include
LIB = ../lib/libmyutils.a
TARGET = ../bin/client_static

all: $(TARGET)

$(TARGET): ../obj/main.o $(LIB)
	gcc ../obj/main.o $(LIB) -o $(TARGET)

$(LIB): ../obj/mystrfunctions.o ../obj/myfilefunctions.o
	ar rcs $(LIB) ../obj/mystrfunctions.o ../obj/myfilefunctions.o

../obj/main.o: main.c
	gcc $(CFLAGS) -c main.c -o ../obj/main.o

../obj/mystrfunctions.o: mystrfunctions.c
	gcc $(CFLAGS) -c mystrfunctions.c -o ../obj/mystrfunctions.o

../obj/myfilefunctions.o: myfilefunctions.c
	gcc $(CFLAGS) -c myfilefunctions.c -o ../obj/myfilefunctions.o

clean:
	rm -f ../obj/*.o $(LIB) $(TARGET)


