#include <stdio.h>

int maior (int a, int b, int c)
{
	int maior = a;
	if (b>maior)
		maior = b;
	if (c>maior)
		maior = c;
	return maior;
}

int main()
{
	int a, b, c;
	printf("Estreva três numeros inteiros:\n");
	scanf("%d %d %d", &a, &b, &c);
	printf("O maior dos três é %d", maior(a, b, c));
	return 0;
}