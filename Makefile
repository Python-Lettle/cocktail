# Author: Lettle

# 变量
CC = gcc
FILENAME = cocktail
CFlags = -g -Wall -Wno-strict-aliasing -fPIC

s  = Source
t  = target

COT_Kernel = $(t)/cot_debug.o $(t)/cot_lexer.o $(t)/cot_stack.o $(t)/cot_util.o $(t)/cot_parser.o $(t)/main.o

.PHONY: nop all clean run debug

nop:
	@echo "all      编译cocktail"
	@echo "debug    调试test.cot"
	@echo "clean    清理obj文件"

all: $(COT_Kernel)
	$(CC) -o $(FILENAME) $(COT_Kernel)

clean:
	rm -rf $(t)/*
	rm -rf $(FILENAME)

run:
	./$(FILENAME) src.cot

debug:
	./$(FILENAME) test.cot --token --varlist

$(t)/cot_debug.o: $(s)/cot_debug.c
	$(CC) $(CFlags) -c -o $@ $<

$(t)/cot_lexer.o: $(s)/cot_lexer.c
	$(CC) $(CFlags) -c -o $@ $<

$(t)/cot_stack.o: $(s)/cot_stack.c
	$(CC) $(CFlags) -c -o $@ $<

$(t)/cot_util.o: $(s)/cot_util.c
	$(CC) $(CFlags) -c -o $@ $<

$(t)/cot_parser.o: $(s)/cot_parser.c
	$(CC) $(CFlags) -c -o $@ $<

$(t)/main.o: $(s)/main.c
	$(CC) $(CFlags) -c -o $@ $<


