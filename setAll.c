#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int if_set_all = 0; //A counter to set all
int set_all_value;

typedef struct 
{
	int value;
	int syncSetAll; //Cheking if the index set after set all 
}obj;

obj arr[20];

void get()
{
	int index;
	printf("Please enter an index number: ");
	scanf("%d", &index);

	if (arr[index].syncSetAll < if_set_all)
		printf("%d\n", set_all_value);
	else
		printf("%d\n", arr[index].value);
}

void set()
{
	int index, value;
	printf("Please enter an index number: ");
	scanf("%d", &index);
	printf("Please enter an value: ");
	scanf("%d", &value);

	arr[index].syncSetAll = if_set_all;
	arr[index].value = value;
}

void set_all()
{
	int value;
	printf("Please enter an value: ");
	scanf("%d", &value);
	if_set_all++;
	set_all_value = value;
}


void main()
{
	int choise = 0;
	while (1)
	{
		printf("For set an index please press 1\n");
		printf("For get an index value please press 2\n");
		printf("For set all indexes please press 3\n");

		scanf("%d", &choise);
		switch (choise)
		{
		case 1: 
		{
			set();
			break;
		}
		case 2:
		{
			get();
			break;
		}
		case 3:
		{
			set_all();
			break;
		}
		default:
			break;
		}
	}
}