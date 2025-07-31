# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Target executables
TARGETS = in2post.x test_stack.x

# Source and header files
IN2POST_SRC = in2post.cpp
TEST_STACK_SRC = test_stack.cpp
HEADERS = stack.h stack.hpp

# Build rule for in2post.x
in2post.x: $(IN2POST_SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o in2post.x $(IN2POST_SRC)

# Build rule for test_stack.x
test_stack.x: $(TEST_STACK_SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o test_stack.x $(TEST_STACK_SRC)

# Rule to build all targets
all: $(TARGETS)

# Clean rule to remove all generated executables
clean:
	rm -f $(TARGETS)
