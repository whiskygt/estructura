//malloc  : Le mandamos un tamaño. Si no es encontrado devuelve un null o 0.
//calloc  : Tamaño posición, tamaño del vector.
//realloc : Reasigna
//free    : Libera la memoria ocupada.

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *p;
	p= (int*) malloc(sizeof(int) * 100);

	getchar();
	free(p);
	p=NULL;
	
	return(0);
}