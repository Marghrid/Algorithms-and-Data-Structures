#include <stdio.h>

void quadrado(int lado)
{
	int i, j;
	printf("\n\n");
	for (i = 0; i < lado; ++i)
	{
		for (j = 0; j < lado; ++j)
			printf ("%2d  ", i+j+1);
		printf ("\n");
	}
	printf("\n");
} 

int main()
{
	int N;
	printf("Insira um numero inteiro maior do que 1: ");
	scanf("%d", &N);

	quadrado(N);

	return 0;
}