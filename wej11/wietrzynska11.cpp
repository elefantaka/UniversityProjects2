#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstring>
#include <string>


#define ILE 60;

using namespace std;

class SilnikSamochodowy {
protected:
	int moc;
	int wymiary;
public:
	SilnikSamochodowy *nast;
public:
	SilnikSamochodowy();
	SilnikSamochodowy(int mocS, int wymiaryS);
	SilnikSamochodowy(SilnikSamochodowy &silnikS);
	~SilnikSamochodowy();
	int getMoc(); 
	int getWymiary();
	void setMoc(int nowaMoc);
	void setWymiary(int nowyWymiar);
	void wypisz();
};

SilnikSamochodowy::SilnikSamochodowy() {
	printf("Konstruktor domyslny SilnikSamochodowy.\n");
	moc = 1;
	wymiary = 1;
	nast = NULL;
}

SilnikSamochodowy::SilnikSamochodowy(int mocS, int wymiaryS) {
	printf("Konstruktor argumentowy SilnikSamochodowy.\n");
	moc = mocS;
	wymiary = wymiaryS;
	nast = NULL;
}

SilnikSamochodowy::SilnikSamochodowy(SilnikSamochodowy &silnikS) {
	printf("Konstruktor kopiujacy SilnikSamochodowy.\n");
	moc = silnikS.moc;
	wymiary = silnikS.wymiary;
	if (nast != NULL) {
		nast = new SilnikSamochodowy(*nast);
	}
	else {
		nast = NULL;
	}
}

SilnikSamochodowy::~SilnikSamochodowy() {
	printf("Destruktor SilnikSamochodowy\n");
	if (nast != NULL) {
		delete nast;
	}
}

int SilnikSamochodowy::getMoc() {
	return moc;
}

int SilnikSamochodowy::getWymiary() {
	return wymiary;
}

void SilnikSamochodowy::setMoc(int nowaMoc) {
	moc = nowaMoc;
}

void SilnikSamochodowy::setWymiary(int nowyWymiar) {
	wymiary = nowyWymiar;
}

void SilnikSamochodowy::wypisz() {
	printf("SilnikSamochodowy: Moc = %d, Wymiary = %d\n", moc, wymiary);
	if (nast != NULL) {
		nast->wypisz();
	}
	else {
		printf("NULL\n");
	}
}

class Samochod {
protected:
	int cena;
	string rodzajSilnika; 
public:
	Samochod *nast;
public:
	Samochod();
	Samochod(int cenaS, string rodzajSilnikaS);
	Samochod(Samochod &samochod);
	~Samochod();
	int getCena();
	string getRodzajSilnika();
	void setCena(int nowaCena);
	void setRodzajSilnika(string nowyRodzajSilnika);
	void wypisz();
};

Samochod::Samochod() {
	printf("Konstruktor domyslny Samochod\n");
	cena = 1;
	rodzajSilnika = "spalinowy";
	nast = NULL;
}

Samochod::Samochod(int cenaS, string rodzajSilnikaS) {
	printf("Konstruktor argumentowy Samochod\n");
	cena = cenaS;
	rodzajSilnika = rodzajSilnikaS;
	nast = NULL;
}

Samochod::Samochod(Samochod &samochod) {
	printf("Konstruktor kopiujacy Samochod\n");
	cena = samochod.cena;
	rodzajSilnika = samochod.rodzajSilnika;
	if (nast != NULL) {
		nast = new Samochod(*nast);
	}
	else {
		nast = NULL;
	}
}

Samochod::~Samochod() {
	printf("Destruktor Samochod\n");
	if (nast != NULL) {
		delete nast;
	}
}

int Samochod::getCena() {
	return cena;
}

string Samochod::getRodzajSilnika() {
	return rodzajSilnika;
}

void Samochod::setCena(int nowaCena) {
	cena = nowaCena;
}

void Samochod::setRodzajSilnika(string nowyRodzajSilnika) {
	rodzajSilnika = nowyRodzajSilnika;
}

void Samochod::wypisz() {
	printf("Samochod: Cena = %d, Rodzaj silnika = %s\n", cena, rodzajSilnika.c_str());
	if (nast != NULL) {
		nast->wypisz();
	}
	else {
		printf("NULL\n");
	}
}

class UrzadzenieOptyczne {
protected:
	int zoom;
	int waga;
public:
	UrzadzenieOptyczne *nast;
public:
	UrzadzenieOptyczne();
	UrzadzenieOptyczne(int zoomU, int wagaU);
	UrzadzenieOptyczne(UrzadzenieOptyczne &urzadzenie);
	~UrzadzenieOptyczne();
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

UrzadzenieOptyczne::UrzadzenieOptyczne(UrzadzenieOptyczne &urzadzenie) {
	printf("Konstruktor kopiujacy UrzadzenieOptyczne\n");
	zoom = urzadzenie.zoom;
	waga = urzadzenie.waga;
	if (nast != NULL) {
		nast = new UrzadzenieOptyczne(*nast);
	}
	else {
		nast = NULL;
	}
}

UrzadzenieOptyczne::~UrzadzenieOptyczne() {
	printf("Destruktor UrzadzenieOptyczne\n");
	if (nast != NULL) {
		delete nast;
	}
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

class OsobaNaUczelni {
protected:
	string imie;
	string nazwisko;
	string adresEmail;
public:
	OsobaNaUczelni *nast;
public:
	OsobaNaUczelni();
	OsobaNaUczelni(string imieO, string nazwiskoO, string adresEmailO);
	OsobaNaUczelni(OsobaNaUczelni &osoba);
	~OsobaNaUczelni();
	string getImie();
	string getNazwisko();
	string getAdresEmail();
	void setImie(string noweImie);
	void setNazwisko(string noweNazwisko);
	void setAdresEmail(string nowyAdresEmail);
	void wypisz();
};

OsobaNaUczelni::OsobaNaUczelni() {
	printf("Konstruktor domyslny OsobaNaUczelni\n");
	imie = "Jan";
	nazwisko = "Kowalski";
	adresEmail = "JanKowalski@gmail.com";
	nast = NULL;
}

OsobaNaUczelni::OsobaNaUczelni(string imieO, string nazwiskoO, string adresEmailO) {
	printf("Konstruktor argumentowy OsobaNaUczelni\n");
	imie = imieO;
	nazwisko = nazwiskoO;
	adresEmail = adresEmailO;
	nast = NULL;
}

OsobaNaUczelni::OsobaNaUczelni(OsobaNaUczelni &osoba) {
	printf("Konstruktor kopiujacy OsobaNaUczelni\n");
	imie = osoba.imie;
	nazwisko = osoba.nazwisko;
	adresEmail = osoba.adresEmail;
	if (nast != NULL) {
		nast = new OsobaNaUczelni (*nast);
	}
	else {
		nast = NULL;
	}
}

OsobaNaUczelni::~OsobaNaUczelni() {
	printf("Destruktor OsobaNaUczelni\n");
	if (nast != NULL) {
		delete nast;
	}
}

string OsobaNaUczelni::getImie() {
	return imie;
}

string OsobaNaUczelni::getNazwisko() {
	return nazwisko;
}

string OsobaNaUczelni::getAdresEmail() {
	return adresEmail;
}

void OsobaNaUczelni::setImie(string noweImie) {
	imie = noweImie;
}

void OsobaNaUczelni::setNazwisko(string noweNazwisko) {
	nazwisko = noweNazwisko;
}

void OsobaNaUczelni::setAdresEmail(string nowyAdresEmail) {
	adresEmail = nowyAdresEmail;
}

void OsobaNaUczelni::wypisz() {
	printf("OsobaNaUczelni: Imie = %s, Nazwisko = %s, AdresEmail = %s\n", imie.c_str(), nazwisko.c_str(), adresEmail.c_str());
	if (nast != NULL) {
		nast->wypisz();
	}
	else {
		printf("NULL\n");
	}
}

int main() {
	printf("Program... Autor...\n\n");

	SilnikSamochodowy *lista1; //glowa

	SilnikSamochodowy *silnik1 = new SilnikSamochodowy();
	SilnikSamochodowy *silnik2 = new SilnikSamochodowy();
	SilnikSamochodowy *silnik3 = new SilnikSamochodowy();
	SilnikSamochodowy *silnik4 = new SilnikSamochodowy();
	SilnikSamochodowy *silnik5 = new SilnikSamochodowy();

	lista1 = silnik1;

	silnik1->nast = silnik2;
	silnik2->nast = silnik3;
	silnik3->nast = silnik4;
	silnik4->nast = silnik5;
	silnik5->nast = NULL;

	printf("Lista1\n");

	lista1->wypisz();

	Samochod *lista2;

	Samochod *samochod1 = new Samochod();
	Samochod *samochod2 = new Samochod();
	Samochod *samochod3 = new Samochod();
	Samochod *samochod4 = new Samochod();
	Samochod *samochod5 = new Samochod();

	lista2 = samochod1;

	samochod1->nast = samochod2;
	samochod2->nast = samochod3;
	samochod3->nast = samochod4;
	samochod4->nast = samochod5;
	samochod5->nast = NULL;

	printf("Lista2\n");

	lista2->wypisz();

	UrzadzenieOptyczne *lista3;

	UrzadzenieOptyczne *urzadzenie1 = new UrzadzenieOptyczne();
	UrzadzenieOptyczne *urzadzenie2 = new UrzadzenieOptyczne();
	UrzadzenieOptyczne *urzadzenie3 = new UrzadzenieOptyczne();
	UrzadzenieOptyczne *urzadzenie4 = new UrzadzenieOptyczne();
	UrzadzenieOptyczne *urzadzenie5 = new UrzadzenieOptyczne();

	lista3 = urzadzenie1;

	urzadzenie1->nast = urzadzenie2;
	urzadzenie2->nast = urzadzenie3;
	urzadzenie3->nast = urzadzenie4;
	urzadzenie4->nast = urzadzenie5;
	urzadzenie5->nast = NULL;

	printf("Lista3\n");

	lista3->wypisz();

	OsobaNaUczelni *lista4;

	OsobaNaUczelni *osoba1 = new OsobaNaUczelni();
	OsobaNaUczelni *osoba2 = new OsobaNaUczelni();
	OsobaNaUczelni *osoba3 = new OsobaNaUczelni();
	OsobaNaUczelni *osoba4 = new OsobaNaUczelni();
	OsobaNaUczelni *osoba5 = new OsobaNaUczelni();

	lista4 = osoba1;

	osoba1->nast = osoba2;
	osoba2->nast = osoba3;
	osoba3->nast = osoba4;
	osoba4->nast = osoba5;
	osoba5->nast = NULL;

	printf("Lista4\n");

	lista4->wypisz();

	delete lista1;
	delete lista2;
	delete lista3;
	delete lista4;

	printf("\nKoniec programu.\n");
	return 0;
}
