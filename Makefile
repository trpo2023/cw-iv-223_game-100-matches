CC = g++
CXXFLAGS = -std=c++11 -I../lib/thirdparty 

OBJ_DIR = obj
BIN_DIR = bin

APP_SOURCES = $(wildcard src/app/*.cpp)
APP_OBJECTS = $(patsubst src/app/%.cpp, $(OBJ_DIR)/%.o, $(APP_SOURCES))

LIB_SOURCES = $(wildcard src/app_lib/*.cpp)
LIB_OBJECTS = $(patsubst src/app_lib/%.cpp, $(OBJ_DIR)/%.o, $(LIB_SOURCES))

TESTS_SOURCES = $(wildcard tests/*.cpp)
TESTS_OBJECTS = $(patsubst tests/%.cpp, $(OBJ_DIR)/%.o, $(TESTS_SOURCES))

all: $(BIN_DIR)/game

$(BIN_DIR)/game: $(APP_OBJECTS) $(LIB_OBJECTS)
	mkdir -p $(BIN_DIR)
	$(CC) $(APP_OBJECTS) $(LIB_OBJECTS) -o $(BIN_DIR)/game
	ar rcs lib/mylib.a $(OBJ_DIR)/lib.o 

$(OBJ_DIR)/%.o: src/app/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CC) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: src/app_lib/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CC) $(CXXFLAGS) -c $< -o $@

tests: $(TESTS_OBJECTS) $(LIB_OBJECTS)
	mkdir -p $(BIN_DIR)
	$(CC) $(TESTS_OBJECTS) $(LIB_OBJECTS) -o $(BIN_DIR)/tests 

$(OBJ_DIR)/%.o: tests/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CC) $(CXXFLAGS) -c $< -o $@

run: $(BIN_DIR)/game
	./$(BIN_DIR)/game

run_tests: $(BIN_DIR)/tests
	./$(BIN_DIR)/tests

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

