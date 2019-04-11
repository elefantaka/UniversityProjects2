#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define DLUGOSC 60

char **alokujTab(int m, int n) {
	char **tab = (char**)malloc(m * sizeof(char*)); //alokowanie tablicy wskaznikow do wierszy
	for (int i = 0; i < m; i++) {
		tab[i] = (char*)malloc(n * sizeof(char));
	}
	return tab;
}

int wczytajDane(int m, int n, char **tab, char nazwaPliku[]) {
	FILE *f;
	if ((f = fopen(nazwaPliku, "r")) == NULL) {
		printf("Plik %s nie zostal otwarty\n", nazwaPliku);
		return 0;
	}
	int iloscLiczb = 0;
	printf("Plik %s zostal otwarty\n", nazwaPliku);
	int x = fscanf(f, "%s", tab[iloscLiczb]); //string 
	while (x > 0) {
	
		if (tab[iloscLiczb][0] != '1') {
			printf("Bledna liczba w pliku\n");
		}
		iloscLiczb++;
		x = fscanf(f, "%s", tab[iloscLiczb]); //string 
	}
	printf("\nWczytano %d liczb.\n", iloscLiczb);
	fclose(f);
	return iloscLiczb;
}

void wypiszTab(char **tab, int iloscLiczb) {
	printf("\nTablica:\n");
	for (int i = 0; i < iloscLiczb; i++) {
		printf("%s\n", tab[i]);
	}
}

int bin2int(char *wiersz) { //schemat hornera
	int wynik = 0;
	int i = 0;
	while (wiersz[i] != '\0') {
		wynik = wynik * 2 + (wiersz[i] - '0');
		i++;
	}
	return wynik;
}

void tab2int(char **tab, int iloscLiczb) {
	printf("\nTablica:\n");
	for (int i = 0; i < iloscLiczb; i++) {
		int wynik = bin2int(tab[i]);
		printf("%d\n", wynik);
	}
}

void sortowanie(char **tab, int iloscLiczb) {
	for (int j = 0; j < iloscLiczb; j++) {
		for (int i = 0; i < (iloscLiczb - 1); i++) {
			if (bin2int(tab[i]) < bin2int(tab[i + 1])) {
				char *pom = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = pom;
			}
		}
	}
}



int main() {
	printf("Program...Autor...\n");
	int m, n;
	char nazwaPliku[DLUGOSC];
	printf("Podaj m.\n");
	scanf("%d", &m);
	printf("Podaj n.\n");
	scanf("%d", &n);
	printf("Podaj nazwe pliku.\n");
	scanf("%s", nazwaPliku);
	char **T = alokujTab(m, n);
	int iloscLiczb = wczytajDane(m, n, T, nazwaPliku);
	wypiszTab(T, iloscLiczb);
	tab2int(T, iloscLiczb);
	sortowanie(T, iloscLiczb);
	printf("\nSortowanie zakonczone.\n");
	tab2int(T, iloscLiczb);
	wypiszTab(T, iloscLiczb);
	printf("\nKoniec programu.\n");
	return 0;
}