#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

int main()
{
	srand((unsigned)time(NULL));

	int list[20];
	int i, j, temp, least;

	for (i = 0; i < SIZE; i++) {
		int data = rand() % 20 + 1;
		list[i] = data;
	}


	for (i = 0; i < SIZE - 1; i++) {
		least = i;
		for (j = i+1; j < SIZE; j++) {
			if (list[j] > list[least])
				least = j;
		}

		temp = list[i];
		list[i] = list[least];
		list[least] = temp;
	}
	
	for (i = 0; i < SIZE; i++) {
		printf("%d ", list[i]);
	}
	printf("\n");

	return 0;
}