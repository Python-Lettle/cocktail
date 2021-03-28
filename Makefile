# Author: Lettle


# 变量
CC = g++
FILENAME = cocktail
CFLAGS=-Wall -std=gnu99

s = /Source
s_main = $(s)/main

i = /Include
HEADS = util.h global.h

OBJ_SRC = /Object

SRCS = $(s_main)/main.cpp \
       $(s_main)/util.cpp \
       $(s_main)/token.cpp
INC = -I .$(i)
OBJS = $(SRCS:.c=.o)

.PHONY: all clean checkdir

all:
	$(CC) -o $(FILENAME) .$(s_main)/*.cpp $(INC)

checkdir:
	mkdir -p $(OBJ_SRC) $(s) $(s_main) $(i)


$(FILENAME): $(OBJS)
	#	@echo TARGET:$@
	#	@echo OBJECTS:$^
	$(CC) -o $@ $^
%.o: %.c
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

#cocktail.o: $(s_main)/main.cpp
#	$(CC) -c $(s_main)/main.cpp $(HEADS) -o cocktail.o
#util.o: util.cpp
#	$(CC) -o $(s_main)/util.cpp $(HEADS) -o util.o

clean:
	rm $(FILENAME) -rf


