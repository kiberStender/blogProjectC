all: program 
clean:
	rm -rf program
	rm -rf $(LIB)/*.a
	rm -rf $(OBJ)/*.o
.PHONY: all clean

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
