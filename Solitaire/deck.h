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
int searchCard(Deck *list, int face, char *wSuit);

int insert(Deck *list, int wFace, char *wSuit, int hide);

//Cambia una carta de pila. El primer argumento es su lista actual, el segundo es su destino. 
void swapCard(Deck *origin, Deck *destination, int index);

//Elimina un elemento de la lista.
int eliminar(Deck *list, int pos);

//Imprime la lista.
void showList(Deck *list);

//Imprime las cartas que se encuentran en la BuildPile.
void showCardsBP(Deck *list);

//Imprime las cartas que se encuentran en el Deck.
void showCardsDeck(Deck *list, Deck *list2, Deck *list3, Deck *list4, Deck *list5);

//Establece que cartas se pueden ver.
void setVisible(Deck *list);

//Elimina toda la lista.
void eliminarLista(Deck *list);

//Guarda los datos de la lista en un archivo externo.
void saveFile(Deck *list);

//Lee los datos de la lista que están escritos en un archivo externo.
void readFile(Deck *list);

//char transformFace(int face);
//void transformFace(int face, char *cFace[]);
char *transformFace(int face, char *cFace);

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

int searchCard(Deck *list, int card, char *wSuit)
{
	printf("IN CARD\n");
	int out=FALSE;
	if(list==NULL) return 0;
	if(list->size==0) return 1;
	else
	{
		printf("IN CARD2\n");
		int i=1;
		Card *search = NULL;

		search = list->first;
		printf("%i\n", search->face);

		while(search->face != card && out==FALSE)
		{
			printf("IN CARD3\n");
			printf("%i\t%i\n", search->face, card);
			//if(search->next==NULL) return 0;
			if (search->face == card)
			{
				printf("IN CARD4\n");
				if(!strcmp(search->suit, wSuit))
				{
					printf("IN CARD5\n");
					if(search->hidden==FALSE)
					{
						printf("IN CARD6\n");
						out = TRUE;
					}
				}
			}
			else
			{
				search=search->next;
			}
			i++;
		}

		return i;
	}
}

//TODO: Testing pending
int searchList(Deck *list, int card, char *wSuit)
{
	printf("IN LIST\n");
	int out=FALSE;
	int found = FALSE;
	if(list==NULL) return FALSE;
	if(list->size==0) return FALSE;
	else
	{
		Card *search = NULL;
		search = list->first;

		while(found == FALSE)
		{
			//printf("En lista: %i \t En metodo: %i\n", search->face, card);
			if (search->face == card)
			{
				printf("IN LIST2\n");
				if(!strcmp(search->suit, wSuit))
				{
					printf("IN LIST3\n");
					if(search->hidden==FALSE)
					{
						printf("IN LIST4\n\n");
						found = TRUE;
						return TRUE;
					}
				}
			}
			if(search->next == NULL) return FALSE;
			search = search->next;
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

void swapCard(Deck *origin, Deck *destination, int index)
{
	printf("SWAP1\n");
	int i;
	Card *current = NULL;
	Card *selected = NULL;

	selected = origin->first;
	printf("SWAP2\n");

	if(origin->size == 1)
	{
		startList(origin);
	}
	else
	{
		if(index == 1)
		{
			printf("SWAP3\n");
			origin->first = selected->next;
			printf("SWAP4\n");
			selected->next->previous = NULL;
			printf("SWAP4v2\n");
		}
	
		else
		{
			printf("SWAP3.1\n");
			for(i=1; i<index; i++)
			{
				selected = selected->next;
			}
			current = selected->next;
			selected->previous->next = current;
			current->previous = selected->previous;
			printf("SWAP4.1\n");
		}
		origin->size--;
	}
	if(destination->size==0)
	{
		printf("SWAP5.1\n");
		selected->next = NULL;
		selected->previous = NULL;
		destination->first = selected;
		destination->last = selected;
	}
	else
	{
		printf("SWAP5.1\n");
		selected->next = destination->first;
		selected->previous = NULL;
		selected->next->previous = selected;
		destination->first = selected;
	}
	destination->size++;
	printf("SWAP6\n");
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
	//char *pFace[3]="10";
	char *wFace;
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
			//char pFace = transformFace(current->face);
			//transformFace(current->face, pFace);
		
			//printf("%s", current->suit);
			if(!strcmp(current->suit, "E"))
			{
				printf("|%s ♠| ", transformFace(current->face, wFace));
				//printf("|♠ %d", current->face);
			}
			if(!strcmp(current->suit, "T"))
			{
				printf("|%s ♣| ", transformFace(current->face, wFace));
				//printf("|♣ %i%s", current->face, transformFace(current->face, wFace)));
			}
			if(!strcmp(current->suit, "C"))
			{
				printf("|%s%s ♥| %s", red, transformFace(current->face, wFace), none);
				//printf("|%s♥ %i%s%s", red, current->face, transformFace(current->face, wFace)), none);
			}
			if(!strcmp(current->suit, "D"))
			{
				printf("|%s%s ♦| %s", red, transformFace(current->face, wFace), none);
				//printf("|%s♦ %c%s", red, current->face, transformFace(current->face, wFace)), none);
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

void showCardsDeck(Deck *list, Deck *list2, Deck *list3, Deck *list4, Deck *list5)
{
	Card *current = NULL;
	Card *current2 = NULL;
	Card *current3 = NULL;
	Card *current4 = NULL;
	Card *current5 = NULL;
	char *wFace;

	printf("|  | ");

	if(list == NULL) printf("|  |");
	if(list2 == NULL) printf("|  |");
	if(list3 == NULL) printf("|  |");
	if(list4 == NULL) printf("|  |");
	if(list5 == NULL) printf("|  |");

	if(list->size==0) printf("|  |");
	else
	{
		current = list->first;

		if(!strcmp(current->suit, "E"))
		{
			printf("|%s ♠| ", transformFace(current->face, wFace));
			//printf("|♠ %d", current->face);
		}
		if(!strcmp(current->suit, "T"))
		{
			printf("|%s ♣| ", transformFace(current->face, wFace));
			//printf("|♣ %i%s", current->face, transformFace(current->face, wFace)));
		}
		if(!strcmp(current->suit, "C"))
		{
			printf("|%s%s ♥| %s", red, transformFace(current->face, wFace), none);
			//printf("|%s♥ %i%s%s", red, current->face, transformFace(current->face, wFace)), none);
		}
		if(!strcmp(current->suit, "D"))
		{
			printf("|%s%s ♦| %s", red, transformFace(current->face, wFace), none);
			//printf("|%s♦ %c%s", red, current->face, transformFace(current->face, wFace)), none);
		}
	}

	printf("\t\t\t\t");
	if(list2->size==0) printf("|  |");
	else
	{
		current2 = list2->first;

		if(!strcmp(current2->suit, "E"))
		{
			printf("|%s ♠| ", transformFace(current2->face, wFace));
			//printf("|♠ %d", current2->face);
		}
		if(!strcmp(current2->suit, "T"))
		{
			printf("|%s ♣| ", transformFace(current2->face, wFace));
			//printf("|♣ %i%s", current2->face, transformFace(current2->face, wFace)));
		}
		if(!strcmp(current2->suit, "C"))
		{
			printf("|%s%s ♥| %s", red, transformFace(current2->face, wFace), none);
			//printf("|%s♥ %i%s%s", red, current2->face, transformFace(current2->face, wFace)), none);
		}
		if(!strcmp(current2->suit, "D"))
		{
			printf("|%s%s ♦| %s", red, transformFace(current2->face, wFace), none);
			//printf("|%s♦ %c%s", red, current2->face, transformFace(current2->face, wFace)), none);
		}
	}

	printf(" ");

	if(list3->size==0) printf("|  |");
	else
	{
		current3 = list3->first;

		if(!strcmp(current3->suit, "E"))
		{
			printf("|%s ♠| ", transformFace(current3->face, wFace));
			//printf("|♠ %d", current3->face);
		}
		if(!strcmp(current3->suit, "T"))
		{
			printf("|%s ♣| ", transformFace(current3->face, wFace));
			//printf("|♣ %i%s", current3->face, transformFace(current3->face, wFace)));
		}
		if(!strcmp(current3->suit, "C"))
		{
			printf("|%s%s ♥| %s", red, transformFace(current3->face, wFace), none);
			//printf("|%s♥ %i%s%s", red, current3->face, transformFace(current3->face, wFace)), none);
		}
		if(!strcmp(current3->suit, "D"))
		{
			printf("|%s%s ♦| %s", red, transformFace(current3->face, wFace), none);
			//printf("|%s♦ %c%s", red, current3->face, transformFace(current3->face, wFace)), none);
		}
	}
	printf(" ");
	
	if(list4->size==0) printf("|  |");
	else
	{
		current4 = list4->first;

		if(!strcmp(current4->suit, "E"))
		{
			printf("|%s ♠| ", transformFace(current4->face, wFace));
			//printf("|♠ %d", current4->face);
		}
		if(!strcmp(current4->suit, "T"))
		{
			printf("|%s ♣| ", transformFace(current4->face, wFace));
			//printf("|♣ %i%s", current4->face, transformFace(current4->face, wFace)));
		}
		if(!strcmp(current4->suit, "C"))
		{
			printf("|%s%s ♥| %s", red, transformFace(current4->face, wFace), none);
			//printf("|%s♥ %i%s%s", red, current4->face, transformFace(current4->face, wFace)), none);
		}
		if(!strcmp(current4->suit, "D"))
		{
			printf("|%s%s ♦| %s", red, transformFace(current4->face, wFace), none);
			//printf("|%s♦ %c%s", red, current4->face, transformFace(current4->face, wFace)), none);
		}
	}
	printf(" ");
	
	if(list5->size==0) printf("|  |");
	else
	{
		current5 = list5->first;

		if(!strcmp(current5->suit, "E"))
		{
			printf("|%s ♠| ", transformFace(current5->face, wFace));
			//printf("|♠ %d", current5->face);
		}
		if(!strcmp(current5->suit, "T"))
		{
			printf("|%s ♣| ", transformFace(current5->face, wFace));
			//printf("|♣ %i%s", current5->face, transformFace(current5->face, wFace)));
		}
		if(!strcmp(current5->suit, "C"))
		{
			printf("|%s%s ♥| %s", red, transformFace(current5->face, wFace), none);
			//printf("|%s♥ %i%s%s", red, current5->face, transformFace(current5->face, wFace)), none);
		}
		if(!strcmp(current5->suit, "D"))
		{
			printf("|%s%s ♦| %s", red, transformFace(current5->face, wFace), none);
			//printf("|%s♦ %c%s", red, current5->face, transformFace(current5->face, wFace)), none);
		}
	}
	printf("\n");

/*	if(list2 == NULL) printf("|  |");
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
	}*/	
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

int transformSuit(char *wSuit)
{
	if(!strcmp(wSuit, "E")) return 1;
	if(!strcmp(wSuit, "C")) return 2;
	if(!strcmp(wSuit, "T")) return 3;
	if(!strcmp(wSuit, "D")) return 4;
}

char *transformFace(int face, char *cFace)
{
	//char *cFace[13]={"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
	if(face == 1) 
	{
		cFace="A";
	}

	if(face == 2) 
	{
		cFace="2";
	}
	if(face == 3) 
	{
		cFace="3";
	}
	if(face == 4) 
	{
		cFace="4";
	}
	if(face == 5) 
	{
		cFace="5";
	}
	if(face == 6) 
	{
		cFace="6";
	}
	if(face == 7) 
	{
		cFace="7";
	}
	if(face == 8) 
	{
		cFace="8";
	}
	if(face == 9) 
	{
		cFace="9";
	}
	if(face == 10)
	{
		cFace="10";
	}
	if(face == 11)
	{
		cFace="J";
	}
	if(face == 12)
	{
		cFace="Q";
	}
	if(face == 13)
	{
		cFace="K";
	}

	return cFace;
}