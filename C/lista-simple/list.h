#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nodo.h"

typedef struct Lista
{
  Nodo *first;
	Nodo *last;
	int size;
}Lista;

//Inicia la lista.
void iniciar(Lista *lista);

//Inserta el primer elemento en la lista.
int insertarEnListaVacia(Lista *lista, char *dato);

//Inserta un elemento al principio de la lista,
int insertarAlPrincipio(Lista *lista, char *dato);

//Inserta un elemento al final de la lista.
int insertarAlFinal(Lista *lista, Nodo *actual, char *dato);

//Inserta un elemento después de una posición determinada.
int insertarLista(Lista *lista, char *dato, int pos);

//Elimina un elemento que se encuentra al principio de la lista.
int eliminarAlPrincipio(Lista *lista);

//Elimina al elemento que se encuentra después de una posición determinada.
int eliminarDeLista(Lista *lista, int pos);

//Elimina la lista. 
void eliminarLista(Lista *lista);

//Imprime la lista.
void mostrarLista(Lista *lista);



void iniciar(Lista *lista)
{
	lista->first = NULL;
	lista->last = NULL;
	lista->size = 0;
}

int insertarEnListaVacia(Lista *lista, char *dato)
{
	Nodo *nuevo;

	if ((nuevo = (Nodo*) malloc (sizeof (Nodo))) == NULL)
	{
		return -1;
	}
  	
  if ((nuevo->dato = (char*) malloc (sizeof(char)*50)) == NULL)
  {
  	return -1;
  }
  strcpy (nuevo->dato, dato);

  nuevo->next=NULL;
  lista->first=nuevo;
  lista->last=nuevo;
  lista->size++;
 
  return 0;
}

int insertarAlPrincipio(Lista *lista, char *dato)
{
	Nodo *nuevo;

	if ((nuevo = (Nodo *) malloc (sizeof (Nodo))) == NULL)
	{
		return -1;
	}
  	
  if ((nuevo->dato = (char *) malloc (sizeof(char)*50)) == NULL)
  {
  	return -1;
  }
  strcpy ((char *)nuevo->dato, dato);

  nuevo->next = lista->first;
  lista->first = nuevo;
  lista->size++;

  return 0;
}

int insertarAlFinal(Lista *lista, Nodo *actual, char *dato)
{
	Nodo *nuevo;
  
	if ((nuevo = (Nodo *) malloc (sizeof (Nodo))) == NULL)
	{
		return -1;
	}
  	
  if ((nuevo->dato = (char *) malloc (sizeof(char)*50)) == NULL)
  {
  	return -1;
  }
  strcpy (nuevo->dato, dato);

  	actual->next = nuevo;
  	nuevo->next = NULL;
    lista->last = nuevo;
  	lista->size++;

  	return 0;
}

int insertarLista(Lista *lista, char *dato, int pos)
{
  if (lista->size < 2)
  {
    return -1;
  }

  if (pos < 1 || pos >= lista->size)
  {
    return -1;
  }

  Nodo *actual;
  Nodo *nuevo;
  int i;

  if ((nuevo = (Nodo *) malloc (sizeof (Nodo))) == NULL)
  {
    return -1;
  }
    
  if ((nuevo->dato = (char *) malloc (sizeof(char)*50)) == NULL)
  {
    return -1;
  }
  
  actual = lista->first;

  for(i = 1; i<pos; i++)
  {
    actual = actual->next;
    if (actual->next==NULL) return -1;
  }
  
  strcpy (nuevo->dato, dato);

  nuevo->next = actual->next;
  actual->next = nuevo;
  lista->size++;

  return 0;
}

int eliminarAlPrincipio(Lista *lista)
{
  if(lista->size==0)
  {
    return -1;
  } 

  Nodo *killme;
  killme = lista->first;
  lista->first = lista->first->next;
  
  if(lista->size == 1)
  {
    lista->last = NULL;
  }

  free(killme->dato);
  free(killme);
  lista->size--;

  return 0;
}

int eliminarDeLista(Lista *lista, int pos)
{
  if (lista->size<=1 || pos < 1 || pos >= lista->size)
  {
    return -1;
  }

  int i;
  Nodo *actual;
  Nodo *killme;

  actual = lista->first;

  for(i = 1; i<pos; ++i)
  {
    actual = actual->next;
  }

  killme = actual->next;
  actual->next = actual->next->next;
  
  if(actual->next==NULL)
  {
    lista->last = actual;
  }

  free(killme->dato);
  free(killme);
  lista->size--;

  return 0;

}

void mostrarLista(Lista *lista)
{
	Nodo *actual;
	actual = lista->first;

  printf("-- ELEMENTOS DE LA LISTA --\n");

	while(actual != NULL)
	{
    printf("%p - %s\n", actual, actual->dato);
		actual = actual->next;
	}
  printf("\nPresione alguna tecla para continuar...\n");
  getchar();
}

void eliminarLista(Lista *lista)
{
  while (lista->size>0)
  {
    eliminarAlPrincipio(lista);
  }
}