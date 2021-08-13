.PHONY: codebook.pdf autoOpenPdf clean

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Darwin)
XELATEX=/Library/TeX/texbin/xelatex
else
XELATEX=xelatex
endif

BUILD_DIR := $(shell [ -d build ] || mkdir build; echo build)
LATEXFLAGS = -output-directory=$(BUILD_DIR)

all: codebook.pdf

codebook.pdf: main.tex content.tex
	$(XELATEX) $(LATEXFLAGS) main.tex
	$(XELATEX) $(LATEXFLAGS) main.tex
	cp $(BUILD_DIR)/main.pdf ./codebook.pdf

autoOpenPdf: codebook.pdf
ifeq ($(UNAME_S), Linux)
	xdg-open ./codebook.pdf
else ifeq ($(UNAME_S), Darwin)
	open ./codebook.pdf
endif

clean:
	rm -f codebook.pdf
