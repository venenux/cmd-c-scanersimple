/*
 * scanersimple.c  Este programa es GNU, visite www.gnu.org para ver la licensia
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
/* inclusion de libfprint, ojo deben tener el repo venenux y libfprint-dev instalado */
#include <fprint.h>

int main(int argc, char **argv)
{

	unsigned char *nombreimagen = "dedoescaneado.pgm";
	int procesoscan = 0;

	/* manejo de argumentos para decirle nombre de la imagen */
	int argnm;
	for(argnm = 1; argnm < argc; argnm++)
	{
		if( strcmp(argv[argnm],"image") == 0) /* buscamos si se mando especificar el argumento de iamegn (nombre de) */
			nombreimagen = argv[argnm+1]; /* si encontramos imagen en argumentos, asumimos el sieguiente4 el nombre */
		if( strcmp(argv[argnm],"enroll") == 0)
			procesoscan = 1; /* anadimos esto para dedirle al programa, que escanee , sino obviamos, seguridad? quiza! */
	}

	int devresult = 1; /* usaremos esto para marcar el estado de nuestro dispositivo usandose */
	int prg_sts = 0; /* estado en que se esta el programa, asume todo malo, se verifica en el camino todo */

	/* inicializacion de la libreria, carga de objetos y corroboracion de dispositivos posibles */
	devresult = fp_init();

	if ( devresult < 0 ) /* libreria mal enlazada o no esta instalado libfprint, instalarla con aptitude install libfprint-dev */
		exit (99);

	struct fp_dscv_dev **dispositivosposibles; /* arreglo de estrucutra que representa dispositivos scaners */
	dispositivosposibles = fp_discover_devs (); /* invoco libfprint a que busque los readers de dedos */
	if ( !dispositivosposibles ) /* libreria enlazada pero usb de computadora malo, o no encontro dispositovos conectados */
		exit (2);

	struct fp_dscv_dev *disposivouno; /* estructura que define dispositivo valido */
	disposivouno = dispositivosposibles[0]; /* seleccionado el primer dispositivo de todos los encontrados */
	if ( !disposivouno ) /*libreria enlazada, usb bueno, pero dispositivo 1 no valido, o el seleccionado primero no sirve */
		exit (1);

	struct fp_driver *dvc; /* representacion de caracteristicas del dispositivo seleccionado arriba */
	dvc = fp_dscv_dev_get_driver ( disposivouno ); /* identificacion del dispositivo (opcional) */
	/* en este punto tengo la referencia/ubicacion del disp, y lo uso desde dicha ubicacion */
	unsigned char *dvcname = fp_driver_get_full_name(dvc); /* opcional: obtengo nombre legible del dispositivo segun su referencia/ubicacion */

	struct fp_dev *dispositivo; /* representar el dispositivo a manejar en el codigo */
	dispositivo = fp_dev_open (disposivouno); /* representacion del dispositivo usandose */
	fp_dscv_devs_free( dispositivosposibles ); /* ya tengo el scaner, limpio el bus usb con toda la info anterior recopilada */
	if(!dispositivo)
	{
		/* "dispositivo esta ocupado o siendo usado, use otro.. */
		fprintf(stderr, "dispositivo : %s, esta siendo usado.. \n", dvcname );
		fp_exit (); /* recuerde que por usar el api de libusb 1, solo se puede acceder a un dispositivo por instancia de referencia */
		exit(98); /* para acceder a el bus seria con otro dispositivo, y de paso esperar se libere la interupcion */
	}
	fprintf(stderr, "Encontrado : %s \n", dvcname );

	struct fp_print_data *data_deo_tempo = NULL; /* reservo otro lugarcito para datos de manejo */
	int r;

	/* if ( procesoscan == 1 ) */ /* descomenta esta linea para usar el parametro enroll */
	do /* metemos un bucle para que espere por el escaneo una vez prendido */
	{
		struct fp_img *img = NULL; /* reservo un lugar para manejar la imagen, una fotico de la victima */
		r = fp_enroll_finger_img ( dispositivo, &data_deo_tempo, &img); /* en este punto se enciende el dispositivo  */
		if(img) /* despues de escanear, libfprint maneja el device, si guardo algo, img no es nulo */
		{
			fp_img_save_to_file ( img, nombreimagen);
			fp_img_free (img);
			fp_print_data_free(data_deo_tempo);
			fprintf(stderr,"salvada imagen en %s\n",nombreimagen);
		}
		/* la variable img, su ubicacion en ram tendra datos y no sera nula si todo fue bien */
		/* r guarda el resultado de la operacion, haya escaneado o no la imagen */
		switch (r)
		{
			case FP_ENROLL_COMPLETE:
				prg_sts = 0;
				break;
			case FP_ENROLL_FAIL: /* hay mas casos pero por motivos didacticos estos son suf */
				fprintf(stderr, "fallo huella o proceso mal hecho?\n");
				fp_dev_close(dispositivo);
				fp_exit ();
				prg_sts = NULL;
		}
		if(r<0) /* en casos extraños el dispositivo no guarda imagenes sino binarizados */
		{
			fp_dev_close(dispositivo);
			fp_exit ();
		}
	}
	while( r!= FP_ENROLL_COMPLETE ); /* el dispositivo estara esperando el dedo hasta exito o el break del case */

	/* liberacion de memoria */
	fp_dev_close(dispositivo);
	fp_exit ();

	/* salida */
	return (prg_sts);

}
