#include <stdio.h>

int main()
{
	int idade, num_acidentes;
	float seguro_atual;
	printf("\n\nInsira o valor atual da apolice de seguro, a idade do condutor, e o numero de acidentes registados este ano:  ");
	scanf("%f %d %d", &seguro_atual, &idade, &num_acidentes);
	if (num_acidentes < 5)
	{
		if (idade < 25)
		{
			if (num_acidentes == 0)
				printf ("O valor da apolice para o proximo ano deve ser de %g.", seguro_atual*0.85);
			else if (num_acidentes == 1)
				printf("O valor da apolice para o proximo ano deve ser de %g.", seguro_atual*1.05);
			else if (num_acidentes > 1)
				printf("O valor da apolice para o proximo ano deve ser de %g.", seguro_atual*1.5);
		}

		else
		{
			if (num_acidentes == 0)
				printf ("O valor da apolice para o proximo ano deve ser de %g.", seguro_atual*0.8);
			else if (num_acidentes == 1)
				printf("O valor da apolice para o proximo ano deve ser de %g.", seguro_atual);
			else if (num_acidentes > 1)
				printf("O valor da apolice para o proximo ano deve ser de %g.", seguro_atual*1.3);
		}
	}

	else
		printf("A companhia recusa o seguro para o próximo ano.");

	printf("\n\n");
	return 0;

}