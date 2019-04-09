#include <stdio.h>

int main()
{
	int c;
	int maiusc, minusc, alg, linhas;
	int nova_linha;

	c = getchar();
	while (c != EOF)
	{
		if (c >= 'A' && c <= 'Z')
			++ maiusc;
		else if (c >= 'a' && c <= 'z')
			++ minusc;
		else if (c >= '0' && c <= '9')
			++ alg;
		else if (c == '\n')
			nova_linha = 1;
		if (nova_linha)
			if (c != '\n')
			{
				nova_linha = 0;
				++ linhas;
			}
		c = getchar();
	}
	printf ("\n\nForam encontrados:\n\t%d letras maiusculas,\n\t%d letras minusculas,\n\t%d algarismos,\n\te %d linhas nao vazias.\n", maiusc, minusc, alg, linhas);
	return 0;
}