#include <stdio.h>
#include "Lab3.h"

void
apagaCaracter(char s[], char c)
{
	int i, k=0;
	for (i=0; s[i-1]!= '\0'; ++i)
	{
		if (s[i]==c)
			k++;
		s[i]=s[i-k];
	}	
}

int
main()
{
	char s[MAX];
	puts("\n\nEscreva algo:");
	leLinha(s);
	puts("\nQual o carater que deseja apagar?\n");
	char c = getchar();
	apagaCaracter(s, c);
	printf("\n\n%s\n",s);
	return 0;
}