#pragma once
#include <stdio.h>

typedef struct{
	float x, y;
}complexo;

complexo leComplexo();

complexo somaComplexo(complexo, complexo);

void escreveComplexo(complexo);