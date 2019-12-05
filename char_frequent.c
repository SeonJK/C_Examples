#include <stdio.h>
#pragma warning(disable:4996)
#define SIZE 50

void str_char(char s[], int a[]);

int main()
{
	char c[SIZE];
	int a[26] = { 0, };

	printf("문자열을 입력하시오: ");
	gets(c, SIZE);
	str_char(c, a);

	for (int i = 0; i < 26; i++) {
		if (a[i] == 0) { continue; }
		printf("%c = %d\n", i + 97, a[i]);
	}

	return 0;
}

void str_char(char s[], int a[]) {
	int i = 0;

	while (s[i] != '\0') {
		if ('A' <= s[i] && s[i] <= 'Z') {
			a[s[i] - 65]++;
		}
		else if ('a' <= s[i] && s[i] <= 'z') {
			a[s[i] - 97]++;
		}
		i++;
	}
}