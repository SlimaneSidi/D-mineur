CC := gcc
CFLAGS := -Wall -O2 -o

BUILDDIR := ./build
INCLUDE := ./include
SRC := ./src
SRCFILES := main.c gameloop.c gridhandler.c
OBJFILES := $(patsubst %.c, $(BUILDDIR)/%.o, $(SRCFILES)) # changer les .c en .h

all: $(BUILDDIR) output

$(BUILDDIR):
	mkdir $(BUILDDIR)

output: $(OBJFILES)
	$(CC) $(CFLAGS) $@ $^ -lm 

$(BUILDDIR)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) $@ -c $< -Wno-unused-result

clean:
	rm -fr $(BUILDDIR)
	rm -f output