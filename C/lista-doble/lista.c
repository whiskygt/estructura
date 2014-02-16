#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "list.h"
#define arraySize 13
#define TRUE 1
#define FALSE 0

//Función que contiene un temporizador.
void timer(float sec);

//Permite mostrar una "animación" de carga.
void loading(float time);

//Imprime un menú con diferentes opciones.
int menu(ListaD *list);

void timer(float sec)
{
	clock_t end;
	end = clock() + sec + CLOCKS_PER_SEC;
	while (clock() < end){}
	sec=0;
}

void loading(float time)
{
	int i;
	int percent = 20;
	char barra[arraySize]={'[',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ', ']'};
	float sec = time/10;
	timer(sec);
	//printf("%f\n", time);
	//printf("%f\n", sec);

	for(i=1; i<11; i=i+2)
	{
		int j;
		barra[i]='-';
		barra[i+1]='-';

		for(j=0; j<arraySize; j++)
		{
			printf("%c", barra[j]);
		}
		printf(" %d%%\n", percent);
		percent = percent + 20;
		timer(sec);
	}
}

int menu(ListaD *list)
{
	int eleccion;

  	printf("\nMenú de Lista\n");
  	
  	if (list->size == 0)
  	{
    	printf ("1. Añadir un elemento.\n");
    	printf ("2. Cargar lista.\n");
    	printf ("3. Salir.\n");
  	}

  	else if(list->size == 1)
  	{
    	printf ("1. Añadir un elemento.\n");
      	printf ("2. Eliminar un elemento.\n");
    	printf ("3. Mostrar lista.\n");
      	printf ("4. Destruir lista.\n");
      	printf ("5. Guardar lista.\n");
      	printf ("6. Cargar lista.\n");
      	printf ("7. Salir\n");
  	}

  	else 
  	{
    	printf ("1. Añadir un elemento.\n");
      	printf ("2. Eliminar un elemento.\n");
    	printf ("3. Mostrar lista.\n");
      	printf ("4. Destruir lista.\n");
      	printf ("5. Guardar lista.\n");
      	printf ("6. Cargar lista.\n");
    	printf ("7. Salir\n");
  	}
  	
  	printf ("\nSu opción: ");
  	scanf ("%d", &eleccion);
  	getchar();
    printf("\n");
  	
  	if(list->size == 0 && eleccion == 2) eleccion = 6;
  	if(list->size == 0 && eleccion == 3) eleccion = 7;
  	
  	return eleccion;
}


int main() 
{
	ListaD *list;
	char data[25];
	int opcion;
	char lastChance;

	if ((list = (ListaD *) malloc (sizeof (ListaD))) == NULL)
	{
		return -1;
	}

	printf("\nBienvenido. \n");
	timer(0.5);
	
	printf("Presione Enter para crear la lista automáticamente.\n");
	getchar();
	
	printf("Creando lista. Por favor espere...\n");
	inicializar(list);
  	

	opcion = 0;
	while(opcion!=7)
	{
		opcion = menu(list);
		switch(opcion)
		{
			case 1:
				
				printf("Introduzca el elemento: ");
				scanf("%s", data);
				getchar();

				
				if(list->size==0)
				{
					position(0);
				}
				else
				{
					printf("\nInserte la posición donde quiere insertar el elemento: ");
					scanf("%i", &pos);
					position(pos);
				}
				
				insertar(list, data, FALSE);
				printf("\nElemento insertado.\n");
				timer(0.5);
			
			break;

			case 2:
				if(list->size==0)
				{
					opcion=7;
				}
				
				printf("Introduzca el elemento que desea eliminar: ");
				scanf("%s", data);
				getchar();

				eliminar(list, data);
				timer(0.5);
				printf("\nElemento eliminado.\n");
				
			break;

			case 3:
				printf("Mostrando lista.\n");
				showList(list);

			break;

			case 4:
				printf("\n¿Está seguro que desea eliminar la lista?");
        		printf("\nPresione Y para eliminarla o cualquier para mantenerla: ");
        		scanf("%s", &lastChance);
        		getchar();

		        if(lastChance=='y' || lastChance=='Y')
		        {
          			eliminarLista(list);
          			/*int i;
          			Nodo *killme;
          			killme = list->first;
          			size = list->size;
          			for(i=0; i<size; i++)
          			{
          				eliminar(list, killme->data);
          				killme=killme->next;

          			}*/
          			printf("\nSe ha eliminado la lista.\n\n");
        		}
        		else {
          		
            		printf("\nLa lista no se ha eliminado.\n\n");
            		break;         			
        		}

        		timer(0.5);
			break;

			case 5: 
				
				printf("La lista se guardará en un archivo externo. Cualquier lista previamente guardada se sobreescribirá.\nDesea continuar[y/n]: ");
				scanf("%s", &lastChance);
        		getchar();

        		if(lastChance=='y' || lastChance=='Y')
        		{
        			printf("\nGuardando lista, por favor espere.\n");
					saveFile(list);
					loading(1);
					printf("Lista guardada.\n");
					timer(0.5);
        		}
        		else
        		{
					printf("\nLa lista no se ha eliminado.\n\n");
        		}			

			break;

			case 6: 
				
				printf("Esta acción eliminará cualquier lista que haya creado actualmente.");		
				printf("\n¿Está seguro que desea continuar?");
        		printf("\nPresione Y para continuar o cualquier tecla para cancelar: ");
        		scanf("%s", &lastChance);
        		getchar();

		        if(lastChance=='y' || lastChance=='Y')
		        {
          			eliminarLista(list);
          			readFile(list);
        		}
        		else {
          		
            		printf("\nLa lista no se ha eliminado.\n\n");        			
        		}

			break;

			case 7: exit(1);		
			break;

			default: printf("Opción no válida.\n");
			break;
		}
	}

	return 0;
}