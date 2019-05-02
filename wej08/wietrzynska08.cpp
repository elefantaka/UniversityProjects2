#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

class trapeze {
	double a, b, h; //wymiary trapezu
	double xA, yA; //polozenie lewego dolnego pkt trapezu, pkt A
public:
	void set_locationAndSize(double at, double bt, double ht, double xAt, double yAt);
	void write();
	void transformation(double n);
};

//pierwsza metoda

void trapeze::set_locationAndSize(double at, double bt, double ht, double xAt, double yAt) {
	//kontrola poprawnosci danych
	if (at < 0)
		at = (-at);
	if (bt < 0)
		bt = (-bt);
	if (ht < 0)
		ht = (-ht);
	//nowy trapez
	a = at;
	b = bt;
	h = ht;
	xA = xAt;
	yA = yAt;
}

//druga metoda

void trapeze::write() {
	//przeliczanie polozenia wierzcholkow
	double temp, c, xB, yB, xC, yC, xD, yD;
	temp = (a - b) / 2;
	c = sqrt(h*h + temp * temp);
	xB = xA + temp;
	yB = yA + h;
	xC = xB + b;
	yC = yB;
	xD = xA + a;
	yD = yA;
	printf("Dlugosci bokow:\n");
	printf("Podstawa gorna: %.2lf\n podstawa dolna: %.2lf\n ramie: %.2lf\n wysokosc: %.2lf\n", b, a, c, h);
	printf("Wspolrzedne punktow:\n");
	printf("A(%.2lf,%.2lf)  B(%.2lf,%.2lf)  C(%.2lf,%.2lf)  D(%.2lf,%.2lf)\n", xA, yA, xB, yB, xC, yC, xD, yD);
}

//trzecia metoda

void trapeze::transformation(double n) {
	double temp1, temp2;
	double xD = xA + a;
	if (xD < n) {
		temp1 = n - xD;
		xD += 2 * temp1;
		xA = xD;
	}
	else if (xD > n) {
		temp2 = xD - n;
		xD -= 2 * temp2;
		xA = xD;
	}
	else {
		xA = xD;
	}
}

int main() {
	printf("Program...Autor...\n");

	trapeze object; //w zadaniu obiekt - trapez
	double a, b, h, xA, yA;

	printf("Podaj podstawe gorna.\n");
	scanf("%lf", &b);
	printf("Podaj podstawe dolna.\n");
	scanf("%lf", &a);
	printf("Podaj wysokosc.\n");
	scanf("%lf", &h);
	printf("Podaj xA.\n");
	scanf("%lf", &xA);
	printf("Podaj yA.\n");
	scanf("%lf", &yA);

	object.set_locationAndSize(a, b, h, xA, yA);

	object.write();

	double n;
	printf("Podaj argument dla symetrii osiowej\n");
	scanf("%lf", &n);

	object.transformation(n);

	object.write();

	object.transformation(n);

	object.write();

	printf("Koniec programu.\n");
	return 0;
}