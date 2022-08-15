# Author: Lettle, Robot_Steve

CC = gcc
name = cocktail

src = ./src/
INCLUDE = -I ./Include/

cocktail: main.o cot_debug.o cot_util.o cot_lexer.o cot_parser.o
	$(CC) -o cocktail $^ $(INCLUDE)

main.o: 
	$(CC) -c $(src)main.c $(INCLUDE)

cot_debug.o: 
	$(CC) -c $(src)cot_debug.c $(INCLUDE)

cot_util.o:
	$(CC) -c $(src)cot_util.c $(INCLUDE)

cot_lexer.o: 
	$(CC) -c $(src)cot_lexer.c $(INCLUDE)

cot_parser.o: 
	$(CC) -c $(src)cot_parser.c $(INCLUDE)

.PHONY: clean

clean:
	-rm -rf *.o
	-rm -rf *.exe

