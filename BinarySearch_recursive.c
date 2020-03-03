#include <stdio.h>
#pragma warning(disable:4996)
#define SIZE 16

int recursive(int list[], int low, int high, int key);

int main()
{
	int key, isIn = 0;
	int grade[SIZE] = { 2, 6, 11, 13, 18, 20, 22, 27, 29, 30, 34, 38, 41, 42, 45, 47};

	printf("탐색할 값을 입력하시오: ");
	scanf("%d", &key);

	for (int i = 0; i < SIZE; i++) {
		if (grade[i] == key) {
			isIn = 1;
			break;
		}
	}
	if (!isIn) {
		printf("입력하신 값이 배열에 존재하지 않습니다.\n");
	}
	else {
		printf("탐색결과= %d\n", recursive(grade, 0, SIZE - 1, key));
	}
	return 0;
}

int recursive(int list[], int low, int high, int key) {
	int middle = (low + high) / 2;

	printf("[%d %d]\n", low, high);

	if (key == list[middle]) {
		return middle;
	}
	else if (key > list[middle]) {
		return recursive(list, middle + 1, high, key);
	}
	else { return recursive(list, low, middle - 1, key); }
}
