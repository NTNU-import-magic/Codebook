.PHONY: codebook.pdf

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Darwin)
XELATEX=/Library/TeX/texbin/xelatex
else
XELATEX=xelatex
endif

BUILD_DIR=build
LATEXFLAGS=-output-directory=$(BUILD_DIR)

codebook.pdf: main.tex content.tex
	mkdir $(BUILD_DIR)
	$(XELATEX) $(LATEXFLAGS) main.tex
	$(XELATEX) $(LATEXFLAGS) main.tex
	cp $(BUILD_DIR)/main.pdf ./codebook.pdf
	rm -rf $(BUILD_DIR) 
clean:
	rm -f codebook.pdf