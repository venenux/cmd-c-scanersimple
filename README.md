scanersimple: como programar y usar un scaner de huellas digitales
============

scanersimple, aplicacion para aprender usar el finger print library
scanersimplegui, interfaz grafica que ejemplifica como usar dicho programa scanersimple


Instrucciones
=============

El codigo fuente de c tiene en cada linea documentado, 

ademas evita usar funciones y direcciones de memoria desde las mismas.

Con este ejemplo secuencial, puede ser usado como C o C++

esto porque accede a lugares reservados de memoria en vez de acceder a variables.

en la raiz tiene scanersimple.c y un makefile, tambien esta un subdirectorio, 
este subdirectorio contiene el gui en gambas3, cargelo en su ide gambas3.

Notas:

libfprint puede ser consumido como C o C++ dado la forma de usarse de la misma libreria.


USO, compilar y ver el fuente:
=============================

Para el codigo C ( scanersimple.c ) :

1. aptitude install libfprint-dev
2. descarge el codigo, y el makefile
3. coloquelo en un diretorio
4. ejecute make all
5. ejecute ./scanersimple

Si no hay dispositivos escaneadores de dedos el programa salira.


Para usar el gui en gambas3 (scanersimplegui.class ) :

1. aptitude install gambas3
2. abra el ide gambas3
3. busque el proyecto, esto solo con encontrar el directorio donde descargo este fuente
4. revise el codigo, debe cambiar la ruta del ejecutable en la funcion "scan_dedo_imagen" 
4.1. cambielo por la ruta exacta donde esta el compilado anterior de c
5. en "proyecto" puede generar un tarbal o ejecutable gambas

LICENCIA:
========

GPLv3+

Versiones futuras:
=================

* Soporte DB
* Implementacion directa de la libreria
* Configuracion por archivo
* Soporte webcam
* Encriptacion y storage en DB
* Deteccion de teclado
* bloqueo de interfaz en enrolamiento de foto
* Log de hora y disparo

Las versiones futuras estaran en otro repo para no romper el esquema didactico.
