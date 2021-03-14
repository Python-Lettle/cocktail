# Author: Lettle


# 变量
CC = g++
FILENAME = cocktail

s = /Source
s_main = $(s)/main

all:
	$(CC) -o $(FILENAME) .$(s_main)/*.cpp


