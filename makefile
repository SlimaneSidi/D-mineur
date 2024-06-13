CC := gcc
CFLAGS := -Wall -O2 -o

BUILDDIR := ./build
INCLUDE := ./include
SRC := ./src
SRCFILES := demineur.c genBombes.c menu.c Niveau1.c time.c
OBJFILES := $(patsubst %.c, $(BUILDDIR)/%.o, $(SRCFILES))

all: $(BUILDDIR) output

$(BUILDDIR):
	mkdir $(BUILDDIR)

output: $(OBJFILES)
	$(CC) $(CFLAGS) $@ $^ -lm 

$(BUILDDIR)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) $@ -c $< -Wno-unused-result

clean:
	rm -f $(BUILDDIR)/*.o
	rm -fr $(BUILDDIR)
	rm -f output