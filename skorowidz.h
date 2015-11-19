#ifndef _SKOROWIDZ_H
#define _SKOROWIDZ_H

typedef struct {
	char *slowo;
	int wystapienia;
	int *linie;
	int size;
} slowo_t;

typedef struct {
	slowo_t *skr;
	int n;
} skorowidz_t;

skorowidz_t* utworz_skorowidz(char **str, int n);
void dodaj_linie(skorowidz_t* s, int i, int nr);
void wypisz_skorowidz(skorowidz_t* s);
void usun_skorowidz(skorowidz_t* s);

#endif
