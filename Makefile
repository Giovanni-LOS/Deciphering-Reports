IDIR = include
CC=gcc
CFLAGS= -O2 -funroll-loops -Ofast -flto -finline-functions -I$(IDIR)

ODIR= src

LIBS=

_DEPS = input.h process.h initatt.h output.h error.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o input.o process.o initatt.o output.o error.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
