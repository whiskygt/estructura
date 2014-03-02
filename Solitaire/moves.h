#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

//Si el deck1 vacío entonces inserta todas las cartas que están en el deck2 en el deck 1.
void deckTransfer();

//Mueve una carta de una pila a otra.
void move(Deck *list, Deck *destination, int face, char *wSuit);

//Busca una carta en todas las listas.
int findCard(int face, char *wSuit);

void deckTransfer()
{
	printf("Size deck1: %i\tSize deck2: %i\n", deckPile1->size, deckPile2->size);
	if(deckPile1->size==0)
	{
		int i;
		for(i=deckPile2->size; i>0; i--)
		{
			swapCard(deckPile2, deckPile1, 1);
		}
		//TODO:
		//INSERTAR TODOS LOS ELEMENTOS DE deckPile2 en deckPile1 y luego eliminarlos de deckPile2.
	}
	else
	{
		swapCard(deckPile1, deckPile2, 1);
	}
}

void moveCard(Deck *destination, int face, char *wSuit, int atBuildPiles)
{
	printf("FLAG 1\n");
	if(searchList(destination, face, wSuit) == 1)
	{
		printf("No puede mover una carta en la misma pila.");
	}
	else
	{
		printf("FLAG 2\n");
		if(validateInsert(destination, face, wSuit, atBuildPiles))
		{
			printf("FLAG 3.1\n");
			printf("Find: %i\n", findCard(face, wSuit));
			switch(findCard(face, wSuit))
			{
				case 1:
					move(buildPile1, destination, face, wSuit);
				break;

				case 2:
					move(buildPile2, destination, face, wSuit);
				break;

				case 3:
					move(buildPile3, destination, face, wSuit);
				break;

				case 4:
					move(buildPile4, destination, face, wSuit);
				break;

				case 5:
					move(buildPile5, destination, face, wSuit);
				break;

				case 6:
					move(buildPile6, destination, face, wSuit);
				break;

				case 7:
					move(buildPile7, destination, face, wSuit);
				break;

				case 8:
					move(cardPile1, destination, face, wSuit);
				break;

				case 9:
					move(cardPile2, destination, face, wSuit);
				break;

				case 10:
					move(cardPile3, destination, face, wSuit);
				break;

				case 11:
					move(cardPile4, destination, face, wSuit);
				break;

				case 12:
					move(deckPile2, destination, face, wSuit);
				break;
			}
		}
	}
}
void move(Deck *list, Deck *destination, int face, char *wSuit)
{
	printf("FLAG 3\n");
	int pos;
	printf("%i\t%s\n", face, wSuit);
	pos = searchCard(list, face, wSuit);
	printf("POSITION: %i\n", pos);

	swapCard(list, destination, pos);
}

int validateInsert(Deck *list, int face, char *wSuit, int atBuildPiles)
{
	printf("VALIDATE1\n");
	Card *checker = NULL;
	int currentSuit;
	int currentFace;

	if(list->size!=0)
	{
		checker = list->first;
		currentSuit = transformSuit(checker->suit);
		currentFace = checker->face;

		if(atBuildPiles == TRUE)
		{
			if(currentSuit % 2 == 1)
			{
				if(transformSuit(wSuit) % 2 == 0)
				{
					if(face == currentFace-1)
					{
						return TRUE;
					}
					else
					{
						return FALSE;
					}
				}
				else
				{
					return FALSE;
				}
			}
			else
			{
				if(transformSuit(wSuit) == currentSuit)
				{
					if(face == currentFace+1)
					{
						return TRUE;
					}
					else
					{
						return FALSE;
					}
				}
				else
				{
					return FALSE;
				}
			}
		}
		else
		{
				
		}
	}
	else
	{
		if(atBuildPiles == FALSE)
		{
			if(face == 1)
			{
				return TRUE;
			}
			else
			{
				return FALSE;
			}
		}
		else
		{
			if(face == 13)
			{
				return TRUE;
			}
			else
			{
				return FALSE;
			}
		}
	}
}

int findCard(int face, char *wSuit)
{
	printf("buildPile1\n");
	if(searchList(buildPile1, face, wSuit) == TRUE)
	{
		return 1;
	}
	
	printf("buildPile2\n");
	if(searchList(buildPile2, face, wSuit) == TRUE)
	{
		return 2;
	}
	
	printf("buildPile3\n");
	if(searchList(buildPile3, face, wSuit) == TRUE)
	{
		return 3;
	}
	
	printf("buildPile4\n");
	if(searchList(buildPile4, face, wSuit) == TRUE)
	{
		return 4;
	}
	
	printf("buildPile5\n");
	if(searchList(buildPile5, face, wSuit) == TRUE)
	{
		return 5;
	}
	
	printf("buildPile6\n");
	if(searchList(buildPile6, face, wSuit) == TRUE)
	{
		return 6;
	}
	
	printf("buildPile7\n");
	if(searchList(buildPile7, face, wSuit) == TRUE)
	{
		return 7;
	}
	
	printf("cardPile1\n");
	if(searchList(cardPile1, face, wSuit) == TRUE)
	{
		return 8;
	}
	
	printf("cardPile2\n");
	if(searchList(cardPile2, face, wSuit) == TRUE)
	{
		return 9;
	}
	
	printf("cardPile3\n");
	if(searchList(cardPile3, face, wSuit) == TRUE)
	{
		return 10;
	}
	
	printf("cardPile4\n");
	if(searchList(cardPile4, face, wSuit) == TRUE)
	{
		return 11;
	}

	printf("deckPile2\n");
	if(searchList(deckPile2, face, wSuit) == TRUE)
	{
		return 12;
	}
}

