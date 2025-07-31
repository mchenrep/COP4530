# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Target executables
TARGETS = proj4.x

# Source and header files
DRIVER_SRC = driver.cpp
HEADERS = BET.h BET.hpp

# Build rule for proj4.x
proj4.x: $(DRIVER_SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o proj4.x $(DRIVER_SRC)

# Rule to build all targets
all: $(TARGETS)

# Clean rule to remove all generated executables
clean:
	rm -f $(TARGETS)
