#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>						//ȭ��ٲ��� ���� ���
#include<string.h>						//strcmp, strcpy

typedef struct{							//����ü ����
	char name[100];
	int age;
	char number[100];
} phoneBook;

void Input(phoneBook* ptr, int* num);
void Output(phoneBook* ptr, int* num);
void Search(phoneBook* ptr, int* num);
void Delete(phoneBook* ptr, int* num);

int main()
{
	phoneBook pb1[100];					//���� 100�� ����ü�迭 ����
	int c;
	int num = 0;						//�迭�� ���� ���� ����

	while(1){
		printf("��ȭ��ȣ��\n");
		printf("---------------------------------\n");
		printf("1.�Է� 2.��� 3.�˻� 4.���� 5.����\n");
		printf("����: ");
		scanf("%d", &c);

		switch (c)						//�Էµ� ���ڸ� ������ �Լ� ����
		{
		case 1:							//�Է�
			system("cls");
			Input(pb1, &num);
			break;
		case 2:							//���
			system("cls");
			Output(pb1, &num);
			break;
		case 3:							//�˻�
			system("cls");
			Search(pb1, &num);
			break;
		case 4:							//����
			system("cls");
			Delete(pb1, &num);
			break;
		case 5:							//����
			return 0;
		default:						//����ó��
			system("cls");
			printf("1-5�� ���ڸ� �Է��ϼ���.\n");
			system("pause");
			break;
		}
	}
}

void Input(phoneBook* ptr, int* num)				//Input �Լ�
{
	if (*num < 100) {
		printf("�̸�: ");
		scanf("%s", ptr[*num].name);
		printf("����: ");
		scanf("%d", &ptr[*num].age);
		printf("��ȣ: ");
		scanf("%s", ptr[*num].number);
		printf("\n�ԷµǾ����ϴ�.\n");

		(*num)++;
	}else{
		printf("�� �̻� �Է��� �� �����ϴ�!\n");
	}
	
	system("pause");
	system("cls");
	return;
}

void Output(phoneBook* ptr, int* num)				//Output �Լ�
{
	printf("��°��\n");
	printf("------------------------------\n");

	if (*num == 0) {
		printf("����ó�� ����ֽ��ϴ�.\n");
		system("pause");
		system("cls");
		return;
	}

	printf("NUM		�̸�		����		��ȣ\n");
	
	for (int i = 0; i < *num; i++) {
		printf("%d		%s		%d		%s\n", i+1, ptr[i].name, ptr[i].age, ptr[i].number);
	}

	system("pause");
	system("cls");
	return ;
}

void Search(phoneBook* ptr, int* num)				//Search �Լ�
{
	int s1 =0, s3 =0;							//s1���� �˻�����, s2/s3�� �˻����ؿ� ���� �����˻�
	char s2[100];
	int cnt = 0;						//�����˻��� �˻��Ǽ� ����

	printf("<�˻�>\n");

	if (*num == 0) {
		printf("����ó�� ����ֽ��ϴ�.\n");
		system("pause");
		system("cls");
		return;
	}

	printf("������ �������� ã���ðڽ��ϱ�?\n\n");
	printf("1.�̸�	2.����	3.��ȭ��ȣ	5.���ư���\n\n");
	printf("�Է�: ");
	scanf("%d", &s1);

	switch (s1) {					
		case 1:							//�̸��� �������� �˻�
			printf("�̸�: ");
			scanf("%s", &s2);
			system("cls");
		
			printf("�˻����\n");
			printf("--------------------------------\n");
			printf("NUM		�̸�		����		��ȣ\n");

			for (int i = 0; i < *num; i++) {
				if (strcmp(s2, ptr[i].name) == 0) {
					printf("%d		%s		%d		%s\n", cnt+1, ptr[i].name, ptr[i].age, ptr[i].number);
					cnt++;
				}
				else {
					continue;
				}
			}

			printf("==%d �� �˻��Ǿ����ϴ�.==\n", cnt);
			break;
		case 2:							//���̸� �������� �˻�
			printf("����: ");
			scanf("%d", &s3);
			system("cls");

			printf("�˻����\n");
			printf("--------------------------------\n");
			printf("NUM		�̸�		����		��ȣ\n");
			
			for (int i = 0; i < *num; i++) {
				if (s3 == ptr[i].age) {
					printf("%d		%s		%d		%s\n", i + 1, ptr[i].name, ptr[i].age, ptr[i].number);
					cnt++;
				}
				else {
					continue;
				}
			}

			printf("==%d �� �˻��Ǿ����ϴ�.==\n", cnt);
			break;
		case 3:							//��ȭ��ȣ�� �������� �˻�
			printf("��ȭ��ȣ: ");
			scanf("%s", &s2);
			system("cls");

			printf("�˻����\n");
			printf("--------------------------------\n");
			printf("NUM		�̸�		����		��ȣ\n");

			for (int i = 0; i < *num; i++) {
				if (strcmp(s2, ptr[i].number) == 0) {
					printf("%d		%s		%d		%s\n", i + 1, ptr[i].name, ptr[i].age, ptr[i].number);
					cnt++;
				}
				else {
					continue;
				}
			}

			printf("==%d �� �˻��Ǿ����ϴ�.==", cnt);
			break;
		case 5:							//���ư���
			return ;
		default:						//����ó��
			printf("1,2,3,5�� ���ڸ� �Է����ּ���.\n");
			exit(1);
	}
	system("pause");
	system("cls");
}

void Delete(phoneBook* ptr, int* num)				//Delete �Լ�
{
	int r1, r3, r4, i;					//r1���� ��������, r2/r4�� ���ؿ� ���� �����˻�, r3�� ������ ��������
	char r2[100];
	char r5[100];						//r4�� �������� ����
	int tmp[100];						//�˻��� ���� NUM ����
	int cnt = 0;						//�����˻��� �˻��Ǽ� ����
	int tnum = 0;						//tmp�迭�� ���� ����
	

	printf("<����>\n");

	if (*num == 0) {
		printf("����ó�� ����ֽ��ϴ�.\n");
		system("pause");
		system("cls");
		return;
	}

	printf("������ �������� ã���ðڽ��ϱ�?\n\n");
	printf("1.�̸�	2.����	3.��ȭ��ȣ	etc.���ư���\n\n");
	printf("�Է�: ");
	scanf("%d", &r1);

	switch (r1) {
	case 1:								//�̸��� �������� �˻�
		printf("�̸�: ");
		scanf("%s", &r2);
		system("cls");

		printf("�˻����\n");
		printf("--------------------------------\n");
		printf("NUM		�̸�		����		��ȣ\n");

		for (i = 0; i < *num; i++) {					//�Է��� ���� ���� �������
			if (strcmp(r2, ptr[i].name) == 0) {
				printf("%d		%s		%d		%s\n", i + 1, ptr[i].name, ptr[i].age, ptr[i].number);
				cnt++;
				tmp[tnum] = i + 1;
				tnum++;
			}
		}

		printf("==%d �� �˻��Ǿ����ϴ�.==\n", cnt);

		if (cnt == 0) {									//0���� �˻��� ��� Delete�Լ� ����
			system("pause");
			system("cls");
			return ;
		}

		printf("--------------------------------\n");
		printf("������ ���� NUM�� �Է����ּ���: ");
		scanf("%d", &r3);

		for (i = 0; i < tnum; i++) {					//�˻��� NUM�� �ƴ� �ٸ� NUM�� �Է��� ��� Delete�Լ� ����
			if (r3 == tmp[i]) {
				continue;
			}
			else {
				system("cls");
				printf("�ùٸ� NUM�� �Է����ּ���.\n");
				system("pause");
				system("cls");
				return;
			}
		}

		printf("\n--------------------------------\n");
		printf("������ ����ðڽ��ϱ�?(Y/N) : ");
		scanf("%s", &r5);
			
		if (r5 == "y" || "Y") {							//�������� ����
			for (i = r3-1; i < *num; i++) {
				strcpy(ptr[i].name, ptr[i + 1].name);
				ptr[i].age = ptr[i + 1].age;
				strcpy(ptr[i].number, ptr[i + 1].number);
			}
			*ptr[*num-1].name = NULL;
			ptr[*num-1].age = NULL;
			*ptr[*num-1].number = NULL;

			(*num)--;
			
			system("cls");
			printf("�ش� ������ �����Ǿ����ϴ�.\n");
			system("pause");
		}
		else if (r5 == "n" || "N") {
			system("cls");
			return ;
		}
		else {
			system("pause");
			system("cls");
			printf("����ε� ���� �Է����ּ���.");
		}
		break;

	case 2:												//���̸� �������� �˻�
		printf("����: ");
		scanf("%d", &r4);
		system("cls");

		printf("�˻����\n");
		printf("--------------------------------\n");
		printf("NUM		�̸�		����		��ȣ\n");

		for (int i = 0; i < *num; i++) {				//�Է��� ���� ���� �������
			if (r4 == ptr[i].age) {
				printf("%d		%s		%d		%s\n", i + 1, ptr[i].name, ptr[i].age, ptr[i].number);
				cnt++;
			}
		}

		printf("==%d �� �˻��Ǿ����ϴ�.==\n", cnt);

		if (cnt == 0) {									//0���� �˻��� ��� Delete�Լ� ����
			system("pause");
			system("cls");
			return;
		}

		printf("--------------------------------\n");
		printf("������ ���� NUM�� �Է����ּ���: ");
		scanf("%d", &r3);

		for (i = 0; i < tnum; i++) {					//�˻��� NUM�� �ƴ� �ٸ� NUM�� �Է��� ��� Delete�Լ� ����
			if (r3 == tmp[i]) {
				continue;
			}
			else {
				system("cls");
				printf("�ùٸ� NUM�� �Է����ּ���.\n");
				system("pause");
				system("cls");
				return;
			}
		}

		printf("\n--------------------------------\n");
		printf("������ ����ðڽ��ϱ�?(Y/N) : ");
		scanf("%s", &r5);

		if (r5 == "y" || "Y") {			//�������� ����
			for (i = r3-1; i < *num; i++) {
				strcpy(ptr[i].name, ptr[i + 1].name);
				ptr[i].age = ptr[i + 1].age;
				strcpy(ptr[i].number, ptr[i + 1].number);
			}
			*ptr[*num-1].name = NULL;
			ptr[*num-1].age = NULL;
			*ptr[*num-1].number = NULL;

			(*num)--;

			system("cls");
			printf("�ش� ������ �����Ǿ����ϴ�.\n");
			system("pause");
		}
		else if (r5 == "n" || "N") {
			system("cls");
			return;
		}
		else {
			system("cls");
			printf("����ε� ���� �Է����ּ���.\n");
		}

		break;
	case 3:								//��ȭ��ȣ�� �������� �˻�
		printf("��ȭ��ȣ: ");
		scanf("%s", &r2);
		system("cls");

		printf("�˻����\n");
		printf("--------------------------------\n");
		printf("NUM		�̸�		����		��ȣ\n");

		for (int i = 0; i < *num; i++) {				//�Է��� ���� ���� �������
			if (strcmp(&r2, ptr[i].number) == 0) {
				printf("%d		%s		%d		%s\n", i + 1, ptr[i].name, ptr[i].age, ptr[i].number);
				cnt++;
			}
		}

		printf("==%d �� �˻��Ǿ����ϴ�.==\n", cnt);

		if (cnt == 0) {									//0���� �˻��� ��� Delete�Լ� ����
			system("cls");
			return;
		}

		printf("--------------------------------\n");
		printf("������ ���� NUM�� �Է����ּ���: ");
		scanf("%d", &r3);

		for (i = 0; i < tnum; i++) {					//�˻��� NUM�� �ƴ� �ٸ� NUM�� �Է��� ��� Delete�Լ� ����
			if (r3 == tmp[i]) {
				continue;
			}
			else {
				system("cls");
				printf("�ùٸ� NUM�� �Է����ּ���.\n");
				system("pause");
				system("cls");
				return;
			}
		}

		printf("\n--------------------------------\n");
		printf("������ ����ðڽ��ϱ�?(Y/N) : ");
		scanf("%s", &r5);

		if (r5 == "y" || "Y") {			//�������� ����
			for (i = r3-1; i < *num; i++) {
				strcpy(ptr[i].name, ptr[i + 1].name);
				ptr[i].age = ptr[i + 1].age;
				strcpy(ptr[i].number, ptr[i + 1].number);
			}
			*ptr[*num-1].name = NULL;
			ptr[*num-1].age = NULL;
			*ptr[*num-1].number = NULL;

			(*num)--;

			system("cls");
			printf("�ش� ������ �����Ǿ����ϴ�.\n");
			system("pause");
		}
		else if (r5 == "n" || "N") {
			system("cls");
			return;
		}
		else {
			system("cls");
			printf("����ε� ���� �Է����ּ���.\n");
		}

		break;
	default:						//���ذ˻��� ���� ����ó��
		exit(1);
	}
}