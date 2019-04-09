#include <stdio.h>

float media (int n)
{
	float num;
	printf("\nIntroduza um numero: ");
	scanf("%f", &num);
	num = num/(float)n;
	return num;
}

int main()
{
	int n, i;
	float med = 0;
	printf("\n \nQuantos numeros vai introduzir para calcular a media?\n");
	scanf("%d", &n);
	for (i=0; i<n; i++)
		med += media(n);
	printf("A media dos %d numeros e %g.\n\n", n, med);
	return 0;
}