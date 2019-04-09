#include <stdio.h>
#include <string.h>
#include "Lab3.h"

int main()
{
	int comp, i;
	char palavra[MAX];
	puts("\n\nEscreva uma palavra:");
	scanf("%s", palavra);
	
	comp = strlen(palavra);
	for (i = 0; i < comp/2; i++)
		if (palavra[i] != palavra[comp-1-i])
		{
			printf("\nA palavra nao e uma capicua.\n");
			return 0;
		}
	printf("\nParabens! Introduziu uma capicua!!\n\n");
	return 0;
}