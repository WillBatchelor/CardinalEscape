WORGLE=worgle/worgle
SORG=worgle/sorg

CFLAGS = -Wall -pedantic -O2 -std=c89

LDFLAGS=-lncurses

default: all

all: $(WORGLE) $(SORG) hello

hello.c: hello.org
	$(WORGLE) -g $<

hello: hello.o
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(WORGLE):
	cd worgle; make

$(SORG):
	cd worgle; make sorg

clean:
	$(RM) hello.c hello.o hello
	cd worgle; make clean;
