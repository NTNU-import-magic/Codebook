.PHONY: codebook.pdf clean

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Darwin)
XELATEX=/Library/TeX/texbin/xelatex
else
XELATEX=xelatex
endif

all: codebook.pdf

BUILD_DIR := $(shell [ -d build ] && echo build || (mkdir build && echo build || echo error))
LATEXFLAGS := -output-directory=$(BUILD_DIR)
ifeq ($(BUILD_DIR), error)
$(error Cannot establish build dir)
endif

codebook.pdf: main.tex content.tex
	$(XELATEX) $(LATEXFLAGS) main.tex
	$(XELATEX) $(LATEXFLAGS) main.tex
	cp $(BUILD_DIR)/main.pdf ./codebook.pdf

clean:
	rm -rf build codebook.pdf 
