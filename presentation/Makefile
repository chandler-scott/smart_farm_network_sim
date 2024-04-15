# Definition of variables
TARGET = presentation

# Default target
all: $(TARGET).pdf

# RUle to generate PDF from LaTeX source
$(TARGET).pdf: $(TARGET).tex
	pdflatex $(TARGET).tex

clean:  # Command to remove all files except .tex files and the Makefile
	find . -type f \
		\( ! -name '*.tex' \
		! -name 'Makefile' \) \
		-exec rm -f {} +

