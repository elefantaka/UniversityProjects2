#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstring>
#include <string>


#define ILE 60;

using namespace std;

class UrzadzenieOptyczne {
protected:
	int zoom;
	int waga;
public:
	UrzadzenieOptyczne *nast;
public:
	UrzadzenieOptyczne();
	UrzadzenieOptyczne(int zoomU, int wagaU);
	UrzadzenieOptyczne(const UrzadzenieOptyczne &urzadzenie);
	~UrzadzenieOptyczne();
	UrzadzenieOptyczne &operator+=(UrzadzenieOptyczne &obiekt2); //operator
	int getZoom();
	int getWaga();
	void setZoom(int nowyZoom);
	void setWaga(int nowaWaga);
	void wypisz();
};

UrzadzenieOptyczne::UrzadzenieOptyczne() {
	printf("Konstruktor domyslny UrzadzenieOptyczne\n");
	zoom = 1;
	waga = 1;
	nast = NULL;
}

UrzadzenieOptyczne::UrzadzenieOptyczne(int zoomU, int wagaU) {
	printf("Konstruktor argumentowy UrzadzenieOptyczne\n");
	zoom = zoomU;
	waga = wagaU;
	nast = NULL;
}

UrzadzenieOptyczne::UrzadzenieOptyczne(const UrzadzenieOptyczne &urzadzenie) {
	printf("Konstruktor kopiujacy UrzadzenieOptyczne\n");
	zoom = urzadzenie.zoom;
	waga = urzadzenie.waga;
	if (nast != NULL) {
		nast = new UrzadzenieOptyczne(*nast);
	}
	else {
		nast = NULL;
	}
	this->wypisz();
}

UrzadzenieOptyczne::~UrzadzenieOptyczne() {
	printf("Destruktor UrzadzenieOptyczne\n");
	if (nast != NULL) {
		delete nast;
	}
}

//operator:

UrzadzenieOptyczne &UrzadzenieOptyczne::operator+=(UrzadzenieOptyczne &obiekt2) {
	zoom += obiekt2.zoom;
	waga += obiekt2.waga;
	return *this;
}

int UrzadzenieOptyczne::getZoom() {
	return zoom;
}

int UrzadzenieOptyczne::getWaga() {
	return waga;
}

void UrzadzenieOptyczne::setZoom(int nowyZoom) {
	zoom = nowyZoom;
}

void UrzadzenieOptyczne::setWaga(int nowaWaga) {
	waga = nowaWaga;
}

void UrzadzenieOptyczne::wypisz() {
	printf("UrzadzenieOptyczne: Zoom = %d, Waga = %d\n", zoom, waga);
	if (nast != NULL) {
		nast->wypisz();
	}
	else {
		printf("NULL\n");
	}
}

UrzadzenieOptyczne sumaListy(UrzadzenieOptyczne *glowa) {
	printf("Funkcja sumaListy\n");
	UrzadzenieOptyczne suma(0,0); //domysle urzadzenie optyczne
	UrzadzenieOptyczne *aktualny;
	aktualny = glowa;
	while (aktualny != NULL) {
		suma += *aktualny;
		aktualny = aktualny->nast;
	}
	suma.wypisz();
	return suma;
}

int main() {
	printf("Program... Autor...\n\n");
	
	UrzadzenieOptyczne *lista;

	UrzadzenieOptyczne *urzadzenie1 = new UrzadzenieOptyczne();
	UrzadzenieOptyczne *urzadzenie2 = new UrzadzenieOptyczne();
	UrzadzenieOptyczne *urzadzenie3 = new UrzadzenieOptyczne();
	UrzadzenieOptyczne *urzadzenie4 = new UrzadzenieOptyczne();
	UrzadzenieOptyczne *urzadzenie5 = new UrzadzenieOptyczne();

	lista = urzadzenie1;

	urzadzenie1->wypisz();
	urzadzenie2->wypisz();

	*urzadzenie1 += *urzadzenie2;

	urzadzenie1->wypisz();
	urzadzenie2->wypisz();

	urzadzenie1->nast = urzadzenie2;
	urzadzenie2->nast = urzadzenie3;
	urzadzenie3->nast = urzadzenie4;
	urzadzenie4->nast = urzadzenie5;
	urzadzenie5->nast = NULL;


	printf("Lista:\n");

	lista->wypisz();

	UrzadzenieOptyczne suma = sumaListy(lista);

	suma.wypisz();
	
	delete lista;

	printf("\nKoniec programu.\n");
	return 0;
}
