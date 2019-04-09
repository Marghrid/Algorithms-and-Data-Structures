#include <stdio.h>
#include "complexo.h"

complexo leComplexo()
{
	float x, y;
	char signal;
	if(!scanf("%f%c%fi", &x,&signal,&y))
		printf("ERRO\n");
	if(signal=='-')
		y= -y;
	
	complexo tmp={x,y};
	return tmp;
}

void escreveComplexo(complexo z)
{
	if (z.y == -1)
		printf("%g-i", z.x);
	else if(z.y<0)
		printf("%g%gi",z.x,z.y);
	else if(z.y == 0)
		printf("%g", z.x);
	else if (z.y == 1)
		printf("%g+i", z.x);
	else
		printf("%g+%gi",z.x,z.y);
}

complexo somaComplexo(complexo z1, complexo z2)
{
	complexo tmp = {z1.x+z2.x, z1.y+z2.y};
	return tmp;
}