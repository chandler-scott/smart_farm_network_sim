# Definition of variables
SOURCES = presentation.tex
TARGET = presentation.pdf

.PHONE: all clean

# Default target
all: $(TARGET)

# RUle to generate PDF from LaTeX source
$(TARGET): $(SOURCES) 
	pdflatex $(SOURCES)

clean:  # Command to remove all files except .tex files and the Makefile
	find . -type f \
		\( ! -name '*.tex' \
		! -name 'Makefile' \) \
		-exec rm -f {} +

