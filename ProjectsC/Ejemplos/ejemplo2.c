#include <stdio.h>

int main()
{
	int *ptra;
	int a;
	a=100;
	ptra=&a;

	printf("Valor del puntero %d\n", *ptra);
	printf("Valor de la variable %d\n", a);
	printf("DIrección de memoria puntero %p\n", ptra);
	printf("Dirección de memoria %p\n", &a);

	getchar();
	return(0);
}