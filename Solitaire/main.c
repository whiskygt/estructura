#include <stdio.h>
#include <stdlib.h>
#include "deck.h"
#include "card.h"
#include "color.h"
#include "moves.h"
#include "lists.h"
#define TRUE 1
#define FALSE 0

//Inicializa las listas.
void startGame();

//Imprime las cartas.
int showGame();

//Reparte las cartas.
void dealCards();

//Establece si la carta debe de mostrarse o no mostrarse.
void hideCard();

//Muestra un menú con las opciones que posee el usuario.
int menu(int fMenu);

void startGame()
{
	startList(deckPile1);
	startList(deckPile2);
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

int showGame()
{
	system("clear");
	hideCard(FALSE);
	printf("----------------------------------------------------------------------------------\n");
	printf("Deck: ");
	showCardsDeck(deckPile2, cardPile1, cardPile2, cardPile3, cardPile4);
	//showCards(deckPile2);
	//showCards(cardPile1);
	//showCards(cardPile2);
	//showCards(cardPile3);
	//showCards(cardPile4);
	printf("Pila 1: ");
	showCardsBP(buildPile1);

	printf("Pila 2: ");
	showCardsBP(buildPile2);

	printf("Pila 3: ");
	showCardsBP(buildPile3);

	printf("Pila 4: ");
	showCardsBP(buildPile4);

	printf("Pila 5: ");
	showCardsBP(buildPile5);

	printf("Pila 6: ");
	showCardsBP(buildPile6);

	printf("Pila 7: ");
	showCardsBP(buildPile7);

	printf("----------------------------------------------------------------------------------\n");

	return 0;
}
void dealCards()
{
	startGame();

	deal(); 
	int i;
	int j;

	insert(buildPile1, deck[0].face, deck[0].suit, TRUE);
	insert(buildPile2, deck[1].face, deck[1].suit, TRUE);
	insert(buildPile3, deck[2].face, deck[2].suit, TRUE);
	insert(buildPile4, deck[3].face, deck[3].suit, TRUE);
	insert(buildPile5, deck[4].face, deck[4].suit, TRUE);
	insert(buildPile6, deck[5].face, deck[5].suit, TRUE);
	insert(buildPile7, deck[6].face, deck[6].suit, TRUE);

	insert(buildPile2, deck[7].face, deck[7].suit, TRUE);
	insert(buildPile3, deck[8].face, deck[8].suit, TRUE);
	insert(buildPile4, deck[9].face, deck[9].suit, TRUE);
	insert(buildPile5, deck[10].face, deck[10].suit, TRUE);
	insert(buildPile6, deck[11].face, deck[11].suit, TRUE);
	insert(buildPile7, deck[12].face, deck[12].suit, TRUE);

	insert(buildPile3, deck[13].face, deck[13].suit, TRUE);
	insert(buildPile4, deck[14].face, deck[14].suit, TRUE);
	insert(buildPile5, deck[15].face, deck[15].suit, TRUE);
	insert(buildPile6, deck[16].face, deck[16].suit, TRUE);
	insert(buildPile7, deck[17].face, deck[17].suit, TRUE);
	
	insert(buildPile4, deck[18].face, deck[18].suit, TRUE);
	insert(buildPile5, deck[19].face, deck[19].suit, TRUE);
	insert(buildPile6, deck[20].face, deck[20].suit, TRUE);
	insert(buildPile7, deck[21].face, deck[21].suit, TRUE);

	insert(buildPile5, deck[22].face, deck[22].suit, TRUE);
	insert(buildPile6, deck[23].face, deck[23].suit, TRUE);
	insert(buildPile7, deck[24].face, deck[24].suit, TRUE);

	insert(buildPile6, deck[25].face, deck[25].suit, TRUE);
	insert(buildPile7, deck[26].face, deck[26].suit, TRUE);

	insert(buildPile7, deck[27].face, deck[27].suit, TRUE);
			
	for(j=51; j>27; j--)
	{
		insert(deckPile1, deck[j].face, deck[j].suit, TRUE);	
	}

	hideCard(FALSE);
	
}

void hideCard(int choice)
{
	//setHidden(deckPile1, choice);
	setHidden(deckPile2, choice);
	setHidden(cardPile1, choice);
	setHidden(cardPile2, choice);
	setHidden(cardPile3, choice);
	setHidden(cardPile4, choice);
	setHidden(buildPile1, choice);
	setHidden(buildPile2, choice);
	setHidden(buildPile3, choice);
	setHidden(buildPile4, choice);
	setHidden(buildPile5, choice);
	setHidden(buildPile6, choice);
	setHidden(buildPile7, choice);
}

int menu(int fMenu)
{
	int eleccion;

  	switch (fMenu)
  	{
  		case 0:
  			showGame();
  			printf("Presione 0 para salir del programa. Presione 9 para salir al menú principal.\n");
  			printf("1. Siguiente carta del deck.\n");
  			printf("2. Mover carta.\n");
  			printf("3. Mostrar ayuda.\n");
  			printf("4. Guardar Juego\n");
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

void showTitle()
{
	system("clear");
	printf("%s", blue);
	printf("\n**********************************************************************************************************\n");
	printf("*     **********  **********  ***         ****  **********    ****     **********   ****  **********     *\n");
	printf("*     **********  **********  ***         ****  **********    *  *     ***    ***   ****  **********     *\n");
	printf("*     ****        ***    ***  ***         ****     ****      **  **    ***    ***   ****  ***    ***     *\n");
	printf("*     ****        ***    ***  ***         ****     ****      **  **    ***    ***   ****  ***    ***     *\n");
	printf("*     **********  ***    ***  ***         ****     ****      ******    **********   ****  ***    ***     *\n");
	printf("*     **********  ***    ***  ***         ****     ****     ********   ********     ****  ***    ***     *\n");
	printf("*            ***  ***    ***  ***         ****     ****     ***  ***   *******      ****  ***    ***     *\n");
	printf("*            ***  ***    ***  ***         ****     ****     ***  ***   *** ****     ****  ***    ***     *\n");
	printf("*     **********  **********  **********  ****     ****    ****  ****  ***  ****    ****  **********     *\n");
	printf("*     **********  **********  **********  ****     ****    ****  ****  ***   ****   ****  **********     *\n");
	printf("**********************************************************************************************************\n\n");
	printf("%s", none);
	printf("\n");
}

int main()
{
	system("mkdir SavedGames");

	struct timeval ti, tf;
	double elapsedTime;
	int finished=FALSE;
	int option;
	showTitle();

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

				//INICIA EL CRONÓMETRO.
				

				gettimeofday(&ti, NULL);

				while(option != 9)
				{
					if(finished)
					{
						break;
					}
					//showList(deckPile);
					option = menu(FALSE);
					if (option == 0)
					{
						break;
					}
					else
					{
						char uFace;
						char uSuit;
						char *suit;
						int face;
						int newPosition;
						switch(option)
						{
							case 1:
								//TODO:
								//IMPLEMENTAR CÓDIGO PARA PASAR A SIGUIENTE CARTA DEL DECK
								deckTransfer();
							break;

							case 2:
								printf("\nIngrese la carta que quiere mover: ");
								scanf("%s", &uFace);
								printf("\n");
								
								if(!strcmp(&uFace, "A"))
								{
									face = 1;
								}
								else if(!strcmp(&uFace, "J"))
								{
									face = 11;
								}
								else if(!strcmp(&uFace, "Q"))
								{
									face = 12;
								}
								else if(!strcmp(&uFace, "K"))
								{
									face = 13;
								}
								else if(!strcmp(&uFace, "10"))
								{
									face = 10;
								}
								else
								{
									face = uFace-48;
									if(face<1 || face>13) 
									{
										printf("Carta no movida.\n");
										break;
									}
								}

								printf("\nFACE: %i\n", face);
								printf("\nIngrese el palo de la carta que quiere mover: ");
								scanf("%s", &uSuit);
								getchar();
								suit = &uSuit;
								printf("\nFACE: %i, SUIT: %s\n", face, suit);

								printf("Ingrese hacia donde quiere mover la carta: ");
								scanf("%i", &newPosition);
								
								printf("\nNew:%i\n", newPosition);

								switch(newPosition)
								{
									case 1:
										moveCard(buildPile1, face, suit, TRUE);
										printf("\nNew:%i\n", newPosition);
									break;

									case 2:
										moveCard(buildPile2, face, suit, TRUE);
										printf("\nNew:%i\n", newPosition);
									break;

									case 3:
										moveCard(buildPile3, face, suit, TRUE);
										printf("\nNew:%i\n", newPosition);
									break;

									case 4:
										moveCard(buildPile4, face, suit, TRUE);
										printf("\nNew:%i\n", newPosition);
									break;

									case 5:
										moveCard(buildPile5, face, suit, TRUE);
										printf("\nNew:%i\n", newPosition);
									break;

									case 6:
										moveCard(buildPile6, face, suit, TRUE);
										printf("\nNew:%i\n", newPosition);
									break;

									case 7:
										moveCard(buildPile7, face, suit, TRUE);
										printf("\nNew:%i\n", newPosition);
									break;

									case 8:
										moveCard(cardPile1, face, suit, FALSE);
										if(gameFinished())
										{
											printf("Felicidades, ha ganado el juego\n");
											finished = TRUE;
										}
										printf("\nNew:%i\n", newPosition);
									break;

									case 9:
										moveCard(cardPile2, face, suit, FALSE);
										if(gameFinished())
										{
											printf("Felicidades, ha ganado el juego\n");
											finished = TRUE;
										}
										printf("\nNew:%i\n", newPosition);
									break;

									case 10:
										moveCard(cardPile3, face, suit, FALSE);
										if(gameFinished())
										{
											printf("Felicidades, ha ganado el juego\n");
											finished = TRUE;
										}
										printf("\nNew:%i\n", newPosition);
									break;

									case 11:
										moveCard(cardPile4, face, suit, FALSE);
										if(gameFinished())
										{
											printf("Felicidades, ha ganado el juego\n");
											finished = TRUE;
										}
										printf("\nNew:%i\n", newPosition);
									break;

									default:
									break;
								}

								printf("\nFACE: %i, SUIT: %s, LIST: %i\n", face, suit, newPosition);
							break;

							case 3:
								//TODO:
								//Implementar método para mostrar ayuda, también será usado en el menú principal.
							break;

							case 4:
								saveFile(buildPile1, buildPile2, buildPile3, buildPile4, buildPile5, buildPile6, buildPile7, cardPile1, cardPile2, cardPile3, cardPile4, deckPile1, deckPile2);
						}
					}
				}
			break;

			//TODO: Add help here.
			case 2:
				printf("AÑADIR AYUDA\n");
				option = 1;
			break;

			case 3: 
				gettimeofday(tf, NULL);
				elapsedTime = ((tf.tv_sec - ti.tv_sec)*1000 + (tf.tv_usec - ti.tv_usec))/1000.0;
				printf("\nTiempo de ejecución %f\n", elapsedTime);
				getchar();
				exit(1);
			break;

			default: 
				printf("Ingrese una opción correcta.\n\n");
				getchar();
			break;
		}
		if(option == 0)
		{
			gettimeofday(&tf, NULL);
			elapsedTime = (tf.tv_sec - ti.tv_sec)*1000 + (tf.tv_usec - ti.tv_usec)/1000.0;
			printf("\nTiempo de ejecución %f segundos.\n", elapsedTime/1000);
			getchar();
		}
	}
	return 0;
}



