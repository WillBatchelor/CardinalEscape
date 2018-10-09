WORGLE=worgle/worgle

CFLAGS = -Wall -pedantic -O2 -std=c89

LDFLAGS=-lncurses

default: all

all: $(WORGLE) hello

hello.c: hello.org
	$(WORGLE) -g $<

hello: hello.o
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(WORGLE):
	cd worgle; make

clean:
	$(RM) hello.c hello.o hello
	cd worgle; make clean;
