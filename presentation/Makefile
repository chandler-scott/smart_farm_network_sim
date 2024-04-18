# Project Name: Project Presentation 
# Author: Chandler Scott
# Description: Smart Agriculture Project Presentation 


# Definition of variables
NAME = presentation
SOURCES = $(NAME).tex
TARGET = $(NAME).pdf
BUILD_TOOL = pdflatex

.PHONY: all clean

# Default target
all: $(TARGET)

# Rule to build the target
$(TARGET): $(SOURCES) 
	$(BUILD_TOOL) $(SOURCES)

# Clean target to remove build artifacts
clean:  
	rm -f $(NAME).out $(NAME).aux $(NAME).pdf $(NAME).log $(NAME).nav $(NAME).snm $(NAME).toc
