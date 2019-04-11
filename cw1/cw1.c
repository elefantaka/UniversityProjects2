#include <stdio.h>

struct Osoba
{
	char imie[32];
	int wiek;
	int punkty;
};

void dodajPkt(struct Osoba* os, int nowePkt)
{
	(*os).punkty = (*os).punkty + nowePkt;
}

void drukujOs(struct Osoba os)
{
	printf("%s %d %d\n", os.imie, os.wiek, os.punkty);
}

int main()
{
	struct Osoba os1;
	strcpy(os1.imie, "Ala");
	os1.wiek = 7;
	os1.punkty = 200;
	struct Osoba os2;
	strcpy(os2.imie, "Zosia");
	os2.wiek = 7;
	os2.punkty = 250;
	dodajPkt(&os2, 10);
	drukujOs(os1);
	drukujOs(os2);
}