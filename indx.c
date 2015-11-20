#include <stdio.h>  // wiadomo po co
#include <stdlib.h> 
#include <string.h> // strstri
#include "skorowidz.h"

#define BUFSIZE 8192   // zakładamy, że linie będą krótsze niż 8kB

int
main( int argc, char **argv ) {
	int i,j;
  	int ile_linii;
	char buf[BUFSIZE];

	FILE *in= argc > 1 ? fopen( argv[1], "r" ) : stdin;

	skorowidz_t *s = utworz_skorowidz(argv+2, argc-2);
	if( s->n == 0 ) {
		fprintf( stderr, "%s: błąd: proszę podać słowa do wyszukiwania\n", argv[0] );
		return EXIT_FAILURE;
	}

	if( in == NULL ) {
		fprintf( stderr, "%s: błąd: nie mogę czytać pliku %s\n", argv[0], argv[1] );
		return EXIT_FAILURE;
	}

	ile_linii= 0;
	while( fgets( buf, BUFSIZE, in ) != NULL ) {
		ile_linii++;
		for( i= 0; i < s->n; i++ )
			if( strstr( buf, s->skr[i]->slowo) != NULL ) {
				dodaj_linie(s, i, ile_linii);
			}
	}

	wypisz_skorowidz(s);
	usun_skorowidz(s);
	fclose(in);			
	return EXIT_SUCCESS;
}
