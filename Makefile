CC=gcc
FILENAME=letlang

INCLUDE_F = ./Include
SOURCE_F = ./Source

all:
	$(CC) -o $(FILENAME) $(INCLUDE_F)/*.h $(SOURCE_F)/*.c

clean:
	rm -rf $(FILENAME)*
