# Makefile for EDB1 project 'Vector-Implementation'

# Makefile made by Daniel Guerra

# Directories
srcdir = ./src
incdir = ./include
bindir = ./bin
datdir = ./data

# Macros
CC = g++
CFLAGS = -Wall -std=c++11 -lm -I$(incdir)
RM = rm -fv
OBJS = $(addprefix $(bindir)/,vector.o MyIterator.o)

#STILL GOING TO ADD MORE OBJECTS

# Phony targets (for more information, visit https://www.gnu.org/software/make/manual/make.html#Phony-Targets)

.PHONY: clean cleanbin cleandat
.PHONY: all main build

# Use "make" to compile everything
all: main build

# Use "make main" to compile only the main
main: vectorTest

# Use "make build" to build all modules
build: vector iterator

# Use "make vector" to build only the vector module
vector: $(bindir)/vector.o

# Use "make iterator" to build only the iterator module
iterator: $(bindir)/MyIterator.o

# Compiles the main
vectorTest: $(srcdir)/main.cpp $(OBJS)
	mkdir -p $(bindir)
	$(CC) $(CFLAGS) $^ -o $(bindir)/$@
	ln -sfv $(bindir)/$@ $@

# Builds only the vector module
$(bindir)/vector.o: $(incdir)/vector.inl $(incdir)/vector.hpp
	mkdir -p $(bindir)
	$(CC) $(CFLAGS) -c $< -o $@

# Builds only the vector module
$(bindir)/iterator.o: $(incdir)/MyIterator.inl $(incdir)/MyIterator.hpp
	mkdir -p $(bindir)
	$(CC) $(CFLAGS) -c $< -o $@

# Removes executable and objects
cleanbin:
	$(RM) $(bindir)/*
	$(RM) -r $(bindir)
	$(RM) life

# Removes data files
cleandat:
	$(RM) $(datdir)/*
	$(RM) -r $(datdir)

# Removes all objects, executables and data input and output files
clean: cleanbin cleandat

