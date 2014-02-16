#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int [][13]);
void deal(const int [][13], const char *[], const char *[]);

void shuffle(int wDeck[][13])
{
	int card, row, column;

	for(card=1; card<=52; card++)
	{
		//printf("Bandera 4");
		row = rand() % 4;
		column = rand() % 13;

		//printf("Fila: %i.\tColumna: %i\n", row, column);

		while(wDeck[row][column]!=0)
		{
			//printf("En el while.");
			row = rand() % 4;
			column = rand() % 13;
		}
		//printf("Bandera 5");
		wDeck[row][column]=card;
	}
}

void deal(const int wDeck[][13], const char *wPalo[], const char *wCarta[])
{
	int card, row, column;

	for(card=1; card<=52; card++)
	{
		for (row=0; row <= 3; row++)
		{
			for (column = 0; column<=12; column++)
			{
				if (wDeck[row][column] == card)
				{
					//printf("Bandera 6");
					printf("%5s de %-8s%c", wCarta[column], wPalo[row], card % 2 == 0 ? '\n' : '\t');
				}
			}
		}
	}
}

int main()
{
	printf("Bandera 1\n");
	char *palo[4]={"Corazones", "Espadas", "Diamantes", "Treboles"};
	char *carta[13]={"As", "Dos", "Tres", "Cuatro", "Cinco", "Seis", "Siete", "Ocho", "Nueve", "Diez", "Jack", "Reina", "Rey"};
	
	int deck[4][13]={0};

	printf("Bandera 2\n");

	srand(time(NULL));

	printf("Bandera 3\n");
	shuffle(deck);

	printf("Bandera 4\n");
	deal(deck, palo, carta);
	

	return 0;
}

