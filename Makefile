.PHONY: html

WORGLE=worgle/worgle
SORG=worgle/sorg

CFLAGS = -Wall -pedantic -O3 -std=c89

LDFLAGS=-lncurses

ORGS=top.org res.org display.org input.org map.org

OBJ=cardinalescape.o

default: all

all: $(WORGLE) $(SORG) cardinalescape

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

cardinalescape.c: $(ORGS)
	$(WORGLE) -Werror -g $(ORGS)

cardinalescape: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(LDFLAGS)

hello: hello.o
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(WORGLE):
	cd worgle; make

$(SORG):
	cd worgle; make sorg

html: cardinalescape.html cardinalescape_toc.html

cardinalescape.html: $(ORGS) $(SORG)
	cat $(ORGS) | $(SORG) > $@

cardinalescape_toc.html: $(ORGS) $(SORG)
	cat $(ORGS) | $(SORG) -t cardinalescape.html > $@

clean:
	cd worgle; make clean;
	$(RM) cardinalescape.html
	$(RM) cardinalescape_toc.html
	$(RM) $(OBJ)
	$(RM) cardinalescape.h cardinalescape_private.h
	$(RM) cardinalescape.c
