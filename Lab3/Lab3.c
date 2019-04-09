#include <stdio.h>
#include "Lab3.h"

void leVector(int *v, int n)
{
	int i;

	for(i = 0; i < n; ++i)
		scanf("%d", &v[i]);
}

void escVector (int *v, int n)
{
	int i;

	printf("\n");

	for (i = 0; i < n; ++i)
		printf("\t %d", v[i]);
}

int leLinha(char s[])
{
	int i=0;
	
	do
	{
		s[i]=getchar();
		i++;
	} while((s[i-1]!=10) && (i<MAX));
	
	s[i]='\0';
	return i-1;
}

