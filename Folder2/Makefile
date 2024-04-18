CC = g++
CFLAGS = -std=c++17 -Wall
OBJ_DIR = obj
SRC_DIR = src

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))
TARGET = my_program

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@


.PHONY: clean
clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)