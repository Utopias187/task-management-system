CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c11 -Iinclude
TARGET = task
SRC = src/main.c src/cli.c src/store.c src/task.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	del /Q $(TARGET).exe 2>nul || exit 0