#ifndef _SKOROWIDZ_H_
#define _SKOROWIDZ_H_

typedef struct {
	char *slowo;
	int *linie;
	int licznik;
	int size;	
} slowo_t

slowo_t* utworz_skorowidz(int n); // n- liczba slow
void dodaj_slowo(slowo_t *s, char *str) ;
void dodaj_linie(slowo_t *s, int i, int nr);
void wypisz_skorowidz(slowo_t *s);

void usun_skorowidz(slowo_t *s);
