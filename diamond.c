#pragma warning(disable:4996)
#include <stdio.h>

int main()
{
	int line = 2;

	while (line % 2 == 0) {
		printf("높이를 입력해주세요.(홀수): ");
		scanf("%d", &line);
	}
	
	for (int i = 1; i <= (line / 2 ); i++) {
		for (int j = 0; j <= (line/2 - i); j++) {
			printf(" ");
		}
		for (int k = 1; k <= (2 * i - 1); k++) {
			printf("*");
		}
		printf("\n");
	}

	for (int x = 0; x <= (line / 2 + 1); x++) {
		for (int z = 1; z <= x; z++) {
			printf(" ");
		}
		for (int y = 1; y <= (2 * ((line/2 + 1) - x) - 1); y++) {
			printf("*");
		}
		printf("\n");
	}

	return 0;
}