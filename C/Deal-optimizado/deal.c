#include <stdio.h>
#include <stdlib.h>

typedef struct Card
{
	char *face;
	char *suit;
}Card;

void fillDeck(Card *wDeck, char *wFace[], char *wSuit[])
{
	int i;

	for (i = 0; i <= 51; i++ )
	{
		wDeck[i].face = wFace[i % 13];
		wDeck[i].suit = wSuit[i / 13];
	}
}

void shuffleDeck(Card *wDeck)
{
	int i, j;
	Card temp;

	for (i=0; i <= 51; i++)
	{
		j = rand() % 52;
		temp = wDeck[i];
		wDeck[i] = wDeck[j];
		wDeck[j] = temp;
	}
}

void showCards(Card *wDeck)
{
	int i;

	for(i = 0; i <=51; i++)
	{
		printf("%5s de %8s%c", wDeck[i].face, wDeck[i].suit, (i+1) % 2 ? '\t' : '\n');
	}
}

int main()
{
	Card deck[52];
	char *face[] = {"As", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Reina", "Rey"};
	char *suit[] = {"Corazones", "Espadas", "Treboles", "Diamantes"};

	srand(time(NULL));

	fillDeck(deck, face, suit);
	shuffleDeck(deck);
	showCards(deck);
}