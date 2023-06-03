APP_NAME = game
LIB_NAME = lib


CFLAGS = -Wall
CC = g++

BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src

APP_PATH = $(BIN_DIR)/$(APP_NAME)

SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))


$(APP_PATH): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CC) -c $< -o $@

clean:
	$(RM) $(APP_PATH) $(OBJ_DIR)/*.o