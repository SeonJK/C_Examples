#include <stdio.h>
#pragma warning(disable:4996)

int main()
{
	int array[3][10] = { 1,2,3,4,5,6,7,8,9,10 };
	int i, num, result=0;

	for (i = 0; i < 10; i++) {
		array[1][i] = array[0][i] * array[0][i];
		array[2][i] = array[0][i] * array[0][i] * array[0][i];
	}

	printf("������ �Է��Ͻÿ�: ");
	scanf("%d", &num);

	for (i = 0; i < 10; i++) {
		if (num == array[2][i]) {
			result = num / array[1][i];
			printf("%d�� ���������� %d�Դϴ�.\n\n", num, result);
		}
	}
	if (result == 0) {
		printf("�Է��� ���ڰ� ������ �迭 �࿡ �����ϴ�.\n\n");
	}
	
	for (i = 0; i < 3; i++) {
		printf("[");
		for (int j = 0; j < 10; j++) {
			printf("%d", array[i][j]);
			printf("\t");
		}
		printf("]\n");
	}

	return 0;
}