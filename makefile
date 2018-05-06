# Makefile para Estrutura de Dados Básica I "TAD-VECTOR"
# Made by Daniel Guerra

# Default Conventions
Target = vector 	# Name of the executable
INCLUDES = include
HEADERS = $(wildcard $(INCLUDES)/*)
CXX = g++
CXXFLAGS = -Wall -w -std=c++11 -lm -I $(INCLUDES)
RM = rm -v

# Directories
SRCDIR = src
OBJDIR = obj
BINDIR = bin

# Some locations
SOURCES := $(wildcard $(SRCDIR)/*.cpp)
OBJECTS := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)


all: project

project: $(OBJECTS) $(HEADERS) | $(BINDIR)
	$(CXX) $(OBJECTS) $(CXXFLAGS) -o $(BINDIR)/$(Target)
	@echo "link created: "
	@ln -sfv $(BINDIR)/$(Target) $(Target)
	
$(OBJECTS):	$(OBJDIR)/%.o : $(SRCDIR)/%.cpp $(HEADERS) | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(BINDIR):
	@mkdir -p $(BINDIR)

# PHONY targets
.PHONY: clean cleanbin cleanobj

clean: cleanbin cleanobj

cleanbin:
	$(RM) -rf $(BINDIR)
	$(RM) $(Target)	

cleanobj:
	$(RM) -rf $(OBJDIR)
