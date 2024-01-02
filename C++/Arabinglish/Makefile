# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall

# Executable name
TARGET = todo

# Source files
SRCS = main.cc arabians.cc display.cc

# Object files
OBJS = $(SRCS:.cc=.o)

# Build target
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

# Clean rule
clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: clean
