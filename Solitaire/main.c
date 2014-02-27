#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#define TRUE 1
#define FALSE 0

//Listas Usadas
Deck *deckPile1;
Deck *deckPile2;
Deck *cardPile1;  
Deck *cardPile2;
Deck *cardPile3;
Deck *cardPile4;
Deck *buildPile1;
Deck *buildPile2;
Deck *buildPile3;
Deck *buildPile4;
Deck *buildPile5;
Deck *buildPile6;
Deck *buildPile7;

//Muestra un menú con las opciones que posee el usuario.
int menu(int fMenu);

//Imprime las cartas.
int showCards();

//Reparte las cartas.
void dealCards();

//Inicializa las listas.
void startGame();

void dealCards()
{
	
	printf("FLAG 1\n");
	startGame();
	//startList(deckPile);


	printf("FLAG 2\n");
	deal(); 
	int i;
	i = 0;
	int j;
	printf("FLAG 3\n");
	printf("FLAG 3.1\n");
	while(i < 8)
	{
		printf("FLAG 4");
		printf("FLAG 4");
		printf("FLAG 4");
		switch(i)
		{
			printf("FLAGGGG");
			case 0:
				printf("FLAG 5");
				insert(buildPile1, deck[0].face, deck[0].suit, TRUE);
				insert(buildPile2, deck[1].face, deck[1].suit, TRUE);
				insert(buildPile3, deck[2].face, deck[2].suit, TRUE);
				insert(buildPile4, deck[3].face, deck[3].suit, TRUE);
				insert(buildPile5, deck[4].face, deck[4].suit, TRUE);
				insert(buildPile6, deck[5].face, deck[5].suit, TRUE);
				insert(buildPile7, deck[6].face, deck[6].suit, TRUE);
			break;

			case 1:
				insert(buildPile2, deck[7].face, deck[7].suit, TRUE);
				insert(buildPile3, deck[8].face, deck[8].suit, TRUE);
				insert(buildPile4, deck[9].face, deck[9].suit, TRUE);
				insert(buildPile5, deck[10].face, deck[10].suit, TRUE);
				insert(buildPile6, deck[11].face, deck[11].suit, TRUE);
				insert(buildPile7, deck[12].face, deck[12].suit, TRUE);
			break;

			case 2:
				insert(buildPile3, deck[13].face, deck[13].suit, TRUE);
				insert(buildPile4, deck[14].face, deck[14].suit, TRUE);
				insert(buildPile5, deck[15].face, deck[15].suit, TRUE);
				insert(buildPile6, deck[16].face, deck[16].suit, TRUE);
				insert(buildPile7, deck[17].face, deck[17].suit, TRUE);
			break;

			case 3:
				insert(buildPile4, deck[18].face, deck[18].suit, TRUE);
				insert(buildPile5, deck[19].face, deck[19].suit, TRUE);
				insert(buildPile6, deck[20].face, deck[20].suit, TRUE);
				insert(buildPile7, deck[21].face, deck[21].suit, TRUE);
			break;

			case 4: 
				insert(buildPile5, deck[22].face, deck[22].suit, TRUE);
				insert(buildPile6, deck[23].face, deck[23].suit, TRUE);
				insert(buildPile7, deck[24].face, deck[24].suit, TRUE);
			break; 

			case 5:
				insert(buildPile6, deck[25].face, deck[25].suit, TRUE);
				insert(buildPile7, deck[26].face, deck[26].suit, TRUE);
			break;

			case 6:
				insert(buildPile7, deck[27].face, deck[27].suit, TRUE);
			break;

			case 7:
				for(j=52; j>28; j++)
				{
					printf("FLAG 4\n");
					insert(deckPile1, deck[j].face, deck[j].suit, TRUE);	
				}
			break;
		}
		i++;
	}
	
	showList(deckPile1);
}

int showDeck()
{
	
}

int menu(int fMenu)
{
	int eleccion;

  	switch (fMenu)
  	{
  		case 0:
  			printf("Presione 0 para salir del programa. Presione 9 para salir al menú principal.\n");
  			printf("1. Mover carta del deck.\n");
  			printf("2. Mover carta a las Pilas de Palos.\n");
  			printf("3. Mover carta en las Pilas de construcción.\n");
  		break;

  		case 1:
  			printf("1. Iniciar Juego.\n");
  			printf("2. Ayuda.\n");
  			printf("3. Salir.\n");
  		break;
  	}
  	
  	printf ("\nSu opción: ");
  	scanf ("%i", &eleccion);
  	getchar();
    printf("\n");
  	
  	if(fMenu == 1 && eleccion == 3) eleccion = 0;
  	
  	return eleccion;
}


int main()
{
	int option;

	deckPile1 = (Deck *) malloc(sizeof(Deck));
	deckPile2 = (Deck *) malloc(sizeof(Deck));
	cardPile1 = (Deck *) malloc(sizeof(Deck));
	cardPile2 = (Deck *) malloc(sizeof(Deck));
	cardPile3 = (Deck *) malloc(sizeof(Deck));
	cardPile4 = (Deck *) malloc(sizeof(Deck));
	buildPile1 = (Deck *) malloc(sizeof(Deck));
	buildPile2 = (Deck *) malloc(sizeof(Deck));
	buildPile3 = (Deck *) malloc(sizeof(Deck));
	buildPile4 = (Deck *) malloc(sizeof(Deck));
	buildPile5 = (Deck *) malloc(sizeof(Deck));
	buildPile6 = (Deck *) malloc(sizeof(Deck));
	buildPile7 = (Deck *) malloc(sizeof(Deck));

	printf("Solitario desarrollado por LuisFer Arévalo.\n\n");
	option = 1;
	//printf("Opción: %s", (char)option);
	while (option != 0)
	{
		option = menu(TRUE);
		switch (option)
		{
			case 1:
				dealCards();
				while(option != 9)
				{
					//showList(deckPile);
					option = menu(FALSE);
					if (option == 0)
					{
						break;
					}
					else
					{
						
					}
				}
			break;

			//TODO: Add help here.
			case 2:
				printf("AÑADIR AYUDA\n");
				option = 1;
			break;

			case 3: exit(1);
			break;
		}
	}
	return 0;
}

void startGame()
{
	startList(deckPile1);
	startList(deckPile2);
	printf("flag 2\n");
	startList(cardPile1);
	startList(cardPile2);
	startList(cardPile3);
	startList(cardPile4);
	startList(buildPile1);
	startList(buildPile2);
	startList(buildPile3);
	startList(buildPile4);
	startList(buildPile5);
	startList(buildPile6);
	startList(buildPile7);
}