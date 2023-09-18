CXX = g++
CXXFLAGS = -std=c++11 -Wall

SRC_APP_DIR = src/app
SRC_APP_LIB_DIR = src/app_lib
TESTS_DIR = tests
BIN_DIR = bin

SRC_APP_FILES = $(wildcard $(SRC_APP_DIR)/*.cpp)
SRC_APP_LIB_FILES = $(wildcard $(SRC_APP_LIB_DIR)/*.cpp)
TESTS_FILES = $(wildcard $(TESTS_DIR)/*.cpp)

APP_TARGET = $(BIN_DIR)/main
TESTS_TARGET = $(BIN_DIR)/tests

all: create_bin_dir $(APP_TARGET) $(TESTS_TARGET)

create_bin_dir:
	mkdir -p $(BIN_DIR)

$(APP_TARGET): $(SRC_APP_FILES) $(SRC_APP_LIB_FILES)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(TESTS_TARGET): $(SRC_APP_LIB_FILES) $(TESTS_FILES)
	$(CXX) $(CXXFLAGS) $^ -o $@ 

run_app: $(APP_TARGET)
	./$(APP_TARGET)

run_tests: $(TESTS_TARGET)
	./$(TESTS_TARGET)

clean:
	rm -rf $(BIN_DIR)
