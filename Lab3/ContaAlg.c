#include <stdio.h>
#include "Lab3.h"

int
algarismos(char s[])
{
	int i, contador = 0;
	for (i=0; s[i]!= '\0'; ++i)
		if ((s[i] <= '9') && (s[i] >= '0'))
			++contador;
	return contador;
}

int
main()
{
	char s[MAX];
	puts("\n\nEscreva algo:");
	leLinha(s);
	printf("\nA sua string contem %d algarismos.", algarismos (s));
	return 0;
}