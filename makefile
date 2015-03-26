all: program 
clean:
	rm -f program
	rm -f $(LIB)/*.a
	rm -f $(OBJ)/*.o
.PHONY: all clean

# -c ins implicit
CC=gcc
SRC=./src
HEADER=./header
LIB=./lib
OBJ=./obj
CFLAGS := -std=c99 -g -Wall -Wextra -pedantic
LIBFLAGS = -l cadastro

program: cadastro.a
	$(CC) main.c $(CFLAGS) -L $(LIB) $(LIBFLAGS) -o program

cadastro.a:
	$(CC) -c $(CFLAGS) $(SRC)/*.c
	mv *.o $(OBJ)
	ar -cru $(LIB)/libcadastro.a $(OBJ)/*.o

#functions.o: functions.c
#clientefn.o: clientefn.c functions.h
#funcionariofn.o: funcionariofn.c functions.h
