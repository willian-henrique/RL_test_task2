CC=gcc
CXX=g++
CFLAGS=-Wall -Wextra -std=c99 -g
CXXFLAGS=-Wall -Wextra -std=c++17 -g 

#print lst files -Wa,-adhln
# Define lists of source files
BASE_SOURCE := src/RocketMath.cpp
APP_SOURCES := main.cpp

TEST_SOURCES_CPP := test/test_math_class.cpp
TEST_SOURCES_C := test/unity_framework/unity.c

# Define targets
all: 
	$(MAKE) app
	$(MAKE) test

app: $(BASE_SOURCE:.cpp=.o) $(APP_SOURCES:.cpp=.o)
	$(CXX) $(CFLAGS) -o bin/app $(BASE_SOURCE:.cpp=.o) $(APP_SOURCES:.cpp=.o)

test: $(BASE_SOURCE:.cpp=.o) $(TEST_SOURCES_C:.c=.o) $(TEST_SOURCES_CPP:.cpp=.o)
	$(CXX) $(CXXFLAGS) -o bin/test $(BASE_SOURCE:.cpp=.o) $(TEST_SOURCES_C:.c=.o) $(TEST_SOURCES_CPP:.cpp=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf bin/* *.o src/*o test/*.o test/unity_framework/*.o 

.PHONY: all clean app test
