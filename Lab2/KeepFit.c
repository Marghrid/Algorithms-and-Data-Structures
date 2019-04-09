#include <stdio.h>

float IMC(float peso, float altura)
{
	return peso/(altura*altura);
}

char* Categoria(float imc)
{
	return imc < 19 ? "Magro" : (imc > 30. ? "Excesso de peso" : "Normal");
}

float PesoMinimo(float altura)
{
	return 19 * (altura*altura);
}

float PesoMaximo(float altura)
{
	return 25 * (altura*altura);
}

int main()
{
	float altura, peso;
	printf("\n \nIntroduza o seu peso em kilogramas, seguido da sual altura, em metros:  ");
	scanf("%f %f", &peso, &altura);

	printf("\nO seu IMC e' %g e insere-se na categoria %s. \nPara estar na categoria 'Normal', deve manter o seu peso entre %g e %g Kg.\n\n", IMC(peso, altura), Categoria(IMC(peso, altura)), PesoMinimo(altura), PesoMaximo(altura));
	
	return 0;	
}