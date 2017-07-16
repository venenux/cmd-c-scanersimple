scanersimple: programar y usar lector huella dactilar
============

scanersimple, aplicacion para aprender usar el finger print library: lector huella dactilar
scanersimplegui, interfaz grafica que ejemplifica como usar dicho programa scanersimple

**Este codigo es parte del proyecto simplecontrolasistencia:** 

[https://github.com/venenux/simplecontrolasistencia](https://github.com/venenux/simplecontrolasistencia.git)


Instrucciones
=============

El codigo fuente de c tiene cada linea documentado, 

ademas evita usar funciones y direcciones de memoria desde las mismas.

Con este ejemplo secuencial, puede ser usado como C o C++

esto porque accede a lugares reservados de memoria en vez de acceder a variables.

prerequisitos

* libfprint.

deberia agregar el repositorio VenenuX e instalar asi: aptitude install libfprint-dev
para poder desarrollar y/o usar este codigo fuente

libfprint puede ser consumido como C o C++ dado la forma de usarse de la misma libreria.

para la interfaz gui debe agregar el repositorio venenux e instalar: aptitude install gambas3

El codigo C compila en etch, lenny/0.8 o squeeze/0.9, el gui solo en estos dos ultimos.

USO, compilar y ver el fuente:
=============================

Para el codigo C ( scanersimple.c ) :

1. aptitude install libfprint-dev
2. descarge el codigo, y el makefile
3. coloquelo en un diretorio
4. ejecute make all
5. ejecute ./scanersimple o ./escanerdedo

Si no hay dispositivos escaneadores de dedos el programa salira con codigo error 99 o 1.

Este programa se emplea con la interfaz grafica simplecontrolasistencia.

LICENCIA:
========

GPLv3+

