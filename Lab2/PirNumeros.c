#include <stdio.h>

void piramide(int altura)
{
	int i, k;
	printf("\n\n");

	for (i = 1; i <= altura; ++i)
	{
		for (k = 0; k < altura - i; ++k)
			printf("   ");
		for (k = 1; k <= i; ++k)
			printf("%2.d ", k);
		for (k = i-1; k>=1; --k)
			printf("%2.d ", k);
		for (k = 0; k < altura - i; ++k)
			printf("   ");
		printf("\n");
	}

	printf("\n");
} 

int main()
{
	int N;
	printf("Insira um numero inteiro maior do que 1: ");
	scanf("%d", &N);

	piramide(N);

	return 0;
}