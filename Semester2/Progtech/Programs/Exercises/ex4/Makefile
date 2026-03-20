# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude

# Source and object files
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)

# Final executable
TARGET = build/main.exe

# Default target
all: $(TARGET)

# Link object files into executable
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

# Compile each .cpp into .o
src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean compiled files
clean:
	rm -f build/*.exe src/*.o

# =============================================
# Purpose:
# This Makefile automates the compilation of a C++ project
# with the following folder structure:
#   - src/      : contains all .cpp source files
#   - include/  : contains all .hpp header files
#   - build/    : contains the final executable
#
# Using this Makefile ensures:
#   1. Incremental compilation: only files that changed are recompiled
#   2. Automatic linking of all compiled object files
#   3. Easy addition of new source files without editing the Makefile
#   4. Clean separation of source and build artifacts
#
# ---------------------------------------------
# Variables:
#
# CXX       : The C++ compiler command (g++ in this case)
# CXXFLAGS  : Flags/options passed to the compiler
#             -std=c++17 : use C++17 standard
#             -Wall      : enable all compiler warnings
#             -Iinclude  : look in the 'include/' folder for header files
#
# SRC       : List of all .cpp source files in 'src/' (auto-detected using wildcard)
# OBJ       : List of corresponding object files (.o) for each source file
#             The .cpp extension is replaced with .o
#
# TARGET    : The final executable file path (build/main.exe)
#
# ---------------------------------------------
# Default target:
#
# 'all' is the default target that Make will build if no target is specified.
# It depends on the TARGET (build/main.exe). Running 'make' will:
#   1. Compile any changed .cpp files into object files
#   2. Link all object files into the final executable
#
# ---------------------------------------------
# Linking rule:
#
# $(TARGET): $(OBJ)
#   $(CXX) $(OBJ) -o $(TARGET)
#
# Meaning:
#   To create 'build/main.exe', link all object files listed in OBJ
#   The command uses the compiler (CXX) to produce the executable
#
# ---------------------------------------------
# Compile rule for individual .cpp files:
#
# src/%.o: src/%.cpp
#   $(CXX) $(CXXFLAGS) -c $< -o $@
#
# Explanation:
#   - Pattern rule: '%' is a wildcard for the filename
#   - $< refers to the first dependency (the .cpp file)
#   - $@ refers to the target file (the .o file)
#   - -c flag tells the compiler to **compile only**, not link
#   - This rule allows incremental compilation: only changed source files
#     are compiled into object files
#
# Example:
#   If 'src/Greedy.cpp' changes:
#     - g++ -std=c++17 -Wall -Iinclude -c src/Greedy.cpp -o src/Greedy.o
#   Other object files are left untouched
#
# ---------------------------------------------
# Clean target:
#
# 'make clean' removes compiled object files and the executable.
# This ensures a completely fresh build when needed.
# The exact command may differ depending on the system
#
# ---------------------------------------------
# Usage:
#   - Build project:      make
#   - Clean project:      make clean
#   - Rebuild from scratch: make clean && make
#
# ---------------------------------------------
# Notes:
#   - Adding a new .cpp file in 'src/' automatically includes it
#     because of the wildcard in SRC
#   - Incremental compilation saves time: unchanged files are not recompiled
#   - All compiled object files are reused during linking, keeping builds fast
# =============================================

