#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 30

void array_fill(int* a, int size);
void array_copy(int* a, int* b, int size);

int main()
{
	int array1[SIZE], array2[SIZE];
	int i;

	array_fill(array1, SIZE);
	printf("array1 = [");
	for (i = 0; i<sizeof(array1) / sizeof(array1[0]); i++) {
		printf("%d ", array1[i]);
	}
	printf("]\n");

	array_copy(array1, array2, SIZE);
	printf("array2 = [");
	for (i = 0; i < sizeof(array2)/sizeof(array2[0]); i++) {
		printf("%d ", array2[i]);
	}
	printf("]\n");

	return 0;
}

void array_fill(int* a, int size) {
	srand((unsigned)time(NULL));

	for (int i = 0; i < size; i++) {
		a[i] = rand() % SIZE;
	}
}

void array_copy(int* a, int* b, int size) {
	for (int i = 0; i < size; i++) {
		b[i] = a[i];
	}
}