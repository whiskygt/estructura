#include <stdio.h>
#include <stdlib.h>

struct _lista 
{
	char nombre[20];
	char telefono[8];
	struct _lista *next;
};

struct _lista *first, *last;

//Función para mostrar un menú.
void menu()
{
	printf("\nSeleccione una opción:\n\n");
	printf("1. Añadir elementos a la lista.\n");
	printf("2. Borrar elementos de la lista.\n");
	printf("3. Mostrar lista.\n");
	printf("4. Salir.\n");
	printf("Su opción: "); fflush(stdout);
}

//Función para añadir elemento al final.LS
void agregar()
{
	struct _lista *nuevo;

	nuevo = (struct _lista *) malloc (sizeof(struct _lista));
	if(nuevo==NULL)
	{
		printf("Nuevo elemento:\n");
		printf("Nombre: "); fflush(stdout);
		gets(nuevo->nombre);
		printf("Teléfono: "); fflush(stdout);
		gets(nuevo->telefono);

		nuevo->next = NULL;

		if (first==NULL)
		{
			printf("Primer elemento\n");
			first = nuevo;
			last = nuevo;
		}
		else
		{
			last->next = nuevo;
			last = nuevo;
		}
	}
}

void mostrar(struct _lista *first)
{
	struct _lista *aux;
	int i;

	i=0;
	aux=first;

	printf("\nMostrando la lista completa:\n");
	while (aux!=NULL)
	{
		printf("Nombre: %s, Teléfono: %s\n", aux->nombre,aux->telefono);
		aux = aux->next;
		i++;
	}
	if (i==0) printf("\nLa lista está vacía\n");
}

int main()
{
	char opcion;

	first = (struct _lista *) NULL;
	last = (struct _lista *) NULL;

	do
	{
		menu();
		opcion = getchar();
		switch (opcion)
		{
			case '1': 
			{
				printf("\nOpcion seleccionada: %c ", opcion);
				agregar();
			}
				break;
			case '2': ;
				break;
			case '3': mostrar(first);
				break;
			case '4': exit(1);
				break;
			default: printf( "Opción no válida\n" );
				break;
		}
	} while (opcion!='4');
}