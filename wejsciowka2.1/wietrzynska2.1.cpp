#include <stdio.h>

#define ILE 5
#define DLUGOSC 20

struct Dane;
int dlugosc(char napis[DLUGOSC]);
int skracanie(struct Dane tab[DLUGOSC]);
void drukujTab(struct Dane tab[DLUGOSC]);

struct Dane
{
	char napis[DLUGOSC];
	int liczba;
};

int dlugosc(char napis[DLUGOSC])
{
	int i = 0;
	while (napis[i] != '\0')
	{
		i++;
	}
	return i;
}

int skracanie(struct Dane tab[DLUGOSC])
{
	int x = 0;
	for (int i = 0; i < DLUGOSC; i++)
	{
		if (tab[i].liczba < dlugosc(tab[i].napis))
		{
			tab[i].napis[tab[i].liczba] = '\0';
			x++;
		}
	}
	return x;
}

void drukujTab(struct Dane tab[DLUGOSC])
{
	for (int i = 0; i < DLUGOSC; i++)
	{
		printf("%d %s\n", tab[i].liczba, tab[i].napis);
	}
}

int main()
{
	printf("Program...Autor...\n\n");
	struct Dane tab[DLUGOSC];
	for (int i = 0; i < DLUGOSC; i++)
	{
		printf("Podaj napis\n");
		char znak = getchar();
		int j = 0;
		while (znak != '\n')
		{
			tab[i].napis[j] = znak;
			j++;
			znak = getchar();
		}
		tab[i].napis[j] = '\0';
		printf("Podaj liczbe\n");
		while (scanf_s("%d", &(tab[i].liczba)) != 1 || getchar() != '\n')
		{
			printf("Popraw dane");
			while (getchar() != '\n')
			{
			}
		}
	}
	int x = skracanie(tab);
	putchar('\n');
	drukujTab(tab);
	printf("\nIlosc skrocen: %d\n", x);
	printf("\nKoniec programu.\n");
	return 0;
}