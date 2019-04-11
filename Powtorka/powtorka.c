#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define A 4 //rozmiar tablicy
#define B 6 //rozmiar tablicy

int main()
{
	printf("Program...Autor...\n");
	srand(time(NULL));
	int tab[A][B];
	int tab1[A] = 1000;
	int tab2[B] = 0;
	for (int i = 0; i < A; i++)
	{
		for (int j = 0; j < B; j++)
		{
			tab[i][j] = rand() % 1000;
		}
	}
	for (int i = 0; i < A; i++)
	{
		if (tab[i][B] < tab1[i])
		{
			tab1[i] = tab[i][B];
		}
	}
	for (int j = 0; j < B; j++)
	{
		if (tab[A][j] > max)
		{
			max = tab[A][j]; 
		}
	}
}