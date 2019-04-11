#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define DLUGOSC 50
#define ILE 5

struct para
{
	char napis[DLUGOSC];
	int liczba;
};

int wiersz(FILE* f, struct para *p);
void szyfruj(char tablica1[DLUGOSC], char tablica2[DLUGOSC]);

int wiersz(FILE* f, struct para *p) //brakuje nazwy pliku
{
	if (feof(f)) //koniec pliku, EOF
	{
		return 1;
	}
	int indeks;
	fscanf(f, "%d", &indeks);
	fscanf(f, "%s", p->napis); //strzalka bo p jest wskaznikiem, jesli by nie byla to kropka
	fscanf(f, "%d", &(p->liczba));
	return 0; //zwraca 0 gdy sie udalo, 1 gdy sie nie udalo, zapisac jeden wiersz dane do p
}

void szyfruj(char tablica1[DLUGOSC], char tablica2[DLUGOSC])
{
	int i = 0;
	while (tablica1[i] != '\0')
	{
		if (tablica1[i] == 'a' || tablica1[i] == 'e' || tablica1[i] == 'i' || tablica1[i] == 'y' || tablica1[i] == 'u' || tablica1[i] == 'o')
		{
			tablica2[i] = '*';
		}
		else
		{
			tablica2[i] = tablica1[i];
		}
		i++;
	}
	tablica2[i] = '\0';
}

int main()
{
	printf("Program...Autor...\n\n");
	struct para tab[DLUGOSC];
	char nazwaPliku[DLUGOSC];
	char nazwaPliku_wyjsciowego[DLUGOSC];
	printf("Podaj nazwe pliku.\n");
	scanf("%s", nazwaPliku);
	printf("Podaj nazwe pliku wyjsciowego.\n");
	scanf("%s", nazwaPliku_wyjsciowego);
	FILE *f1, *f2;
	if ((f1 = fopen(nazwaPliku, "r")) == NULL)
	{
		printf("Pliku %s nie zostal otwarty.\n", nazwaPliku);
		return 1; //konczy dzialanie maina
	}
	printf("Plik %s zostal otwarty.\n", nazwaPliku);
	if ((f2 = fopen(nazwaPliku_wyjsciowego, "w")) == NULL)
	{
		printf("Plik %s nie zostal otwarty.\n", nazwaPliku_wyjsciowego);
		return 1;
	}
	printf("Plik %s zostal otwarty.\n", nazwaPliku_wyjsciowego);
	int w;
	int n = 0;
	while ((w = wiersz(f1, &(tab[n]))) != 1)
	{
		char tab1[DLUGOSC];
		szyfruj(tab[n].napis, tab1);
		fprintf(f2, "%s ", tab1);
		fprintf(f2, "%d\n", tab[n].liczba);
		n++;
	}
	fclose(f1);
	fclose(f2);
	for (int i = 0; i < n; i++)
	{
		printf("%s ", tab[i].napis);
		printf("%d\n", tab[i].liczba);
	}
	printf("\nKoniec programu.\n");
	return 0;
}