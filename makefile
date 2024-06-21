CC := gcc
CFLAGS := -Wall -O2 -o

BUILDDIR := ./build
INCLUDE := ./include
SRC := ./src
SRCFILES := main.c gridhandler.c demineur.c
OBJFILES := $(patsubst %.c, $(BUILDDIR)/%.o, $(SRCFILES))

all: $(BUILDDIR) libisentlib.a zubr

$(BUILDDIR):
	mkdir $(BUILDDIR)

libisentlib.a:
	make -C gfxlib/

zubr: $(OBJFILES)
	$(CC) $(CFLAGS) $@ $^ gfxlib/build/libisentlib.a -lX11 -lm -lglut -lGL -pthread 

$(BUILDDIR)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) $@ -c $< -Wno-unused-result

rocknoir:
	make clean -C gfxlib/
	rm -f $(BUILDDIR)/*.o
	rm -fr $(BUILDDIR)
	rm -f zubr