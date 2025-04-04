# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++0x -I. -Wall -Wextra -fmessage-length=0 -Wno-sign-compare -O3 -g0
LDFLAGS = -lpthread

# Target executable
TARGET = main

# Object files
OBJS = main.o matrixSolvers.o matrixGenerator.o Matrix.o

# Default target
all: $(TARGET)

# Linking the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

# Compiling source files into object files
main.o: main.cpp Matrix.h matrixSolvers.h matrixGenerator.h
	$(CXX) $(CXXFLAGS) -MMD -o main.o -c main.cpp

matrixSolvers.o: matrixSolvers.cpp matrixSolvers.h Matrix.h
	$(CXX) $(CXXFLAGS) -MMD -o matrixSolvers.o -c matrixSolvers.cpp

matrixGenerator.o: matrixGenerator.cpp matrixGenerator.h Matrix.h
	$(CXX) $(CXXFLAGS) -MMD -o matrixGenerator.o -c matrixGenerator.cpp

Matrix.o: Matrix.cpp Matrix.h
	$(CXX) $(CXXFLAGS) -MMD -o Matrix.o -c Matrix.cpp

# Clean up the generated files
clean:
	rm -f $(OBJS) $(TARGET) *.d

# Include dependency files
-include $(OBJS:.o=.d)