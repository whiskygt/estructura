#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "card.h"
#include "color.h"
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
int x;

//Inicializa la lista.
void startList(Deck *list);

//Busca la ubicación del nodo.
int searchNode(Deck *list, int data);

int insert(Deck *list, int wFace, char *wSuit, int hide);

//Cambia la carta del Deck. Si el deck1 vacío entonces inserta todas las cartas que están en el deck2 en el deck 1.
//El primer argumento es su lista actual, el segundo es su destino. 
void swapCard(Deck *origin, Deck *destiny);

//Elimina un elemento de la lista.
int eliminar(Deck *list, int pos);

//Imprime la lista.
void showList(Deck *list);

//Imprime las cartas que se encuentran en la BuildPile.
void showCardsBP(Deck *list);

//Imprime las cartas que se encuentran en el Deck.
void showCardsDeck(Deck *list, Deck *list2);

//Imprime las cartas que se encuentran en las Pilas finales.
void showCardsCP(Deck *list);

//Establece que cartas se pueden ver.
void setVisible(Deck *list);

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
	int i;
	int face[13];
	for(i=0; i<13; i++)
	{
		face[i]=i+1;
	}
	char *suit[] = {"C", "E", "T", "D"};

	srand(time(NULL));

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

int searchNode(Deck *list, int data)
{
	if(list==NULL) return 0;
	if(list->size==0) return 1;
	
	else
	{
		int i=1;
		Card *search = NULL;

		search = list->first;

		while(search->face = data)
		{
			if(search->next==NULL) return 0;
			search=search->next;
			i++;
		}

		return i;
	}
}

int searchList(Deck *list, int card, char *wSuit)
{
	int out=FALSE;
	if(list==NULL) return FALSE;
	if(list->size==0) return FALSE;
	else
	{
		Card *search = NULL;
		search = list->first;

		while(search->face != card && out==FALSE)
		{
			if(search->next == NULL) return FALSE;
			search = search->next;
			if (search->face == card)
			{
				if(!strcmp(search->suit, wSuit))
				{
					out = TRUE;
					return TRUE;
				}
			}
		}
		
	}

}

int insert(Deck *list, int wFace, char *wSuit, int hide)
{

	if (list==NULL) return -1;

	Card *new = NULL;

	if((new = (Card*) malloc (sizeof (Card))) == NULL)
	{
		return -1;
	}
	new->face=wFace;
	new->suit = wSuit;
	//strcpy(new->suit, wSuit);
	if(hide == TRUE)
	{
		new->hidden = TRUE;
	}
	else
	{
		new->hidden = FALSE;
	}

	if (list->size==0)
	{
		new->next=NULL;
		new->previous=NULL;
		list->first=new;
		list->last=new;
	}
	else
	{
		new->next=list->first;
		new->previous=NULL;	
		new->next->previous=new;
		list->first=new;
	}


	list->size++;	
	return 0;	
}

void swapCard(Deck *origin, Deck *destiny)
{

}

void showList(Deck *list)
{
	Card *current = NULL;
	current = list->first;
	int i=1;

  	printf("-- ELEMENTOS DE LA LISTA --\n");

	while(current != NULL)
	{
    	printf("\nCarta: %d%s", current->face, current->suit);
		current = current->next;
		i++;
	}
  printf("\nPresione alguna tecla para continuar...\n");
  getchar();
}

void showCardsBP(Deck *list)
{
	Card *current = NULL;
	current = list->last;
	//int i=1;
	//int line;
	//printf("\n");
	
	while(current != NULL)
	{
		/*if(i==list->size+1) 
		{
			//printf("\n");
			current = list->last;
			line = FALSE;
		}
		else
		{
			line=TRUE;
		}*/

		if(current->hidden==TRUE)
		{
			//printf("|");
			printf("|");
		}
		else
		{
			//printf("%s", current->suit);
			if(!strcmp(current->suit, "E"))
			{
				printf("|%d ♠| ", current->face);
				//printf("|♠ %d", current->face);
			}
			if(!strcmp(current->suit, "T"))
			{
				printf("|%d ♣| ", current->face);
				//printf("|♣ %d", current->face);
			}
			if(!strcmp(current->suit, "C"))
			{
				printf("|%s%d ♥| %s", red, current->face, none);
				//printf("|%s♥ %d%s", red, current->face, none);
			}
			if(!strcmp(current->suit, "D"))
			{
				printf("|%s%d ♦| %s", red, current->face, none);
				//printf("|%s♦ %d%s", red, current->face, none);
			}
			//printf("|%d%s", current->face, current->suit);	
		}
		current = current->previous;
		//printf("\nBEFORE IF\n");
		//i++;
		//if(i==list->size) line = TRUE;

	}
	printf("\n");
}

void showCardsDeck(Deck *list, Deck *list2)
{
	Card *current = NULL;
	Card *current2 = NULL;

	if(list == NULL) printf("|  |");
	if(list->size==0) printf("|  |");
	else 
	{
		current = list->first;

		if(!strcmp(current->suit, "E"))
		{
			printf("|%d ♠| ", current->face);
			//printf("|♠ %d", current->face);
		}

		if(!strcmp(current->suit, "T"))
		{
			printf("|%d ♣| ", current->face);
			//printf("|♣ %d", current->face);
		}

		if(!strcmp(current->suit, "C"))
		{
			printf("|%s%d ♥| %s", red, current->face, none);
			//printf("|%s♥ %d%s", red, current->face, none);
		}

		if(!strcmp(current->suit, "D"))
		{
			printf("|%s%d ♦| %s", red, current->face, none);
			//printf("|%s♦ %d%s", red, current->face, none);
		}
	}

	if(list2 == NULL) printf("|  |");
	if(list2->size==0) printf("|  |");
	else 
	{
		current2 = list2->first;

		if(!strcmp(current2->suit, "E"))
		{
			printf("|%d ♠| ", current2->face);
			//printf("|♠ %d", current2->face);
		}

		if(!strcmp(current2->suit, "T"))
		{
			printf("|%d ♣| ", current2->face);
			//printf("|♣ %d", current2->face);
		}

		if(!strcmp(current2->suit, "C"))
		{
			printf("|%s%d ♥| %s", red, current2->face, none);
			//printf("|%s♥ %d%s", red, current2->face, none);
		}

		if(!strcmp(current2->suit, "D"))
		{
			printf("|%s%d ♦| %s", red, current2->face, none);
			//printf("|%s♦ %d%s", red, current2->face, none);
		}
	}
	

	
	printf("\n");
}

void setHidden(Deck *list, int choice)
{
	Card *current = NULL;
	if(list->size==0) return;
	else
	{
		if(choice==FALSE)
		{
			current = list->first;
			current->hidden=FALSE;
		}
		else
		{
			if(current->next == NULL) return;
			current = current->next;
			printf("INTENTAR OCULTAR\n");
			while(current != NULL)
			{
				current->hidden=TRUE;
		printf("SECOND\n");
				current = current->next;
			}
		}
	}
}

int eliminar(Deck *list, int pos)
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
			Card *killme = NULL;

			if(pos==0) 
			{
				printf("No se encontró el Card.\n");
				free(killme);
				killme = NULL;
				return -1;
			}

			if(list->size==1)
			{
				killme=list->first;
				free(killme);
				killme = NULL;
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
					killme = NULL;
					list->size--;
					printf("\nElemento eliminado.\n");
					return 0;
				}

				else
				{
					int i;
					Card *current;
					Card *killme = NULL;
					current=list->first;

					for(i=1; i<pos-1; i++)
					{
						if(current->next==NULL) printf("\nERROR.\n");
						current=current->next;
					}

					killme=current->next;
					current->next=killme->next;

					free(killme);
					killme = NULL;

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
	Card *current = NULL;
	current = list->first;
	while (list->size>0)
  	{
	    eliminar(list, current->face);
	    current = current->next;
  	}
}

/*void saveFile(Deck *list)
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
}*/

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