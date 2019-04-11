#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define DLUGOSC 60

struct pomiar {
	unsigned int nr_pomiaru;
	unsigned int nr_czujnika;
	char data_i_czas[20];
	double temp;
	struct pomiar *nast;
};

pomiar* wczytajPlik(char nazwaPliku[DLUGOSC]) {
	FILE *f;
	if ((f = fopen(nazwaPliku, "r")) == NULL) {
		printf("Blad otwarcia pliku.\n");
		return NULL;
	}
	pomiar *glowa = NULL; //glowa jest pusta
	pomiar *poprzedni = NULL;
	while (!feof(f)) {
		pomiar *p = (pomiar*)malloc(sizeof(pomiar));
		fscanf(f, "%d", &(p->nr_pomiaru));
		fscanf(f, "%d", &(p->nr_czujnika));
		fscanf(f, "%s", p->data_i_czas);
		int w = fscanf(f, "%lf", &(p->temp));
		p-> nast = NULL;
		if (w > 0) {
			if (glowa == NULL) {
				glowa = p;
			}
			else {
				poprzedni->nast = p;
			}

			//printf("Wczytano z pliku nr pomiaru %d\n", p->nr_pomiaru);
			poprzedni = p;
		} 
		else {
			free(p);
		}
	}
	fclose(f);
	return glowa;
}

void drukujListe(pomiar* glowa) {
	pomiar* pom = glowa;
	printf("Lista:\n");
	while (pom != NULL) {
		printf("%d, %d, %s, %lf -> ", pom->nr_pomiaru, pom->nr_czujnika, pom->data_i_czas, pom->temp);
		pom = pom->nast;
	}
	printf("NULL\n");
}

void rozdziel(pomiar** g1, pomiar** g2, pomiar** g3, pomiar** g4, pomiar** glowaZrodlowa) { //nasza glowa
	*g1 = NULL;
	*g2 = NULL;
	*g3 = NULL;
	*g4 = NULL;
	pomiar* o1 = NULL; //ostatni
	pomiar* o2 = NULL;
	pomiar* o3 = NULL;
	pomiar* o4 = NULL;
	while ((*glowaZrodlowa) != NULL) {
		pomiar* przeniesienie = *glowaZrodlowa;
		*glowaZrodlowa = (*glowaZrodlowa)->nast;
		if (przeniesienie->nr_czujnika == 1) {
			if (*g1 == NULL) {
				*g1 = przeniesienie;
				o1 = przeniesienie;
			}
			else {
				o1->nast = przeniesienie;
				o1 = przeniesienie;
			}
			przeniesienie->nast = NULL;
		}
		if (przeniesienie->nr_czujnika == 2) {
			if (*g2 == NULL) {
				*g2 = przeniesienie;
				o2 = przeniesienie;
			}
			else {
				o2->nast = przeniesienie;
				o2 = przeniesienie;
			}
			przeniesienie->nast = NULL;
		}
		if (przeniesienie->nr_czujnika == 3) {
			if (*g3 == NULL) {
				*g3 = przeniesienie;
				o3 = przeniesienie;
			}
			else {
				o3->nast = przeniesienie;
				o3 = przeniesienie;
			}
			przeniesienie->nast = NULL;
		}
		if (przeniesienie->nr_czujnika == 4) {
			if (*g4 == NULL) {
				*g4 = przeniesienie;
				o4 = przeniesienie;
			}
			else {
				o4->nast = przeniesienie;
				o4 = przeniesienie;
			}
			przeniesienie->nast = NULL;
		}
	}
}

int dlugoscListy(pomiar* glowa) {
	int d = 0;
	pomiar* pom = glowa;
	printf("Lista:\n");
	while (pom != NULL) {
		d++;
		pom = pom->nast;
	}
	return d;
}

void drukujListedopliku(pomiar* glowa, FILE* f) {
	pomiar* pom = glowa;
	while (pom != NULL) {
		fprintf(f, "%d %d %s %lf\n", pom->nr_pomiaru, pom->nr_czujnika, pom->data_i_czas, pom->temp);
		pom = pom->nast;
	}
}

void zapiszDoPliku(char nazwaPliku[DLUGOSC], int numer, pomiar* glowa) {
	int indeks = 0;
	while (nazwaPliku[indeks] != '\0') {
		indeks++;
	}
	nazwaPliku[indeks] = numer + '0';
	nazwaPliku[indeks + 1] = '.';
	nazwaPliku[indeks + 2] = 't';
	nazwaPliku[indeks + 3] = 'x';
	nazwaPliku[indeks + 4] = 't';
	nazwaPliku[indeks + 5] = '\0';
	FILE *f;
	f = fopen(nazwaPliku, "w");
	drukujListedopliku(glowa, f);
	fclose(f);
	nazwaPliku[indeks] = '\0';
}

int main() {
	printf("Program...Autor...\n");
	char nazwaPliku[DLUGOSC];
	printf("Podaj nazwe pliku.\n");
	scanf("%s", nazwaPliku);
	pomiar* glowa = wczytajPlik(nazwaPliku);
	pomiar* g1;
	pomiar* g2;
	pomiar* g3;
	pomiar* g4;
	rozdziel(&g1, &g2, &g3, &g4, &glowa);
	printf("Dlugosc listy 1 %d\n", dlugoscListy(g1));
	printf("Dlugosc listy 2 %d\n", dlugoscListy(g2));
	printf("Dlugosc listy 3 %d\n", dlugoscListy(g3));
	printf("Dlugosc listy 4 %d\n", dlugoscListy(g4));
	char nazwaPliku2[DLUGOSC];
	printf("Podaj nazwe pliku do zapisu.\n");
	scanf("%s", nazwaPliku2);
	zapiszDoPliku(nazwaPliku2, 1, g1);
	zapiszDoPliku(nazwaPliku2, 2 ,g2);
	zapiszDoPliku(nazwaPliku2, 3, g3);
	zapiszDoPliku(nazwaPliku2, 4, g4);
	printf("Koniec programu.\n");
	return 0;
}
