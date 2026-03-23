CC=cc
CFLAGS=-g -O0 -Wall -Wextra -Wpedantic -Werror
INCLUDES=-Iinclude
SRC=src/main.c src/cli.c src/task.c src/store.c
BIN=task

all:
	$(CC) $(CFLAGS) $(INCLUDES) $(SRC) -o $(BIN)

clean:
	rm -f $(BIN)
