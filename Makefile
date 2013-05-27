
CC = gcc
CFLAGS = -g -Wall
# tenemos un main.c y diremos que contruya en objeto scanersimple.o
OBJECTS = escanersimple.o
# usamos libfprint, debemos incluir su directorio de cabeceras, requeire libfprint-dev
INCFLAGS = -I/usr/include/libfprint  
# usamos venenux<= 1.0  por tanto buscamos liberias en usr/lib
LDFLAGS = -Wl,-rpath,/usr/lib -lfprint  

all: clean escanersimple

escanersimple: $(OBJECTS)
	$(CC) -o escanersimple $(OBJECTS) $(LDFLAGS)

.SUFFIXES:
.SUFFIXES:	.c .cc .C .cpp .o

.c.o :
	$(CC) -o $@ -c $(CFLAGS) $< $(INCFLAGS)

clean:
	rm -f *.o escanersimple

.PHONY: all
.PHONY: clean
