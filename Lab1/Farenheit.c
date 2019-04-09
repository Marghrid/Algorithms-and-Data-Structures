#include <stdio.h>

/* Conversao Fahrenheit-Celsius */

#define INFERIOR 0
#define SUPERIOR 200
#define PASSO 20

int main ()
{

  int fahr, celsius;

  fahr = INFERIOR;
  while (fahr <= SUPERIOR) 
  {
    celsius = 5 * (fahr-32) / 9;
    printf("%d\t%d\n", fahr, celsius);
    fahr = fahr + PASSO;
  }
  return 0;
}