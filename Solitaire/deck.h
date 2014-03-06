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
void swapCard(Deck *origin, Deck *destination, int index, int straight);

//Elimina un elemento de la lista.
int delete(Deck *list);

//Imprime la lista.
void showList(Deck *list);

//Imprime las cartas que se encuentran en la BuildPile.
void showCardsBP(Deck *list);

//Imprime las cartas que se encuentran en el Deck.
void showCardsDeck(Deck *list, Deck *list2, Deck *list3, Deck *list4, Deck *list5);

//Establece que cartas se pueden ver.
void setVisible(Deck *list);

//Elimina toda la lista.
void deleteAll(Deck *list);

//Guarda las pilas en archivos de texto.
void saveFile(Deck *list, Deck *list2, Deck *list3, Deck *list4, Deck *list5, Deck *list6, Deck *list7, Deck *list8, Deck *list9, Deck *list10, Deck *list11, Deck *list12, Deck *list13);

//Escribe los datos de una lista en un archivo de texto.
void writeList(Deck *list, FILE *fileList);

//Lee las pilas en los archivos externos.
void readFile(Deck *list, Deck *list2, Deck *list3, Deck *list4, Deck *list5, Deck *list6, Deck *list7, Deck *list8, Deck *list9, Deck *list10, Deck *list11, Deck *list12, Deck *list13);

//Lee los datos de una lista que se encuentran en un archivo externo.
void readList(Deck *list, FILE *rList);

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
	int out=FALSE;
	if(list==NULL) return 0;
	if(list->size==0) return 1;
	else
	{
		int i=1;
		Card *search = NULL;

		search = list->first;
		printf("%i\n", search->face);

		while(search->face != card && out==FALSE)
		{
			printf("%i\t%i\n", search->face, card);
			//if(search->next==NULL) return 0;
			if (search->face == card)
			{
				if(!strcmp(search->suit, wSuit))
				{
					if(search->hidden==FALSE)
					{
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
				if(!strcmp(search->suit, wSuit))
				{
					if(search->hidden==FALSE)
					{
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

void swapCard(Deck *origin, Deck *destination, int index, int straight)
{
	printf("SWAP1\n");
	int i;
	int flag=FALSE;
	Card *current = NULL;
	Card *selected = NULL;

	selected = origin->first;
	printf("SWAP2\n");

	// SE ELIMINA LA(S) CARTAS DE SU PILA ACTUAL
	if(origin->size == 1)
	{
		/*printf("PRUEBA\n");
		selected->next = destination->first;
		selected->next->previous = selected;
		selected->previous = NULL;
		destination->first = selected;
		destination->size++;*/

		printf("delete ORIGIN\n");
		startList(origin);
		//flag = TRUE;
	}
	else
	{
		printf("INDEEEX: %i\n", index);
		if(index == 1)
		{
			printf("SIZE: %i\n", origin->size);
			printf("SWAP3\n");
			if(selected->next != NULL)
			{
				printf("NO NULO\n");
			}
			current = selected->next;
			origin->first = current;
			printf("SWAP4\n");
			current->previous = NULL;
			printf("SWAP4v2\n");
			origin->size--;
		}

		else
		{
			if (straight)
			{
				printf("PRESWAP AGAIN\n");
				printf("POS STRAIGHT: %i\n", index);
				if(index == origin->size)
				{
					printf("SWAP AGAIN\n");
					selected=origin->last;
					if(destination->size==0)
					{
						selected->next = NULL;
						destination->last = selected;
					}
					else
					{
						selected->next = destination->first;
						selected->next->previous = selected;
					}

					int j;
					//while(selected->previous != NULL)
					for (j=index; j>1; j--)
					{
						printf("SELECTEEED\n");
						selected = selected->previous;
					}
					destination->first=selected;
					destination->size = destination->size + index;
					
					startList(origin);
					flag = TRUE;
				}
				else
				{
					printf("SIZE: %i\n", origin->size);
					printf("SWAP3\n");
					for(i=1; i<index; i++)
					{
						selected = selected->next;
					}
					if(selected->next != NULL)
					{
						printf("NO NULO\n");
					}
					current = selected->next;
					origin->first = current;
					printf("SWAP4\n");

					current->previous = NULL;
					printf("SWAP4v2\n");

					printf("Index2: %i\n", index);
					origin->size = origin->size - index;
				}
			}
			else
			{
				printf("SWAP3.1\n");
				for(i=1; i<index; i++)
				{
					selected = selected->next;
				}
				if(index = origin->size)
				{
					current = selected->previous;
					current->next = NULL;
					origin->last = current;
					printf("SWAP 100\n");
				}
				else
				{
					current = selected->next;
					selected->previous->next = current;
					current->previous = selected->previous;
					printf("SWAP4.1\n");
				}
				origin->size--;
			}
		}

		printf("NUEVO SIZE: %i\n", origin->size);
	}

	// SE AGREGAN LA(S) CARTAS A LA PILA DESTINOL.
	if (!flag)
	{
		if(destination->size==0)
		{
			printf("SWAP5.1\n");
			selected->next = NULL;
			destination->last = selected;
			if(!straight)
			{
				selected->previous = NULL;
				destination->first = selected;
				destination->size++;
			}
			else
			{
				while(selected->previous != NULL)
				{
					printf("SELECTEEED\n");
					selected = selected->previous;
				}
				destination->first=selected;
				destination->size = destination->size + index;	
			}

		printf("NUEVO SIZE 2: %i\n", destination->size);
		}
		else
		{
			printf("SWAP5.2\n");
			selected->next = destination->first;
			selected->next->previous = selected;
			if(!straight)
			{
				selected->previous = NULL;
				destination->first = selected;
				destination->size++;
			}
			else
			{
				while(selected->previous != NULL)
				{
					printf("SELECTEEEED2\n");
					selected= selected->previous ;
				}
				destination->first=selected;
				destination->size = destination->size + index;
			}
		}
		
	}
	printf("NUEVO SIZE 2: %i\n", destination->size);
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

	if(list == NULL) printf("|  |1");
	if(list2 == NULL) printf("|  |2");
	if(list3 == NULL) printf("|  |3");
	if(list4 == NULL) printf("|  |4");
	if(list5 == NULL) printf("|  |5");

	if(list->size==0) printf("|  |01");
	else
	{
		current = list->first;
		printf("FACE: %i, SUIT: %s\n", current->face, current->suit);
		printf("1\n");
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

int delete(Deck *list)
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

			if(list->size==1)
			{
				killme=list->first;
				free(killme);
				killme = NULL;
				startList(list);
				printf("\nElemento eliminado.\n");
				return 0;
			}
			else
			{
				killme=list->first;
				list->first=killme->next;	
				free(killme);
				killme = NULL;
				list->size--;
				printf("\nElemento eliminado.\n");
				return 0;
			}
		}
	}
}

void deleteAll(Deck *list)
{
	Card *current = NULL;
	current = list->first;
	while (list->size>0)
  	{
	    delete(list);
	    current = current->next;
  	}
}

void saveFile(Deck *list, Deck *list2, Deck *list3, Deck *list4, Deck *list5, Deck *list6, Deck *list7, Deck *list8, Deck *list9, Deck *list10, Deck *list11, Deck *list12, Deck *list13)
{
	FILE *lFile;
	printf("IN GUARDAR\n");
	lFile = fopen("SavedGames/pile1.txt", "w");

	printf("IN GUARDAR1.1\n");
	writeList(list, lFile);

	lFile = fopen("SavedGames/pile2.txt", "w");
	printf("IN GUARDAR2\n");
	writeList(list2, lFile);

	lFile = fopen("SavedGames/pile3.txt", "w");
	printf("IN GUARDAR3\n");
	writeList(list3, lFile);

	lFile = fopen("SavedGames/pile4.txt", "w");
	printf("IN GUARDAR4\n");
	writeList(list4, lFile);
	
	lFile = fopen("SavedGames/pile5.txt", "w");
	printf("IN GUARDAR5\n");
	writeList(list5, lFile);

	lFile = fopen("SavedGames/pile6.txt", "w");
	printf("IN GUARDAR6\n");
	writeList(list6, lFile);

	lFile = fopen("SavedGames/pile7.txt", "w");
	printf("IN GUARDAR7\n");
	writeList(list7, lFile);

	lFile = fopen("SavedGames/pile8.txt", "w");
	printf("IN GUARDAR8\n");
	writeList(list8, lFile);

	lFile = fopen("SavedGames/pile9.txt", "w");
	writeList(list9, lFile);

	lFile = fopen("SavedGames/pile10.txt", "w");
	writeList(list10, lFile);

	lFile = fopen("SavedGames/pile11.txt", "w");
	writeList(list11, lFile);

	lFile = fopen("SavedGames/pile12.txt", "w");
	writeList(list12, lFile);	

	lFile = fopen("SavedGames/pile13.txt", "w");
	writeList(list13, lFile);
}

void writeList(Deck *list, FILE *fileList)
{
	int i;
	Card *current;
	char *wFace;

	printf("TRY1\n");
	current=list->last;

	printf("TRY2\n");
	for(i=list->size; i>0; i--)
	{
		printf("TRY3\n");
		//fwrite((char *)current->data, sizeof(Node), list->size, fileList);
		if(current->face == 10)
		{
			char sFace[]="T";
			printf("TRY4\n");
			printf("%s\n", sFace);
			fputs(sFace, fileList);
			printf("TRY4.1\n");
		}
		else
		{
			printf("TRY5\n");
			fputs(transformFace(current->face, wFace), fileList);
		}
		//fputs(", ", fileList);
		printf("TRY6\n");

		//fputs((char *)current->suit, fileList);
		if(transformSuit(current->suit) == 1)
		{
			fputs("1", fileList);
		}
		if(transformSuit(current->suit) == 2)
		{
			fputs("2", fileList);
		}
		if(transformSuit(current->suit) == 3)
		{
			fputs("3", fileList);
		}
		if(transformSuit(current->suit) == 4)
		{
			fputs("4", fileList);
		}
		//fputs(", ", fileList);
		printf("TRY7\n");
		if(current->hidden == TRUE)
		{
			printf("TRY8\n");
			fputs("1", fileList);
		}
		else
		{
			printf("TRY10\n");
			fputs("0", fileList);
		}
		printf("TRY11\n");
		//fputs("; ", fileList);
		current=current->previous;
		printf("TRY12\n");
	}
	printf("TRY13\n");
	fclose(fileList);
}

void readFile(Deck *list, Deck *list2, Deck *list3, Deck *list4, Deck *list5, Deck *list6, Deck *list7, Deck *list8, Deck *list9, Deck *list10, Deck *list11, Deck *list12, Deck *list13)
{
	/*deleteAll(list);
	deleteAll(list2);
	deleteAll(list3);
	deleteAll(list4);
	deleteAll(list5);
	deleteAll(list6);
	deleteAll(list7);
	deleteAll(list8);
	deleteAll(list9);
	deleteAll(list10);
	deleteAll(list11);
	deleteAll(list12);
	deleteAll(list13);*/

	FILE *lFile;
	printf("IN LEER\n");
	lFile = fopen("SavedGames/pile1.txt", "r");

	printf("IN LEER1.1\n");
	readList(list, lFile);

	lFile = fopen("SavedGames/pile2.txt", "r");
	printf("IN LEER2\n");
	readList(list2, lFile);

	lFile = fopen("SavedGames/pile3.txt", "r");
	printf("IN LEER3\n");
	readList(list3, lFile);

	lFile = fopen("SavedGames/pile4.txt", "r");
	printf("IN LEER4\n");
	readList(list4, lFile);
	
	lFile = fopen("SavedGames/pile5.txt", "r");
	printf("IN LEER5\n");
	readList(list5, lFile);

	lFile = fopen("SavedGames/pile6.txt", "r");
	printf("IN LEER6\n");
	readList(list6, lFile);

	lFile = fopen("SavedGames/pile7.txt", "r");
	printf("IN LEER7\n");
	readList(list7, lFile);

	lFile = fopen("SavedGames/pile8.txt", "r");
	printf("IN LEER8\n");
	readList(list8, lFile);

	lFile = fopen("SavedGames/pile9.txt", "r");
	readList(list9, lFile);

	lFile = fopen("SavedGames/pile10.txt", "r");
	readList(list10, lFile);

	lFile = fopen("SavedGames/pile11.txt", "r");
	readList(list11, lFile);

	lFile = fopen("SavedGames/pile12.txt", "r");
	readList(list12, lFile);	

	lFile = fopen("SavedGames/pile13.txt", "r");
	readList(list13, lFile);
	
}

void readList(Deck *list, FILE *rFile)
{
	char faceCard;
	char suitCard;
	char *suit[] = {"E", "C", "T", "D"};
	char hiddenC;
	int iFace;
	int iHidden;

	char as = 'A';
	char jack = 'J';
	char queen = 'Q';
	char king = 'K';
	char ten = 'T';

	deleteAll(list);

	while(!feof(rFile))
	{
		faceCard = fgetc(rFile);
		suitCard = fgetc(rFile);
		hiddenC = fgetc(rFile);

		printf("%c ", faceCard);
		printf("%c ", suitCard);
		printf("%c ", hiddenC);
		printf("\n");
		if(!strcmp(&faceCard, &as))
		{
			printf("AS\n");
			iFace = 1;
		}
		else if(!strcmp(&faceCard, &jack))
		{
			printf("JACK\n");
			iFace = 11;
		}
		else if(!strcmp(&faceCard, &queen))
		{
			printf("QUEEN\n");
			iFace = 12;
		}
		else if(!strcmp(&faceCard, &king))
		{
			printf("KING\n");
			iFace = 13;
		}
		else if(!strcmp(&faceCard, &ten))
		{
			printf("TEN\n");
			iFace = 10;
		}
		else
		{
			iFace = faceCard-48;
			printf("F: %i\n", iFace);
			if(iFace == 17) iFace = 1;
			if(iFace == 26) iFace = 11;
			if(iFace == 27) iFace = 13;
			if(iFace == 33) iFace = 12;
			if(iFace == 36) iFace = 10;

			if(iFace<1 || iFace>37) 
			{
				printf("Carta no movida.\n");
				break;
			}
		}
		iHidden = hiddenC - 48;
		printf("%i\n", iHidden);
		/*if(!strcmp(&hiddenC, "1"))
		{
			printf("try\n");
			iHidden = TRUE;
		}
		else
		{
			printf("try2\n");
			iHidden = FALSE;
		}*/

		insert(list, iFace, suit[suitCard-49], iHidden);
		printf("FACE: %i, SUIT: %s, Hidden: %i\n", iFace, suit[suitCard-49], iHidden);

	}
	/*while(fscanf(flist, "%s", allData) != EOF)
	{
		dataList = strtok(allData, "\n--\n");
		dataCard = strtok(dataList, "; ");
		faceCard = strtok(dataCard, ", ");
		
		//insert(list, data, TRUE);
	}*/
	fclose(rFile);
}

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