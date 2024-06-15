CC := gcc
CFLAGS := -Wall -O2 -o

BUILDDIR := ./build
INCLUDE := ./include
SRC := ./src
SRCFILES := main.c gameloop.c gridhandler.c
OBJFILES := $(patsubst %.c, $(BUILDDIR)/%.o, $(SRCFILES)) # changer les .c en .h

all: $(BUILDDIR) libisentlib.a output

$(BUILDDIR):
	mkdir $(BUILDDIR)

libisentlib.a:
	make -C gfxlib/

output: $(OBJFILES)
	$(CC) $(CFLAGS) $@ $^ gfxlib/build/libisentlib.a -lm -lglut -lGL -pthread 

$(BUILDDIR)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) $@ -c $< -Wno-unused-result

clean:
	make clean -C gfxlib/
	rm -f $(BUILDDIR)/*.o
	rm -fr $(BUILDDIR)
	rm -f output