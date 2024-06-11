CC=g++
CFLAGS=-std=c++17 #-Wall -Werror -Wextra -pedantic
TEST_DIR=./tests
BUILD_DIR=./build
REPORT_DIR=./report

ifeq ($(wildcard $(BUILD_DIR)), )
  $(shell mkdir $(BUILD_DIR))
endif
ifeq ($(wildcard $(REPORT_DIR)), )
  $(shell mkdir $(REPORT_DIR))
endif

SRC=$(wildcard *.cpp)
OBJ=$(addprefix $(BUILD_DIR)/,$(SRC:%.cpp=%.o))
TARGET=s21_matrix_oop.a

all: $(TARGET)

$(TARGET): $(OBJ)
	ar rcs $@ $(OBJ)

$(BUILD_DIR)/%.o: %.cpp    
	$(CC) $(CFLAGS) -c $< -o $@

test: clean $(TARGET)
	cd $(TEST_DIR) && make test

valgrind: clean $(TARGET)
	cd $(TEST_DIR) && make valgrind

gcov_report: clean gcov_flags $(TARGET)	
	cd $(TEST_DIR) && make gcov
	lcov -o $(REPORT_DIR)/s21_matrix_oop.info -c -d $(BUILD_DIR) -d $(TEST_DIR)/$(BUILD_DIR) --ignore-errors mismatch
	lcov -r $(REPORT_DIR)/s21_matrix_oop.info '/usr/include/*' -o $(REPORT_DIR)/filtered_coverage.info
	genhtml $(REPORT_DIR)/filtered_coverage.info -o report 
	xdg-open $(REPORT_DIR)/index.html

gcov_flags: 
	$(eval CFLAGS += -fprofile-arcs -ftest-coverage)

clean_obj:
	rm -rf $(BUILD_DIR)/*
	rm -rf $(TARGET)

clean_gcov:
	rm -rf $(REPORT_DIR)/*

clean: clean_obj clean_gcov
	cd $(TEST_DIR) && make clean

clang_check:
	clang-format -style=Google -n *.cpp *.h
	cd $(TEST_DIR) && make clang_check

clang_format: clang_check
	clang-format -style=Google -i *.cpp *.h
	cd $(TEST_DIR) && make clang_format

rebuild: clean all