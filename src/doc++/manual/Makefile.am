# doc/manual/Makefile.am for DOC++
# Copyright (c) 1999-2000 Dragos Acostachioaie

DOCXX = ../../src/doc++

# C locale
LANG=C

# japanese redhat linux default locale
# LANG=ja_JP.ujis

SOURCES = A.h B.h C.h FAQ.dxx commandline.dxx config.dxx doc.dxx fields.dxx \
	  general.dxx install.dxx intro.dxx reference.dxx short.dxx tags.dxx \
	  ../doc++.conf ../docxx-br.sty ../docxx-fr.sty ../docxx-ja.sty \
	  ../docxx-ro.sty ../docxx.sty

all:	html

html:	doc.dxx
	case $(LANG) in ja_JP.EUC | ja_JP.ujis | ja) \
		export LANG=$(LANG);\
		$(DOCXX) -d html $(srcdir)/doc.dxx ;;\
	*)  $(DOCXX) -d html $(srcdir)/doc.dxx ;;\
	esac;

docxx-br.sty:
	$(LN_S) $(srcdir)/../docxx-br.sty .

docxx-fr.sty:
	$(LN_S) $(srcdir)/../docxx-fr.sty .

docxx-ja.sty:
	$(LN_S) $(srcdir)/../docxx-ja.sty .

docxx-ro.sty:
	$(LN_S) $(srcdir)/../docxx-ro.sty .

docxx.sty:
	$(LN_S) $(srcdir)/../docxx.sty .

latex:	doc.dxx docxx-br.sty docxx-ja.sty docxx-ro.sty docxx.sty
	case $(LANG) in ja_JP.EUC | ja_JP.ujis | ja) \
		export LANG=$(LANG);\
		$(DOCXX) -t -o doc.tex -ep a4wide $(srcdir)/doc.dxx;\
		latex doc;\
		latex doc;;\
	*) $(DOCXX) -t -o doc.tex -ep a4wide $(srcdir)/doc.dxx;\
		latex doc;\
		latex doc;;\
	esac;

ps:
	$(MAKE) latex
	dvips -o doc.ps doc.dvi

pdf:
	$(MAKE) ps
	ps2pdf doc.ps

clean-local:
	rm -rf html/ *.tex *.log *.aux *.dvi *.ps *.pdf docxx*.sty
