#include <stdio.h>
#include <stdlib.h>

int main()
{
	char ch=4;
	int entero=2;
	short shor=4;
	long lon=5;
	long long lonlon=5400;
	float floa=3.4;
	double doubl=1;

	double arreglo[]={1, 2, 3, 4, 5, 6, 7, 8, 9};
	char string[]="Hola";

	int *ptrEntero;
	double *ptrDouble;
	char *ptrChar;
	short *ptrShort;
	long *ptrLong;

	//Varios tipos
	printf("\nTamaño de int %d\n", (int)sizeof(entero));
	printf("Tamaño de char %d\n", (int)sizeof(ch));
	printf("Tamaño de short %d\n", (int)sizeof(shor));
	printf("Tamaño de long %d\n", (int)sizeof(lon));
	printf("Tamaño de long long %d\n", (int)sizeof(lonlon));
	printf("Tamaño de float %d\n", (int)sizeof(floa));
	printf("Tamaño de double %d\n\n", (int)sizeof(doubl));
	
	//Arreglo
	printf("Tamaño de array %d\n", (int)sizeof(arreglo));
	printf("Tamaño de array %d\n\n", (int)sizeof(string));

	//Punteros
	printf("Tamaño de puntero int %d\n", (int)sizeof(ptrEntero));
	printf("Tamaño de puntero double %d\n", (int)sizeof(ptrDouble));
	printf("Tamaño de puntero char %d\n", (int)sizeof(ptrChar));
	printf("Tamaño de puntero short %d\n", (int)sizeof(ptrShort));
	printf("Tamaño de puntero long %d\n\n", (int)sizeof(ptrLong));

	printf("Tamaño del arreglo: %d\n", (int)sizeof(arreglo)/(int)sizeof(double));

	getchar();

	return(0);
}