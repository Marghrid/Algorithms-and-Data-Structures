#include <stdio.h>
#include "Lab3.h"

int
main()
{
	char s[MAX];
	puts("\nIntroduza uma linha de texto.")
	printf("O que escreveu tinha %d carateres.\n", leLinha(s));
	printf("%s",s);
	return 0;
}