# Author: Lettle

# 变量
CC = gcc
FILENAME = cocktail
CFlags = -g -Wall -Wno-strict-aliasing -std=gnu11 -fPIC

s  = Source
t  = target

COT_Kernel = $(t)/cot_debug.o $(t)/cot_lexer.o $(t)/cot_stack.o $(t)/cot_util.o $(t)/main.o

.PHONY: nop all clean run

nop:
	@echo "all      编译cocktail"
	@echo "clean    清理obj文件"

all: $(COT_Kernel)
	$(CC) -o $(FILENAME) $(COT_Kernel)

clean:
	rm -rf $(t)/*
	rm -rf $(FILENAME)

run:
	./cocktail src.cot

$(t)/cot_debug.o: $(s)/cot_debug.c
	$(CC) $(CFlags) -c -o $@ $<

$(t)/cot_lexer.o: $(s)/cot_lexer.c
	$(CC) $(CFlags) -c -o $@ $<

$(t)/cot_stack.o: $(s)/cot_stack.c
	$(CC) $(CFlags) -c -o $@ $<

$(t)/cot_util.o: $(s)/cot_util.c
	$(CC) $(CFlags) -c -o $@ $<

$(t)/main.o: $(s)/main.c
	$(CC) $(CFlags) -c -o $@ $<


