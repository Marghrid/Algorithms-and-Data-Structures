#include <stdio.h>

void
maiusculas(char s[])
{
	int i;
	for (i=0; s[i]!= '\0'; ++i)
		if ((s[i] <= 'z') && (s[i] >= 'a'))
			s[i] -= 32;	
}

int
main()
{
	char s[MAX];
	puts("\n\nEscreva algo:");
	leLinha(s);
	maiusculas(s);
	printf("\n\nEi-lo em maiusculas apenas!\n%s\n",s);
	return 0;
}