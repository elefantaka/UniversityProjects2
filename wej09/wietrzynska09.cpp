#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstring>

#define ILE 60

using namespace std;

class MojaKlasa {
	char **emails; //tablica napisow, tablica emaili
	int ile;
	MojaKlasa *nast;  //pole nast
public:
	MojaKlasa(int x); //konstruktor z argumentem
	MojaKlasa(MojaKlasa& mk);	// konstruktor kopiuj¹cy
	~MojaKlasa();
	void setemail(const char* adres, int idx) { strcpy(emails[idx], adres); }
	char* getemail(int idx) { return emails[idx]; }
	friend class Wykladowca; //klasa wykladowca bedzie zaprzyjazniona wiec moze korzystac z pol prywatnych MojaKlasa
};

MojaKlasa::MojaKlasa(int x) {
	emails = new char*[ile = x];
	for (int i = 0; i < ile; i++) emails[i] = new char[100];
	nast = NULL;
}

MojaKlasa::MojaKlasa(MojaKlasa &mk) {  
	printf("Konstrutor kopiujacy MojaKlasa\n");
	ile = mk.ile;
	emails = mk.emails;
	nast = mk.nast;   
	emails = new char*[ile];  
	for (int i = 0; i < ile; i++) {
		emails[i] = new char[100];
		strcpy(emails[i], mk.emails[i]);
	}
}

MojaKlasa::~MojaKlasa() {
	printf("Wywolano destruktor moja klasa\n");
	for (int i = 0; i < ile; i++) {
		printf("Destruktor kasuje email %s\n", emails[i]);
		delete[] emails[i];
	}
	delete[] emails;
	ile = 0;
	emails = NULL;
	nast = NULL;
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
};

void Wykladowca::setId(int id2) {
	id = id2;
}

Wykladowca::Wykladowca() {
	glowa = NULL;
}

Wykladowca::Wykladowca(const char nazwaPliku[ILE]) {
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
		int x = fscanf(f, "%s", tab[iloscStudentow]);
		while (x > 0) {
			iloscStudentow++;
			x = fscanf(f, "%s", tab[iloscStudentow]);
		}
		fclose(f);
		glowa = new MojaKlasa(iloscStudentow);
		glowa->nast = NULL;
		for (int i = 0; i < iloscStudentow; i++) {
			glowa->setemail(tab[i], i);

		}
	}
	for (int i = 0; i < ILE; i++){
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
	while (glowa != NULL) {
		MojaKlasa *usun = glowa;
		glowa = glowa->nast;
		delete usun;
	}
}

void Wykladowca::dodaj_klase(const char nazwaPliku[ILE]) {
	int iloscStudentow = 0;
	char *tab[ILE];
	for (int i = 0; i < ILE; i++) tab[i] = new char[100];
	FILE *f;
	f = fopen(nazwaPliku, "r");
	if (f == NULL) {
		printf("Brak pliku o tej nazwie.\n");
	}
	else {
		int x = fscanf(f, "%s", tab[iloscStudentow]);
		while (x > 0) {
			iloscStudentow++;
			x = fscanf(f, "%s", tab[iloscStudentow]);
		}
		fclose(f);
		MojaKlasa *nowyEl;
		nowyEl = new MojaKlasa(iloscStudentow);
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
		printf("Grupa:\n");
		for (int i = 0; i < temp->ile; i++) {
			printf("%s\n", temp->emails[i]);
		}
		temp = temp->nast;
	}
}

int main() {
	printf("Program...Autor...\n");
	
	MojaKlasa MK(1);
	MK.setemail("k.trojanowski@uksw.edu.pl", 0);
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
	wykladowca2->dodaj_klase("email2.txt");

	wykladowca1->wypisz();
	wykladowca2->wypisz();
	wykladowca3->wypisz();

	delete wykladowca1;
	delete wykladowca2;
	delete wykladowca3;

	printf("Koniec programu\n");
	return 0;
}