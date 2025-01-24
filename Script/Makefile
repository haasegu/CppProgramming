# SHELL = /bin/csh


NAME=main
#psfile=c-vorlesung.ps
#pdffile=c-vorlesung.pdf

L2H = -no_math -html_version 3.2,math  -t "Vorlesung Programmierung" -local_icons -scalable_fonts -show_section_numbers -toc_depth 2
# -split 2
# -ps_images -antialias
#L2H = -no_math -html_version 3.2,math  -t "Parallelisierung und Vektorisierung" -scalable_fonts -show_section_numbers
#  -debug -verbosity 9
#L2H = -no_math -html_version 3.2,math -t "Parallelisierung und Vektorisierung"  -no_reuse -no_images
#L2H = -no_math -html_version 3.2,math -t "Parallelisierung und Vektorisierung"  -images_only
#-local_icons

default: pdf


simple:
	pdflatex $(NAME)

# pdf: $(NAME).pdf

WWWDIR = $(HOME)/public_html/Lectures/Kurs-C/Script/html
#PROGSDIR = $(HOME)/progs/Kurs-C
#WWWDIR = ../html
PROGSDIR = ../Beispiele

www: pdf
	-cp $(NAME).pdf $(WWWDIR)/script_programmieren.pdf
	-cp -u lit.html $(WWWDIR)/..
##	cp -upr $(PROGSDIR)/*  $(WWWDIR)/../$(PROGSDIR)
##	cd  $(PROGSDIR); make archiv
##	cd  $(WWWDIR)/examples; unzip $(PROGSDIR)/Source.zip

notes: ps
	@psnup -pa4 -2 $(NAME).ps notes.ps

# $(NAME).pdf: *.tex *.bib
pdf: *.tex *.bib
	-pdflatex $(NAME)
#			German ordering, word ordering
# 	makeindex -g $(NAME).idx
	makeindex  $(NAME).idx
	bibtex $(NAME)
	-pdflatex $(NAME)
	makeindex -c  $(NAME)
	-pdflatex $(NAME)


bibtest: bibtest.tex parallel.bib
	pdflatex bibtest
	bibtex bibtest
	pdflatex bibtest
	pdflatex bibtest
	pdflatex2html $(L2H) bibtest

ispell:
	ispell -d deutsch *.tex



L2HT = -no_math -html_version 3.2  -t "Test" -scalable_fonts -short_index -split 4 -link 5 -show_section_numbers -toc_depth 4 -no_reuse


ttest:
	latex test
	latex2html $(L2HT) test

clean:
	rm -rf $(NAME) $(NAME).ps $(NAME).pdf *.log *.blg *.dvi *.idx *.bbl *.aux *.toc  *.ilg

LOCTAR = vorlesung.tar
UPDATEFILES = Makefile main.tex kap*.tex *.bib *.fig *.pstex* *.eps konvert*

tar:
	@tar cvf $(LOCTAR) $(UPDATEFILES)

.PRECIOUS: .tex .cc .hh
.SUFFIXES: .tex .dvi .ps .pdf

#.tex.dvi:
#	latex $<

.dvi.ps:
	dvips -Pcmz -o $@ $<

.ps.pdf:
	ps2pdf $< $@
# 	pdflatex $(NAME)
