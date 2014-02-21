#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

typedef struct NodoLista
{
	char data[25];
	struct NodoLista *next;
	struct NodoLista *previous;
}Nodo;

typedef struct ListaD
{
	Nodo *first;
	Nodo *last;	
	int size;
}ListaD;

FILE *flist;
int pos=0;

//Inicializa la lista.
void inicializar(ListaD *list);

//Busca la ubicación del nodo.
int buscarNodo(ListaD *list, char *data);

//Inserta un elemento solo cuando la lista está vacía.
int insertarVacio(ListaD *list, char *data);

//Inserta al principio de la lista.
int insertarInicio(ListaD *list, char *data);

//Inserta al final de la lista.
int insertarFinal(ListaD *list, char *data);

//Inserta en una posición determinada.
int insertar(ListaD *list, char *data, int file);

//Imprime la lista.
void showList(ListaD *list);

//Elimina un elemento de la lista.
int eliminar(ListaD *list, char *data);

//Elimina toda la lista.
void eliminarLista(ListaD *list);

//Guarda los datos de la lista en un archivo externo.
void saveFile(ListaD *list);

//Lee los datos de la lista que están escritos en un archivo externo.
void readFile(ListaD *list);

//Establece la posición del elemento.
void position(int position);

void inicializar(ListaD *list)
{
	list->first=NULL;
	list->last=NULL;
	list->size=0;
}

int buscarNodo(ListaD *list, char *dato)
{
	if(list==NULL) return 0;
	if(list->size==0) return 1;
	
	else
	{
		int i=1;
		Nodo *search;

		search = list->first;

		while(strcmp(dato, search->data))
		{
			if(search->next==NULL) return 0;
			search=search->next;
			i++;
		}

		return i;
	}
}

int insertarVacio(ListaD *list, char *data)
{
	if(list->size!=0)
	{
		return -1;
	}

	Nodo *new;

	if((new = (Nodo*) malloc (sizeof (Nodo))) == NULL)
	{
		return -1;
	}

	strcpy(new->data, data);

	new->next=NULL;
	new->previous=NULL;
	list->first=new;
	list->last=new;
	list->size++;

	return 0;
}

int insertarInicio(ListaD *list, char *data)
{
	if (list==NULL) return -1;

	if (list->size==0) insertarVacio(list, data);

	Nodo *new;

	if((new = (Nodo*) malloc (sizeof (Nodo))) == NULL)
	{
		return -1;
	}

	strcpy(new->data, data);

	new->next=list->first;
	new->previous=NULL;	
	new->next->previous=new;
	list->first=new;
	list->size++;

	return 0;	
}

int insertarFinal(ListaD *list, char *data)
{
	if (list==NULL) return -1;

	if (list->size==0) insertarVacio(list, data);

	Nodo *new;

	if((new = (Nodo*) malloc (sizeof (Nodo))) == NULL)
	{
		return -1;
	}

	strcpy(new->data, data);

	new->next=NULL;
	new->previous=list->last;
	new->previous->next=new;
	list->last=new;
	list->size++;

	return 0;
}

int insertar(ListaD *list, char *data, int file)
{

	if (list==NULL) return -1;

	if(list->size==0) return insertarVacio(list, data);

	if (file)
	{		
		pos=list->size+1;
	}

	if(pos==1) return insertarInicio(list, data);

	if(pos>=list->size+1) return insertarFinal(list, data);

	Nodo *new;
	Nodo *current;
	int i;

	if ((new = (Nodo*) malloc (sizeof (Nodo))) == NULL)
	{
		return -1;
	}

	current=list->first;

	for(i=1; i<pos; i++)
	{
		printf("%d\t\t - \t%s\n", i,current->data);
		current = current->next;
		printf("%d\t\t - \t%s\n", i,current->data);
	}

	strcpy(new->data, data);
	
	new->previous = current->previous;
	new->next = current;
	current->previous->next = new;
	current->previous = new;
	
	list->size++;
	return 0;

}

void showList(ListaD *list)
{
	Nodo *current;
	current = list->first;
	int i=1;

  	printf("-- ELEMENTOS DE LA LISTA --\n");
  	printf("Posición\t -\tValor\n");

	while(current != NULL)
	{
    	printf("%d\t\t - \t%s\n", i,current->data);
		current = current->next;
		i++;
	}
  printf("\nPresione alguna tecla para continuar...\n");
  getchar();
}

int eliminar(ListaD *list, char *data)
{
	if(list==NULL)
	{
		return 0;
	}

	else
	{
		if(list->size==0)
		{
			return 0;
		}
		else
		{
			int pos;
			pos = buscarNodo(list, data);
			Nodo *killme;

			if(pos==0) 
			{	
				//free(killme);
				return -1;
			}

			else 
			{
				if(list->size==1)
				{
					killme=list->first;
					free(killme);
					inicializar(list);
				
					return 0;
				}
			
				else
				{
					if(pos==1)
					{
						killme=list->first;
						list->first=killme->next;
						killme->next->previous=NULL;

						free(killme);
						list->size--;
					
						return 0;
					}
					if(pos==list->size)
					{
						killme=list->last;
						list->last=killme->previous;
						killme->previous->next=NULL;

						free(killme);
						list->size--;
					
						return 0;
					}
					else
					{
						int i;
						Nodo *current;
						Nodo *killme;
						current=list->first;

						for(i=1; i<=pos; i++)
						{
							if(current->next==NULL) 
							current=current->next;
						}

						killme=current->previous;
						killme->previous->next=current;
						current->previous=killme->previous;

						free(killme);
						list->size--;
					
						return 0;
					}
				}
			}	
		}
	}
}

void eliminarLista(ListaD *list)
{
	Nodo *current;
	current = list->first;
	while (list->size>0)
  	{
	    eliminar(list, current->data);
	    
	    if(current->next == NULL) break;
	    
	    else
	    {
	    	current = current->next;
		}
  	}
}

void saveFile(ListaD *list)
{
	int i;
	Nodo *current;
	
	flist = fopen("list.txt", "w");

	current=list->first;

	for(i=0; i<list->size; i++)
	{
		//fwrite((char *)current->data, sizeof(Nodo), list->size, flist);
		fputs((char *)current->data, flist);
		fputs(" ", flist);
		current=current->next;
	}

	fclose(flist);
}

void readFile(ListaD *list)
{
	char allData[100];
	char *data;

	flist = fopen("list.txt", "r");

	while(fscanf(flist, "%s", allData) != EOF)
	{
		data = strtok(allData, " ");
		insertar(list, data, TRUE);
	}
}

void position(int position)
{
	pos=position;
}