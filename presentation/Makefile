# Project Name: Project Presentation
# Author: Chandler Scott
# Description: Smart Agriculture Project Presentation 


# Definition of variables
SOURCES = presentation.tex
TARGET = presentation.pdf
BUILD_TOOL = pdflatex

.PHONY: all clean

# Default target
all: $(TARGET)

# Rule to build the target
$(TARGET): $(SOURCES) 
	$(BUILD_TOOL) $(SOURCES)

# Clean target to remove build artifacts
clean:  
	find . -type f \
		\( ! -name '*.tex' \
 		! -name 'Makefile' \) \
		-exec rm -f {} +

