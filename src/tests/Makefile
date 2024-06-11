CC=g++
CFLAGS=-lgtest -lstdc++
LIBS=-lcheck -lm -lsubunit

BUILD_DIR=./build
SRC=$(wildcard *.cpp)
OBJ=$(addprefix $(BUILD_DIR)/,$(SRC:%.cpp=%.o))

TARGET=s21_test_matrix_oop.exe

S21_LIB=../s21_matrix_oop.a

ifeq ($(wildcard $(BUILD_DIR)), )
  $(shell mkdir $(BUILD_DIR))
endif

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(S21_LIB) -o $(BUILD_DIR)/$@ $(LIBS)

$(BUILD_DIR)/%.o: %.cpp    
	$(CC) $(CFLAGS) -c $< -o $@
	
test: $(TARGET)
	./$(BUILD_DIR)/$(TARGET)

valgrind: $(TARGET)
	valgrind --tool=memcheck --leak-check=yes -s ./$(BUILD_DIR)/$(TARGET)


gcov: gcov_flags test

gcov_flags:
	$(eval CFLAGS += -g3 -fprofile-arcs -ftest-coverage --coverage)

clang_check:
	clang-format -style=Google -n *.cpp *.h

clang_format: clang_check
	clang-format -style=Google -i *.cpp *.h

clean:
	rm -rf $(BUILD_DIR)/*