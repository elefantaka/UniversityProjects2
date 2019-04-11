#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>

#define ILE 60

struct  dane{
	long czas;
	int trafione;
};

void spr(int iloscProb) {
	assert(iloscProb > 0);
}

void zapiszLog(char message[ILE], FILE *f) {
	struct tm *newtime;
	time_t aclock;
	time(&aclock);
	newtime = localtime(&aclock);
	fprintf(f, "%s-- %s\n", asctime(newtime), message);
}

dane losowanie(int iloscProb, FILE *f) {
	
	char tab[ILE];
	srand(time(NULL));
	char losuj;
	char litera[8];
	dane wynik;
	wynik.trafione = 0;
	time_t start, finish;
	time(&start);
	for (int i = 0; i < iloscProb; i++) {
		losuj = (rand() % (122 + 1 - 97)) + 97;
		printf("%c\n", losuj);
		sprintf(tab, "wylosowana litera:%c", losuj);
		zapiszLog(tab, f);
		printf("Twoja kolej:  ");
		scanf("%s", litera); 
	
		if (losuj == litera[0]) {
			wynik.trafione++;
			sprintf(tab, "odpowiedz uzytkownika:%c, poprawna", litera[0]);
			zapiszLog(tab, f);
		}
		else {
			sprintf(tab, "odpowiedz uzytkownika:%c, niepoprawna", litera[0]);
			zapiszLog(tab, f);
		}
	}
	time(&finish);
	wynik.czas = difftime(finish, start);
	printf("Czas: %ld\n", wynik.czas);
	return wynik;
}

int plikIstnieje(char nick[ILE]) {
	int istnieje;
	FILE *f;
	f = fopen(nick, "r");
	if (f == NULL) {
		istnieje = 0;
	}
	else {
		istnieje = 1;
		fclose(f);
	}
	return istnieje;
}

void utworzPlik(char nick[ILE], dane wynik) {
	int indeks = 0;
	while (nick[indeks] != '\0') {
		indeks++;
	}
	nick[indeks] = '.';
	nick[indeks + 1] = 't';
	nick[indeks + 2] = 'x';
	nick[indeks + 3] = 't';
	nick[indeks + 4] = '\0';
	FILE *f;
	if (plikIstnieje(nick) == 0) {
		printf("Tworzymy plik %s\n", nick);
	}
	f = fopen(nick, "a");
	fprintf(f, "Czas: %ld  Ilosc trafien: %d\n", wynik.czas, wynik.trafione);
	fclose(f);
	nick[indeks] = '\0';
}



int main(int argc, char *argv[]) {
	printf("Program...Autor...\n");
	printf("%d\n%s\n", argc, argv[0]);
	char tab[ILE];
	FILE *f;
	f = fopen("log.txt", "a");
	if (f == NULL) {
		perror("Nie otwarto pliku log.txt\n");
		return 1;
	}
	char nick[ILE];
	int iloscProb;
	printf("Podaj swoj nick\n");
	scanf("%s", nick);
	sprintf(tab, "Pobrany nick:%s", nick);
	zapiszLog(tab, f);
	printf("Podaj liczbe naturalna\n");
	scanf("%d", &iloscProb);
	sprintf(tab, "Pobrana ilosc prob:%d", iloscProb);
	zapiszLog(tab, f);
	dane wynik;
	spr(iloscProb);
	wynik = losowanie(iloscProb, f);
	printf("Ilosc trafien: %d\n", wynik.trafione);
	utworzPlik(nick, wynik);
	fclose(f);
	printf("Koniec programu.\n");
	return 0;
}