#include <stdio.h>
#include "matriz.h"
int
main()
{
	int atletas, sessoes;
	float tempos[DIM1][DIM2];
	
	puts("\nQuantos atletas treina, vossa excelencia?");
	scanf("%d", &atletas);
	puts("\nE quantas sessoes faz cada um?");
	scanf("%d", &sessoes);
	
	leMatriz(tempos, atletas, sessoes);
	escreveMediaColunas(tempos, atletas, sessoes);
	escreveMinimoLinhas(tempos, atletas, sessoes);
	
	return 0;
}