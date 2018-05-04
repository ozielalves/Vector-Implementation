# Makefile para Estrutura de Dados Básica I "TAD-VECTOR"
# Made by Daniel Guerra

# Default Conventions
Target = vector 	# Name of the executable
INCLUDES = include
HEADERS = $(wildcard $(INCLUDES)/*)
CXX = g++
CXXFLAGS = -Wall -w -std=c++11 -lm -I $(INCLUDES)
DOCS = html latex
RM = rm -v

# Directories
SRCDIR = src
OBJDIR = obj
BINDIR = bin

# Some locations
SOURCES := $(wildcard $(SRCDIR)/*.cpp)
OBJECTS := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)


all: project #docs

project: $(OBJECTS) $(HEADERS) | $(BINDIR)
	$(CXX) $(OBJECTS) $(CXXFLAGS) -o $(BINDIR)/$(Target)
	@echo "link created: "
	@ln -sfv $(BINDIR)/$(Target) $(Target)


docs:
	@doxygen Doxyfile
	
$(OBJECTS):	$(OBJDIR)/%.o : $(SRCDIR)/%.cpp $(HEADERS) | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(BINDIR):
	@mkdir -p $(BINDIR)

# PHONY targets
.PHONY: clean clean_txt clean_docs clean_proj

clean: clean_proj #clean_txt clean_docs

clean_proj:
	$(RM) -f $(OBJDIR)/*
	$(RM) -f $(BINDIR)/*
	$(RM) $(Target)	

##clean_txt: $(TEXT)
##	$(RM) -f $(TEXT)	

##clean_docs: $(DOCS)
##$(RM) -rf $(DOCS)
