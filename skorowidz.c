#include "skorowidz.h"
#include <stdio.h>
#include <stdlib.h>
slowo_t utworz_slowo(char* str)
{
	slowo_t *s = malloc(sizeof (slowo_t));
	s->slowo = str;
	s->wystapienia = 0;
	s->size = 2;
	s->linie = malloc(sizeof( int) * s->size);
	return *s;
}

void dodaj_pozycje(slowo_t* s, int nr)
{
	if(s->wystapienia == s->size)
	{
		s->size *= 2;
		s->linie = realloc(s->linie, sizeof (int) * s->size);
	}
	
	s->linie[s->wystapienia] = nr;
	s->wystapienia++;
}


skorowidz_t* utworz_skorowidz(char **str, int n)
{
	skorowidz_t *s = malloc(sizeof(skorowidz_t));
	s->n = n;
	s->skr = malloc(sizeof(slowo_t) * n);
	int i=0;
	for(i=0; i < n; i++)
		s->skr[i] = utworz_slowo(str[i]);
	return s;
}
void dodaj_linie(skorowidz_t *s, int i, int nr)
{
	slowo_t * a = &(s->skr[i]);
	dodaj_pozycje(a, nr);
}
void wypisz_skorowidz(skorowidz_t *s)
{
	int i;
	int j;
	for(i=0; i< s->n; i++)
	{
		printf("Slowo %s wystapilo w liniach:  ", s->skr[i].slowo);
		for(j=0; j< s->skr[i].wystapienia; j++)
			printf("%d, ", s->skr[i].linie[j]);
		printf("\n");
	}
}
/*
int main(int argc, char **argv)
{
	skorowidz_t *s = utworz_skorowidz(argv+1, argc-1);
	int i;
	int j;
	for(i=0; i < argc-1; i++)
	{
		for(j=0; j< argc-1; j++)
			dodaj_linie(s, i, i*j);
		
	}
	wypisz_skorowidz(s); 
//	slowo_t t = utworz_slowo("raz");
//	printf("%s", t.slowo);
	return 0;

}
*/
