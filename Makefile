# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -g

# Project structure
SRC_DIR = src
MOD_DIR = $(SRC_DIR)/modules
BIN_DIR = bin
OBJ_DIR = build

# Files
SRCS = $(SRC_DIR)/server.c \
       $(MOD_DIR)/FileHelper.c \
       $(MOD_DIR)/HTTPHelper.c \
       $(MOD_DIR)/utils.c

OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

TARGET = $(BIN_DIR)/httpserver

# Default rule
all: $(TARGET)

# Linking
$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

# Compiling
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Ensure directories exist
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)/$(MOD_DIR) $(OBJ_DIR)/$(SRC_DIR)

# Cleanup
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Run server
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
