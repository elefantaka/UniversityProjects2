#include <stdio.h>

#define N 5
#define K 25 

int main()
{
	printf("Program...Autor...\n");
	char A[N][N];
	int kodAscii = 97;
	char *B[K] = {NULL};
	char pom[K]; //tablica pomocnicza do wczytania napisu
	char pom1[K]; //tablica pomocnicza do szyfrowania
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (kodAscii < 113)
			{
				A[j][i] = kodAscii;
			}
			else if (kodAscii == 113)
			{
				A[j][i] = kodAscii + 1;
			}
			else if(kodAscii > 113)
			{
				A[j][i] = kodAscii + 1;
			}
			kodAscii++;
		}
	}
	printf("\nPodaj ciag znakow bez spacji.\n");
	scanf_s("%s", pom, K - 1);
	for (int x = 0; x < K; x++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (pom[x] == A[i][j])
				{
					B[x] = &A[i][j];
				}
			}
		}
	}
	printf("\nTwoj napis:\n");
	for (int i = 0; i < K; i++)
	{
		if (B[i] != NULL)
		{
			printf("%c", *B[i]);
		}
	}
	putchar('\n');
	//szyfrowanie
	for (int j = 0; j < N; j++)
	{
		pom1[j] = A[4][j];  //zapisuje to co jest w 4
	}
	for (int i = 4; i > 0; i--)
	{
		for (int j = 0; j < N; j++)
		{
			A[i][j] = A[i - 1][j];  //szyfruje
		}
	}
	for (int j = 0; j < N; j++)
	{
		A[0][j] = pom1[j];  
	}
	putchar('\n');
	printf("Zaszyfrowany napisz:\n");
	for (int i = 0; i < K; i++)
	{
		if (B[i] != NULL)
		{
			printf("%c", *B[i]);
		}
	}
	putchar('\n');
	//odszyfrowanie
	for (int j = 0; j < N; j++)
	{
		pom1[j] = A[0][j];  
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			A[i][j] = A[i + 1][j];  
		}
	}
	for (int j = 0; j < N; j++)
	{
		A[4][j] = pom1[j];
	}
	printf("\nOdszyfrowany napis:\n");
	for (int i = 0; i < K; i++)
	{
		if (B[i] != NULL)
		{
			printf("%c", *B[i]);
		}
	}
	printf("\n\nKoniec programu.\n");
	return 0;
}

//string tablica charow!!!

//for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			printf("%3c", A[i][j]);
//		}
//		putchar('\n');
//	}

//for (int i = 0; i < N; i++)
//{
//	for (int j = 0; j < N; j++)
//	{
//		printf("%3c", A[i][j]);
//	}
//	putchar('\n');
//}

