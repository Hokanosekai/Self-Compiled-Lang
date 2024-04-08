CC = gcc
NASM = nasm
LD = ld

CFLAGS = -Wall -Wextra -Werror -pedantic -std=c99 -g 
CLIBS = -I./include

BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

OUT_NAME = scl

all: $(OUT_NAME)

prepare:
	mkdir -p $(BIN_DIR)
	mkdir -p $(OBJ_DIR)

scl: $(OBJ)
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$(OUT_NAME) $^ $(CLIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(CLIBS)

clean:
	$(RM) $(OBJ_DIR)/*.o
	$(RM) $(BIN_DIR)/$(OUT_NAME)

.PHONY: all clean prepare scl
