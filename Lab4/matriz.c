#include "matriz.h"
#include <stdio.h>
void
leMatriz(float tempos[][DIM2], int atletas, int sessoes)
{
	int atleta, sessao;
	for (atleta=0; atleta<atletas; ++atleta)
	{
		printf("\nAtleta %d:\n", atleta+1);
		for(sessao=0; sessao<sessoes; ++sessao)
		{
			printf("\t%da sessao:  ", sessao + 1);
			scanf("%f", &tempos[atleta][sessao]);
		}
	}
}

void
escreveMediaColunas(float tempos[][DIM2], int atletas, int sessoes)
{
	printf("\nAs medias foram as seguintes:\n\n");
	int i;
	for(i=0; i<sessoes; i++)
	{
		int k;
		float media=0;
		for(k=0; k<atletas; k++)
		{
			media+=tempos[k][i];
			//printf("%g\n", tempos[k][i]);
		}
		media/=(float)atletas;
		printf("\t---%da Sessao:\t%g segundos.\n", i+1, media);
	}
}

void
escreveMinimoLinhas(float tempos[][DIM2], int atletas, int sessoes)
{
	int i, k, indMenorTempo;
	float t;
	
	printf("\nOs melhores tempos foram os seguintes: \n\n");
	for(i=0; i<atletas; i++)
	{
		t=tempos[i][0];
		indMenorTempo=0;	
		for(k=1; k<sessoes; k++)
		{
			if(t>tempos[i][k])
			{
				t=tempos[i][k];
				indMenorTempo=k;
			}
		}
		printf("%do Atleta: %da. sessao : %g segundos\n", i+1, indMenorTempo+1, t);
	}
}

