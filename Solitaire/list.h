#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "card.h"
#define TRUE 1
#define FALSE 0

typedef struct Deck
{
	Card *first;
	Card *last;	
	int size;
}Deck;

FILE *flist;
int pos=0;
Card deck[52];

//Inicializa la lista.
void startList(Deck *list);

//Busca la ubicación del nodo.
int searchNode(Deck *list, char *data);

int insert(Deck *list, char *wFace, char *wSuit, int hide);

//Elimina un elemento de la lista.
int eliminar(Deck *list, char *data);

//Imprime la lista.
void showList(Deck *list);

//Elimina toda la lista.
void eliminarLista(Deck *list);

//Guarda los datos de la lista en un archivo externo.
void saveFile(Deck *list);

//Lee los datos de la lista que están escritos en un archivo externo.
void readFile(Deck *list);

void startList(Deck *list)
{
	list->first=NULL;
	list->last=NULL;
	list->size=0;
}

void deal()
{
	char *face[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13"};
	char *suit[] = {"C", "E", "T", "D"};

	srand(time(NULL));

	int i;

	for (i = 0; i <= 51; i++ )
	{
		deck[i].face = face[i % 13];
		deck[i].suit = suit[i / 13];
	}

	int j;
	Card temp;

	for(i = 0; i <= 51; i++)
	{
		j = rand() % 52;
		temp = deck[i];
		deck[i] = deck[j];
		deck[j] = temp;
	}
}

int searchNode(Deck *list, char *data)
{
	if(list==NULL) return 0;
	if(list->size==0) return 1;
	
	else
	{
		int i=1;
		Card *search;

		search = list->first;

		while(strcmp(data, search->face))
		{
			if(search->next==NULL) return 0;
			search=search->next;
			i++;
		}

		return i;
	}
}

int insert(Deck *list, char *wFace, char *wSuit, int hide)
{
	printf("FLAG 6");
	if (list==NULL) return -1;

	Card *new;

	if((new = (Card*) malloc (sizeof (Card))) == NULL)
	{
		return -1;
	}

	strcpy(new->face, wFace);
	strcpy(new->suit, wSuit);
	

	if (list->size==0)
	{
		new->next=NULL;
		list->first=new;
		list->last=new;
	}
	else
	{
		new->next=list->first;
		list->first=new;
	}

	list->size++;
	return 0;	
}

/*int insertarVacio(Deck *list, char *data)
{
	if(list->size!=0)
	{
		return -1;
	}

	Node *new;

	if((new = (Node*) malloc (sizeof (Node))) == NULL)
	{
		return -1;
	}

	strcpy(new->selected.face, data);

	new->next=NULL;
	new->previous=NULL;
	list->first=new;
	list->last=new;
	list->size++;

	return 0;
}

int insertarInicio(Deck *list, char *data)
{
	if (list==NULL) return -1;

	if (list->size==0) insertarVacio(list, data);

	Node *new;

	if((new = (Node*) malloc (sizeof (Node))) == NULL)
	{
		return -1;
	}

	strcpy(new->selected.face, data);

	new->next=list->first;
	new->previous=NULL;	
	new->next->previous=new;
	list->first=new;
	list->size++;

	return 0;	
}

int insertarFinal(Deck *list, char *data)
{
	if (list==NULL) return -1;

	if (list->size==0) insertarVacio(list, data);

	Node *new;

	if((new = (Node*) malloc (sizeof (Node))) == NULL)
	{
		return -1;
	}

	strcpy(new->selected.face, data);

	new->next=NULL;
	new->previous=list->last;
	new->previous->next=new;
	list->last=new;
	list->size++;

	return 0;
}

int insertar(Deck *list, char *data, int file)
{

	if (list==NULL) return -1;

	if(list->size==0) return insertarVacio(list, data);

	//pos = searchNode(list, data);

	if (file)
	{		
		pos=list->size+1;
	}

	if(pos==1) return insertarInicio(list, data);

	if(pos>=list->size+1) return insertarFinal(list, data);

	//if(pos>list->size+1) return -1;

	Node *new;
	Node *current;
	int i;

	if ((new = (Node*) malloc (sizeof (Node))) == NULL)
	{
		return -1;
	}

	current=list->first;

	for(i=1; i<pos; i++)
	{
		printf("%d\t\t - \t%s\n", i,current->selected.face);
		current = current->next;
		//if(current->next==NULL) return -1;
		printf("%d\t\t - \t%s\n", i,current->selected.face);
	}

	strcpy(new->selected.face, data);
	
	new->previous = current->previous;
	new->next = current;
	current->previous->next = new;
	current->previous = new;
	
	list->size++;
	return 0;

}*/

void showList(Deck *list)
{
	Card *current;
	current = list->first;
	int i=1;

  	printf("-- ELEMENTOS DE LA LISTA --\n");
  	printf("Posición\t -\tValor\n");

	while(current != NULL)
	{
    	printf("\nCarta: %s%s", current->face, current->suit);
		current = current->next;
		i++;
	}
  printf("\nPresione alguna tecla para continuar...\n");
  getchar();
}

int eliminar(Deck *list, char *data)
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
			pos = searchNode(list, data);
			Card *killme;

			if(pos==0) 
			{
				printf("No se encontró el Card.\n");
				free(killme);
				return -1;
			}

			if(list->size==1)
			{
				killme=list->first;
				free(killme);
				//inicializar(list);
				printf("\nElemento eliminado.\n");
				return 0;
			}
			else
			{
				if(pos==1)
				{
					killme=list->first;
					list->first=killme->next;

					free(killme);
					list->size--;
					printf("\nElemento eliminado.\n");
					return 0;
				}

/*				if(pos==list->size)
				{
					killme=list->last;
					list->last=killme->previous;
					killme->previous->next=NULL;

					free(killme);
					list->size--;
					printf("\nElemento eliminado.\n");
					return 0;
				}
*/
				else
				{
					int i;
					Card *current;
					Card *killme;
					current=list->first;

					for(i=1; i<pos-1; i++)
					{
						if(current->next==NULL) printf("\nERROR.\n");
						current=current->next;
					}

					killme=current->next;
					current->next=killme->next;

					free(killme);
					list->size--;
					printf("\nElemento eliminado.\n");
					return 0;
				}
			}
		}
	}
}

void eliminarLista(Deck *list)
{
	Card *current;
	current = list->first;
	while (list->size>0)
  	{
	    eliminar(list, current->face);
	    current = current->next;
  	}
}

void saveFile(Deck *list)
{
	int i;
	Card *current;
	
	flist = fopen("list.txt", "w");

	current=list->first;

	for(i=0; i<list->size; i++)
	{
		//fwrite((char *)current->data, sizeof(Node), list->size, flist);
		fputs((char *)current->face, flist);
		fputs(" ", flist);
		current=current->next;
	}

	fclose(flist);
}

/*void readFile(Deck *list)
{
	char allData[100];
	char *data;

	flist = fopen("list.txt", "r");

	while(fscanf(flist, "%s", allData) != EOF)
	{
		data = strtok(allData, " ");
		insert(list, data, TRUE);
	}
}*/

void position(int position)
{
	pos=position;
}

char* getSuit(Deck *list)
{
	Card *current;
	current = list->first;
	return current->suit;
}
