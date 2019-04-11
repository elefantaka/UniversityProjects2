#include <stdio.h>
#include <ctype.h>

#define DLUGOSC 50
#define DLUGOSC 5

struct para
{
	char napis[DLUGOSC];
	int liczba;
};

int wiersz(FILE* f, struct para *p);

int wiersz(FILE* f, struct para *p) //brakuje nazwy pliku
{
	if (feof(f)) //koniec pliku, EOF
	{
		return 1;
	} 
	int indeks;
	fscanf_s(f, "%d", &indeks);
	fscanf_s(f, "%s", p->napis); //strzalka bo p jest wskaznikiem, jesli by nie byla to kropka
	fscanf_s(f, "%d", &(p->liczba));
	return 0; //zwraca 0 gdy sie udalo, 1 gdy sie nie udalo, zapisac jeden wiersz dane do p
}

int main()
{
	printf("Program...Autor...\n");
	struct para tab[DLUGOSC];
	char nazwaPliku[DLUGOSC];
	char nazwaPliku_wyjsciowego[DLUGOSC];
	printf("Podaj nazwe pliku\n");
	scanf_s("%s", nazwaPliku);
	scanf_s("%s", nazwaPliku_wyjsciowego);
	FILE *f1, *f2;
	if ((f1 = fopen(nazwaPliku, "r")) == NULL)
	{
		printf("Pliku %s nie zostal otwarto\n", nazwaPliku);
		return 1; //konczy dzialanie maina
	}
	printf("Plik %s zostal otwarty\n", nazwaPliku);
	if ((f1 = fopen(nazwaPliku_wyjsciowego, "w")) == NULL)
	{
		printf("Pliku %s nie zostal otwarto\n", nazwaPliku_wyjsciowego);
		return 1;
	}
	printf("Plik %s zostal otwarty\n", nazwaPliku_wyjsciowego);
	int w;
	int i = 0;
	while ((w = wiersz(f1, &(tab[i]))) != 1)
	{
		fprintf(f2, "%s", tab[i].napis);
		fprintf(f2, "%d\n", tab[i].liczba);
		i++;
	}
	fclose(f1);
	fclose(f2);
	printf("Koniec programu\n");
	return 0;
}