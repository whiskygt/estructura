#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#define lenght 20
#define arraySize 13

int lenght;

//Función que contiene un temporizador.
void timer(float sec);

//Permite mostrar una "animación "de carga.
void loading(float time);

void timer(float sec)
{
	clock_t end;
	end = clock() + sec + CLOCKS_PER_SEC;
	while (clock() < end){}
	sec=0;
}

void loading(float time)
{
	int i;
	int percent = 20;
	char barra[arraySize]={'[',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ', ']'};
	float sec = time/10;
	timer(sec);
	//printf("%f\n", time);
	//printf("%f\n", sec);

	for(i=1; i<11; i=i+2)
	{
		int j;
		barra[i]='-';
		barra[i+1]='-';

		for(j=0; j<arraySize; j++)
		{
			printf("%c", barra[j]);
		}
		printf(" %d%%\n", percent);
		percent = percent + 20;
		timer(sec);
	}
}

int main()
{
	lenght = 20;

	int array[lenght];
	char elements[lenght];
	int data;
	int i=0;

	data=-1;

	printf("\nIntroduzca hasta 20 números. Presione 0 para dejar de introducir.");
	
	while(data!=0)
	{
		printf("\nNúmeros introducidos: %i", i);
		printf("\nNúmero a introducir: ");
		scanf("%d", &data);
		//getchar();

		array[i]=data;
		
		if(i==lenght)
		{
			break;
		}	
		i++;
	}

	int j;
	for(j=0; j<lenght; j++)
	{
		elements[j]=array[j];
	}

	elements[i]='\0';

	printf("\n\nPor favor espere, copiando arreglo.\n");
	loading(1);


	printf("\n%s", elements);
	printf("\n");

	return 0;
}