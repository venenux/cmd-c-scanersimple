
CC = gcc
CFLAGS = -g -Wall 
# usamos libfprint, debemos incluir su directorio de cabeceras, requeire libfprint-dev
INCFLAGS = -I/usr/include/libfprint 
# usamos venenux<= 1.0  por tanto buscamos liberias en usr/lib
LDFLAGS = -lfprint  

all: clean escanersimple escanerdedo

escanersimple:
	$(CC) -o escanersimple $@.c $(LDFLAGS) $(INCFLAGS)

escanerdedo:
	$(CC) -o escanerdedo $@.c $(LDFLAGS) $(INCFLAGS)

clean:
	rm -f *.o *.pgm *.pnm escanersimple escanerdedo

.PHONY: all
.PHONY: clean
