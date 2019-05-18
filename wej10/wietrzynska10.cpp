#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstring>

#define ILE 60

using namespace std;

class MojaKlasa {
	char **emails; //tablica napisow, tablica emaili
	int ile;
	MojaKlasa *nast;  //pole nast
	int idNowe;
public:
	MojaKlasa(int x, int idNowe2); //konstruktor z argumentem
	MojaKlasa(MojaKlasa& mk);	// konstruktor kopiuj¹cy
	~MojaKlasa();
	void setemail(const char* adres, int idx) { strcpy(emails[idx], adres); }
	char* getemail(int idx) { return emails[idx]; }
	void wypisz();
	MojaKlasa* szukaj(int szukaneIdNowe);
	friend class Wykladowca; //klasa wykladowca bedzie zaprzyjazniona wiec moze korzystac z pol prywatnych MojaKlasa
};

MojaKlasa::MojaKlasa(int x, int idNowe2) {
	emails = new char*[ile = x];
	for (int i = 0; i < ile; i++) emails[i] = new char[100];
	nast = NULL;
	idNowe = idNowe2;
}

MojaKlasa::MojaKlasa(MojaKlasa &mk) {
	printf("Konstrutor kopiujacy MojaKlasa\n");
	ile = mk.ile;
	emails = mk.emails;
	nast = mk.nast;
	emails = new char*[ile];
	idNowe = mk.idNowe;
	for (int i = 0; i < ile; i++) {
		emails[i] = new char[100];
		strcpy(emails[i], mk.emails[i]);
	}
}

MojaKlasa::~MojaKlasa() {
	printf("Wywolano destruktor moja klasa id %d\n", idNowe);
	for (int i = 0; i < ile; i++) {
		printf("Destruktor kasuje email %s\n", emails[i]);
		delete[] emails[i];
	}
	delete[] emails;
	ile = 0;
	emails = NULL;
	if (nast != NULL) {
		delete nast;
	}
	nast = NULL;
}

//metoda szukaj

MojaKlasa* MojaKlasa::szukaj(int szukaneIdNowe) {
	if (idNowe == szukaneIdNowe) {
		return this;
	}
	else if (nast != NULL) {
		return nast->szukaj(szukaneIdNowe);
	}
	else
		return NULL; //jesli tu dojdzie to znaczy, ze nie znalazl
}

void MojaKlasa::wypisz() {
	printf("Grupa: %d\n", idNowe);
	for (int i = 0; i < ile; i++) {
		printf("%s\n", emails[i]);
	}
}

//moj kod:

class Wykladowca {
	MojaKlasa *glowa;
	int id;
public:
	Wykladowca(); //konstruktor domyslny
	Wykladowca(const char nazwaPliku[ILE]); //konstruktor z argumentem
	Wykladowca(Wykladowca &wykladowca2); //konstruktor kopiujacy
	~Wykladowca();
	void dodaj_klase(const char nazwaPliku[ILE]);
	void wypisz();
	void setId(int id2);
	MojaKlasa* szukaj(int szukaneIdNowe2);
};

void Wykladowca::setId(int id2) {
	id = id2;
}

Wykladowca::Wykladowca() {
	glowa = NULL;
}

Wykladowca::Wykladowca(const char nazwaPliku[ILE]) {
	int idKlasy2;
	int iloscStudentow = 0;
	char *tab[ILE];
	for (int i = 0; i < ILE; i++) tab[i] = new char[100];
	FILE *f;
	f = fopen(nazwaPliku, "r");
	if (f == NULL) {
		printf("Brak pliku o tej nazwie.\n");
		glowa = NULL;
	}
	else {
		fscanf(f, "%d", &idKlasy2);
		int x = fscanf(f, "%s", tab[iloscStudentow]);
		while (x > 0) {
			iloscStudentow++;
			x = fscanf(f, "%s", tab[iloscStudentow]);
		}
		fclose(f);
		glowa = new MojaKlasa(iloscStudentow, idKlasy2);
		glowa->nast = NULL;
		for (int i = 0; i < iloscStudentow; i++) {
			glowa->setemail(tab[i], i);

		}
	}
	for (int i = 0; i < ILE; i++) {
		delete[] tab[i];
	}
}

Wykladowca::Wykladowca(Wykladowca &wykladowca2) {
	if (wykladowca2.glowa == NULL) {
		glowa = NULL;
	}
	else {
		MojaKlasa *temp2 = wykladowca2.glowa;
		MojaKlasa *poprzedni = NULL;
		while (temp2 != NULL) {
			MojaKlasa *nowy = new MojaKlasa(*temp2); //wywolanie konstrutora kpiujacego MojaKlasa
			nowy->nast = NULL;
			if (poprzedni == NULL) {
				glowa = nowy;
			}
			else {
				poprzedni->nast = nowy;
			}
			poprzedni = nowy;
			temp2 = temp2->nast;
		}
	}
}

//destruktor:

Wykladowca::~Wykladowca() {
	printf("Wywolano destruktor wykladowcy %d", id);
	delete glowa;
	/*while (glowa != NULL) {
		MojaKlasa *usun = glowa;
		glowa = glowa->nast;
		delete usun;
	}*/
}

void Wykladowca::dodaj_klase(const char nazwaPliku[ILE]) {
	int idKlasy;
	int iloscStudentow = 0;
	char *tab[ILE];
	for (int i = 0; i < ILE; i++) tab[i] = new char[100];
	FILE *f;
	f = fopen(nazwaPliku, "r");
	if (f == NULL) {
		printf("Brak pliku o tej nazwie.\n");
	}
	else {
		fscanf(f, "%d", &idKlasy);
		int x = fscanf(f, "%s", tab[iloscStudentow]);
		while (x > 0) {
			iloscStudentow++;
			x = fscanf(f, "%s", tab[iloscStudentow]);
		}
		fclose(f);
		MojaKlasa *nowyEl;
		nowyEl = new MojaKlasa(iloscStudentow, idKlasy);
		nowyEl->nast = glowa;
		glowa = nowyEl;
		for (int i = 0; i < iloscStudentow; i++) {
			nowyEl->setemail(tab[i], i);
		}
	}
	for (int i = 0; i < ILE; i++) {
		delete[] tab[i];
	}
}

void Wykladowca::wypisz() {
	printf("Grupy wykladowcy %d\n", id);
	if (glowa == NULL) {
		printf("Wykladowca nie posiada zadnych grup\n");
	}
	MojaKlasa *temp = glowa;
	while (temp != NULL) {
		temp->wypisz();
		temp = temp->nast;
	}
}

//metoda szukaj

MojaKlasa* Wykladowca::szukaj(int szukaneIdNowe2) {
	MojaKlasa* znalezione = glowa->szukaj(szukaneIdNowe2);
	if (znalezione == NULL) {
		printf("Wykladowca nie ma klasy o tym numerze ID %d\n", szukaneIdNowe2);
	}
	else {
		printf("Wykladowca znalazl klase o szukanym ID: %d\n", szukaneIdNowe2);
	}
	return znalezione;
}

int main() {
	printf("Program...Autor...\n");

	MojaKlasa* znalezione1, *znalezione2, *znalezione3;

	MojaKlasa MK(1, 10);
	MK.setemail("k.trojanowski@uksw.edu.pl", 0);
	MojaKlasa MK1(2, 11);
	MK1.setemail("p.akakakakaka@uksw.edu/pl", 0);
	MK1.setemail("w.sjsjs@kk.pl", 1);
	MojaKlasa MK3(2, 12);
	MK3.setemail("kkk@www.pl", 0);
	MK3.setemail("akakaka@kk.pl", 1);
	MojaKlasa MK2(MK);
	printf("%s\n", MK2.getemail(0));
	MK.setemail("m.mikolajczyk@uksw.edu.pl", 0);
	printf("%s\n", MK2.getemail(0));

	Wykladowca *wykladowca1 = new Wykladowca;
	Wykladowca *wykladowca2 = new Wykladowca("email.txt");
	Wykladowca *wykladowca3 = new Wykladowca(*wykladowca2);

	wykladowca1->setId(1);
	wykladowca2->setId(2);
	wykladowca3->setId(3);

	wykladowca1->dodaj_klase("email.txt");
	wykladowca1->dodaj_klase("email2.txt");
	wykladowca1->dodaj_klase("email3.txt");
	wykladowca1->dodaj_klase("email4.txt");
	wykladowca1->dodaj_klase("email5.txt");
	wykladowca2->dodaj_klase("email2.txt");

	wykladowca1->wypisz();
	wykladowca2->wypisz();
	wykladowca3->wypisz();

	int szukaneIdNowe = 5;

	znalezione1 = wykladowca1->szukaj(szukaneIdNowe);
	znalezione2 = wykladowca2->szukaj(szukaneIdNowe);
	znalezione3 = wykladowca3->szukaj(szukaneIdNowe);

	if (znalezione1 != NULL) {
		printf("Wykladowca1 znalazl: \n");
		znalezione1->wypisz();
	}
	else{
		printf("Wykladowca1 nie znalazl podanego id %d\n", szukaneIdNowe);
	}

	if (znalezione2 != NULL) {
		printf("Wykladowca2 znalazl: \n");
		znalezione2->wypisz();
	}
	else {
		printf("Wykladowca2 nie znalazl podanego id %d\n", szukaneIdNowe);
	}

	if (znalezione3 != NULL) {
		printf("Wykladowca3 znalazl: \n");
		znalezione3->wypisz();
	}
	else {
		printf("Wykladowca3 nie znalazl podanego id %d\n", szukaneIdNowe);
	}



	delete wykladowca1;
	delete wykladowca2;
	delete wykladowca3;

	printf("Koniec programu\n");
	return 0;
}