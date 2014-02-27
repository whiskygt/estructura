#ifndef CARD_H
#define CARD_H

typedef struct Card
{
	char *face;
	char *suit;
	int hidden;
	struct Card *next;
	struct Card *previous;
}Card;

#endif