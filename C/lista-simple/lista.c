#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"
#include "list.h"

//Muestra un menú
int menu (Lista *lista,int *p);

int menu (Lista *lista,int *p)
{
	int eleccion;
  	
  	printf("Seleccione una opción:\n");
  	
  	if (lista ->size == 0)
  	{
    	printf ("1. Añadir un elemento.\n");
    	printf ("2. Salir.\n");
  	}

  	else if(lista ->size == 1 || *p == 1)
  	{
    	printf ("1. Insertar al inicio de la lista\n");
    	printf ("2. Insertar al final de la lista\n");
      printf ("4. Eliminar al principio de la lista.\n");
    	printf ("6. Mostrar lista.\n");
      printf ("7. Destruir lista.\n");
      printf ("8. Salir\n");
  	}

  	else 
  	{
    	printf ("1. Insertar al inicio de la lista\n");
    	printf ("2. Insertar al final de la lista\n");
      printf ("3. Insertar después de una posición determinada\n");
      printf ("4. Eliminar al principio de la lista.\n");
      printf ("5. Eliminar después de una posición determinada.\n");
    	printf ("6. Mostrar lista.\n");
      printf ("7. Destruir lista.\n");
    	printf ("8. Salir\n");
  	}
  	
  	printf ("\nSu opción: ");
  	scanf ("%d", &eleccion);
  	getchar();
    printf("\n");
  	
  	if(lista->size == 0 && eleccion == 2) eleccion = 8;
  	
  	return eleccion;
}

int main()
{
	char opcion;
	char *dato;
  char lastChance;
	Lista *lista;
	Nodo *actual;

	if ((lista = (Lista *) malloc (sizeof (Lista))) == NULL)
	{
		return -1;
	}
  	
  if ((dato = (char *) malloc (50)) == NULL)
  {
    return -1;	
  }

  actual = NULL;
  opcion = 'o';

  iniciar(lista);
  int pos, p;


	while (opcion!=8)
	{
		opcion=menu(lista, &p);

		switch (opcion)
		{
			case 1:
        //Inserta un elemento al inicio de la lista. 
        printf("\nIngrese el número que desea agregar a la lista: ", opcion);
				
				scanf("%s", dato);
				getchar();

				if(lista->size==0)
				{
          insertarEnListaVacia(lista, dato);
				}
        else
        {
          insertarAlPrincipio(lista, dato);
        }
        printf("\nNúmero %s agregado a la lista.\n\n", dato);
				break;

			case 2:
        //Inserta un elemento al final de la lista.
        if(lista->size==0)
        {
          opcion=7;
        }
        else
        {
          printf("Ingrese un número: ");

          scanf ("%s", dato);
          getchar();
          actual = lista->last;
          insertarAlFinal(lista, actual, dato);
        }

        printf("\nNúmero %s agregado a la lista.\n\n", dato);
				break;

      case 3:
        printf("Ingrese un número: ");

        scanf ("%s", dato);
        getchar();
          
        do
        {
          printf("Ingrese la posición donde desea que sea insertado: ");
          scanf("%d", &pos);
        } while (pos < 1 || pos > lista->size);
        getchar();

        if(lista->size == 1 || pos == lista->size)
        {
          p=1;
          printf("No se puede insertar en esa posición...");
          break;
        }
        insertarLista(lista, dato, pos);
        printf("\nNúmero %s agregado a la lista en la posición %d.\n\n", dato, pos);
        break;

			case 4:
        //Elimina el primer elemento de la lista.
        eliminarAlPrincipio(lista);

        printf("\nSe ha eliminado el dato.\n\n");

        if(lista->size==0)
        {
          printf("La lista ahora está vacía.");
        }
        break;

      case 5: 
        //Elimina el elemento que le sigue a un elemento determinado.
        do
        {
          printf("Ingrese la posición: ");
          scanf("%d", &pos);
        } while (pos < 1 || pos > lista->size);
        getchar();

        eliminarDeLista(lista, pos);

        if(lista->size==0)
        {
          printf("\nLa lista está vacía.\n");
        }
        break;

      case 6: 
        //Imprime la lista.
        mostrarLista(lista);
				break;

      case 7:
        //Elimina toda la lista.       
        printf("\n¿Está seguro que desea eliminar la lista?");
        printf("\nPresione Y para eliminarla o N para mantenerla: ");
        scanf("%s", &lastChance);
        getchar();

        if(lastChance=='y' || lastChance=='Y')
        {
          eliminarLista(lista);
          printf("\nSe ha eliminado la lista.\n\n");
        }
        else {
          if (lastChance=='n' || lastChance=='N')
          {
            printf("\nLa lista no se ha eliminado.\n\n");
            break;
          }
          else
          {
            printf("\nPor favor presione Y si desea eliminar la lista, o n si desea mantenerla.\n\n\n");
            opcion=7;
          }
        }
                
        break;

			case 8: exit(1);
				break;
			
      default: printf( "Opción no válida\n" );
				break;
		}
	} 
  return 0;
}