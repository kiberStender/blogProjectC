all: program
clean:
	rm -f program *.o
# -c ins implicit
# CC is also implicit, you dont need it
CFLAGS := -std=c99 -g -Wall -Wextra -pedantic

program: blogProject.o
	$(CC) $(LDFLAGS) -o $@ $^ $(LIBS)

blogProject.o: blogProject.c
