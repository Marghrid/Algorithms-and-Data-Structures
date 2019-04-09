#include <stdio.h>

int main()
{
	int n = 0, num_digitos = 0, soma = 0;

	printf("\n");

	while (n <= 0)
	{
		printf("\nIntroduza um inteiro positivo: ");
		scanf("%d", &n);
	}

	printf("\nO numero %d ", n);

	while (n!= 0)
	{
		soma += n%10;
		++num_digitos;
		n = n/10;
	}

	printf("tem %d digitos e a sua soma e' %d.\n\n", num_digitos, soma);

	return 0;
}