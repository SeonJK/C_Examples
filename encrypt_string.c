#include <stdio.h>
#pragma warning(disable:4996)
#define SIZE 50

void encrypt(char c[], int shift);

int main()
{
	char cipher[SIZE];
	int shift = 3;
	printf("���ڿ��� �Է��Ͻÿ�: ");
	gets(cipher, SIZE);
	encrypt(cipher, shift);
	printf("��ȣȭ�� ���ڿ�: %s\n", cipher);

	return 0;
}

void encrypt(char c[], int shift) {
	int i = 0;
	while (c[i] != '\0') {
		if ('A' <= c[i] && c[i] <= 'Z') {
			c[i] += shift;
			if (c[i] > 'Z') {
				c[i] -= 26;
			}
			else if (c[i] < 'A') {
				c[i] += 26;
			}
		}else if ('a' <= c[i] && c[i] <= 'z') {
			c[i] += shift;
			if (c[i] > 'z') {
				c[i] -= 26;
			}
			else if (c[i] < 'a') {
				c[i] += 26;
			}
		}
		i++;
	}
}