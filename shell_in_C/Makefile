CC = gcc
CFLAGS = -Wall -Wextra -g
INCLUDES = -Iinclude

SRC = src/main.c src/input.c src/parser.c src/executor.c src/builtins.c
OUT = mysh

all:
	$(CC) $(CFLAGS) $(INCLUDES) $(SRC) -o $(OUT)

clean:
	rm -f mysh
