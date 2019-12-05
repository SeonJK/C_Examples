#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rcp();

int main()
{
	int rock = 0, cissor = 0, paper = 0; // rock = 바위, cissor = 가위, paper = 보
	srand((unsigned)time(NULL));

	for (int i = 0; i < 100; i++) {
		if (rcp() == 0) {
			rock++;
		}
		else if (rcp() == 1) {
			cissor++;
		}
		else {
			paper++;
		}
	}

	printf("가위 = %d, 바위 = %d, 보 = %d\n", cissor, rock, paper);

	return 0;
}

int rcp() {
	int result = rand() % 3;
	if (result == 0) {
		return 0;
	}
	else if (result == 1) {
		return 1;
	}
	else {
		return 2;
	}
}