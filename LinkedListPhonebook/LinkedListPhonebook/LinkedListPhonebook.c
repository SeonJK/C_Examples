#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>									//malloc, free
#include<windows.h>									//ȭ��ٲ��� ���� ���
#include<string.h>									//strcmp, strcpy

typedef struct pbNode{								//��� ����ü����
	char name[20];
	int age;
	char number[20];
	struct pbNode* next;
	struct pbNode* prev;
} pbNode;

 pbNode *head, *tail, *tmp;
 int count;

void Init();
void Input();
void Output();
void Search();
void Lookup();
void Delete();

int main() {										//Main ��
	int choice;	

	Init();
	while (1) {
		printf("��ȭ��ȣ��\n");
		printf("------------------------------------------\n");
		printf("1.�Է� 2.��� 3.�˻� 4.Ž�� 5.���� 6.����\n");
		printf("����: ");
		scanf("%d", &choice);
			
		switch (choice)								//�Էµ� ���ڸ� ������ �Լ� ����
		{
		case 1:										//�Է�
			system("cls");
			Input();
			break;
		case 2:										//���
			system("cls");
			Output();
			break;
		case 3:										//�˻�
			system("cls");
			Search();
			break;
		case 4:										//Ž��
			system("cls");
			Lookup();
			break;
		case 5:										//����
			system("cls");
			Delete();
			break;
		case 6:										//����
			return 0;
		default:									//����ó��
			system("cls");
			printf("1-6�� ���ڸ� �Է��ϼ���.\n");
			system("pause");
			break;
		}
	}
}

void Init() {										//��� �ʱ⼳��
	head = (pbNode*)malloc(sizeof(pbNode));
	tail = (pbNode*)malloc(sizeof(pbNode));
	
	head->prev = head;
	head->next = tail;
	tail->prev = head;
	tail->next = tail;

	count = 0;
}

void Input() {										//�����Լ�
	pbNode* new_node;
	new_node = (pbNode*) malloc(sizeof(pbNode));
	new_node->next = NULL;
	new_node->prev = NULL;

	printf("<����>\n");
	printf("�̸�: ");
	scanf("%s", new_node->name);
	printf("����: ");
	scanf("%d", &new_node->age);
	printf("��ȭ��ȣ: ");
	scanf("%s", new_node->number);

	tail->prev->next = new_node;
	new_node->prev = tail->prev;
	new_node->next = tail;
	tail->prev = new_node;

	count++;

	system("cls");
	return;
}

void Output() {										//����Լ�
	if (count == 0) {								//�ּҷ��� ����� ���
		printf("��ȭ��ȣ�ΰ� ����ֽ��ϴ�!!\n");
		system("pause");
		system("cls");
		return;
	}
	
	tmp = head->next;
	int ocnt = 0;

	printf("<���>\n");								//���
	printf("��°��\n");
	printf("----------------------------------------------------\n");
	printf("NUM		�̸�		����		��ȣ\n");
		
	while (tmp != tail) {
		printf("%d		%s		%d		%s\n", ocnt+1, tmp->name, tmp->age, tmp->number);
		tmp = tmp->next;
		ocnt++;
	}

	system("pause");
	system("cls");
	return;
}
	
void Search() {										//�˻��Լ�
	if (count == 0) {								//�ּҷ��� ����� ���
		printf("��ȭ��ȣ�ΰ� ����ֽ��ϴ�!!\n");
		system("pause");
		system("cls");
		return;
	}
	
	int schoice1;
	char schoice2[20];
	int scnt = 0;

	tmp = head->next;

	printf("<�˻�>\n");								//�˻�
	printf("������ �������� ã���ðڽ��ϱ�?\n\n");
	printf("1.�̸�	2.����	3.��ȭ��ȣ	5.���ư���\n\n");
	printf("�Է�: ");
	scanf("%d", &schoice1);

	switch (schoice1) {
	case 1:											//�̸��� �������� �˻�
		printf("�̸�: ");
		scanf("%s", &schoice2);
		system("cls");

		printf("�˻����\n");
		printf("----------------------------------------------------\n");
		printf("NUM		�̸�		����		��ȣ\n");

		while (tmp != tail) {
			if (strcmp(schoice2, tmp->name) == 0) {
				printf("%d		%s		%d		%s\n", scnt + 1, tmp->name, tmp->age, tmp->number);
				scnt++;
			}
			tmp = tmp->next;
		}

		printf("==%d �� �˻��Ǿ����ϴ�.==\n", scnt);
		break;
	case 2:											//���̸� �������� �˻�
		printf("����: ");
		scanf("%d", &schoice1);
		system("cls");

		printf("�˻����\n");
		printf("----------------------------------------------------\n");
		printf("NUM		�̸�		����		��ȣ\n");

		while (tmp != tail) {
			if (schoice1 == tmp->age) {
				printf("%d		%s		%d		%s\n", scnt + 1, tmp->name, tmp->age, tmp->number);
				scnt++;
			}
			tmp = tmp->next;
		}

		printf("==%d �� �˻��Ǿ����ϴ�.==\n", scnt);
		break;
	case 3:											//��ȭ��ȣ�� �������� �˻�
		printf("��ȭ��ȣ: ");
		scanf("%s", &schoice2);
		system("cls");

		printf("�˻����\n");
		printf("----------------------------------------------------\n");
		printf("NUM		�̸�		����		��ȣ\n");

		while (tmp != tail) {
			if (strcmp(schoice2, tmp->number) == 0) {
				printf("%d		%s		%d		%s\n", scnt + 1, tmp->name, tmp->age, tmp->number);
				scnt++;
			}
			tmp = tmp->next;
		}

		printf("==%d �� �˻��Ǿ����ϴ�.==\n", scnt);
		break;	
	case 5:											//���ư���
		system("cls");
		return;
	default:										//����ó��
		printf("1,2,3,5�� ���ڸ� �Է����ּ���.\n");
		exit(0);
	}
	system("pause");
	system("cls");
	
}

void Lookup() {										//Ž���Լ�
	if (count == 0) {								//�ּҷ��� ����� ���
		printf("��ȭ��ȣ�ΰ� ����ֽ��ϴ�!!\n");
		system("pause");
		system("cls");
		return;
	}

	int lchoice1;
	char lchoice2;

	pbNode* tmp;
	tmp = head->next;
	
	printf("<Ž��>\n");								//Ž��
	printf("�� ��° ��带 ���� ��������?\n");
	printf("���� %d�� ������ �ֽ��ϴ�.\n", count);
	printf("�Է�: ");
	scanf("%d", &lchoice1);
	system("cls");

	if (lchoice1 <= count) {						//�ش� ��� ���� ���� �Է��ߴ��� �˻�
		for (int i = 1; i < lchoice1; i++) {
			tmp = tmp->next;
		}
	}
	else {
		printf("�߸� �Է��ϼ̽��ϴ�.\n");
		system("pause");
		system("cls");
		return;
	}

	while (1) {										//�̵�����
		printf("Ž�����\n");
		printf("----------------------------------------------------\n");
		printf("NUM		�̸�		����		��ȣ\n");
		printf("%d		%s		%d		%s\n", lchoice1, tmp->name, tmp->age, tmp->number);
		printf("A: ������ �̵�, D: �ڷ� �̵� X: ����\n");
		printf("���� �̵��Ͻðڽ��ϱ�?: ");
		while (getchar() != '\n');					//�Է¹��� ����
		scanf("%c", &lchoice2);
		system("cls");

		switch(lchoice2){
		case 'A':									//�������̵�
		case 'a':
			if (tmp->prev != head) {
				tmp = tmp->prev;
				lchoice1--;
			}
			else {
				printf("�� �̻� ������ �� �� �����ϴ�.\n");
				system("pause");
				system("cls");
			}
			break;
		case 'D':									//�ڷ� �̵�
		case 'd':
			if (tmp->next != tail) {
				tmp = tmp->next;
				lchoice1++;
			}
			else {
				printf("�� �̻� �ڷ� �� �� �����ϴ�.\n");
				system("pause");
				system("cls");
			}
			break;
		case 'X':									//����
		case 'x':
			system("cls");
			return;
		default:									//����ó��
			printf("����ε� ���� �Է����ּ���.\n");
			system("pause");
			system("cls");
			break;
		}
	}
}

void Delete() {										//�����Լ�
	if (count == 0) {								//�ּҷ��� ����� ���
		printf("��ȭ��ȣ�ΰ� ����ֽ��ϴ�!!\n");
		system("pause");
		system("cls");
		return;
	}

	int i = 0;
	int dchoice1, dage;
	char dname[20], dnumber[20];
	char dchoice2;
	int dcnt = 0;

	tmp = head->next;
	pbNode *dNode = (pbNode*) malloc(sizeof(pbNode));

	printf("<����>\n");								//����
	printf("������ �������� ã���ðڽ��ϱ�?\n\n");
	printf("1.�̸�	2.����	3.��ȭ��ȣ	5.���ư���\n\n");
	printf("�Է�: ");
	scanf("%d", &dchoice1);

	switch (dchoice1) {
	case 1:											//�̸��� �������� �˻�
		printf("�̸�: ");
		scanf("%s", &dname);
		system("cls");

		printf("�˻����\n");
		printf("----------------------------------------------------\n");
		printf("NUM		�̸�		����		��ȣ\n");

		while (tmp != tail) {
			if (strcmp(dname, tmp->name) == 0) {
				printf("%d		%s		%d		%s\n", dcnt + 1, tmp->name, tmp->age, tmp->number);
				dcnt++;
			}
			tmp = tmp->next;
		}

		printf("==%d �� �˻��Ǿ����ϴ�.==\n", dcnt);

		if (dcnt == 0) {							//0���� �˻��� ��� Delete�Լ� ����
			system("pause");
			system("cls");
			return;
		}

		printf("--------------------------------\n");
		printf("������ ���� NUM�� �Է����ּ���: ");
		scanf("%d", &dchoice1);

		if (dchoice1 <= dcnt) {						//�ùٸ� MUM�� �Է����� ��� �ش��ϴ� ��带 ã�Ƽ� dNode�����ͷ� ����Ŵ
			tmp = head;
			while (tmp != tail) {
				tmp = tmp->next;
				if (strcmp(dname, tmp->name) == 0) {
					i++;
					dNode = tmp;
				}
				if (i == dchoice1) {
					tmp = tail;
				}
			}
		}
		else {										//�˻��� NUM�� �ƴ� �ٸ� NUM�� �Է��� ��� Delete�Լ� ����
			system("cls");
			printf("�ùٸ� NUM�� �Է����ּ���.\n");
			system("pause");
			system("cls");
			return;
		}

		printf("\n--------------------------------\n");
		printf("������ ����ðڽ��ϱ�?(Y/N) : ");
		while (getchar() != '\n');					//�Է¹��� ����
		scanf("%c", &dchoice2);

		switch (dchoice2) {							//�������� ����
		case 'Y':
		case 'y':
			tmp = dNode->prev;
			tmp->next = dNode->next;
			dNode->next->prev = tmp;
			free(dNode);		
			count--;

			system("cls");
			printf("�ش� ������ �����Ǿ����ϴ�.\n");
			break;
		case 'N':
		case 'n':
			system("cls");
			return;
		default:
			system("cls");
			printf("����ε� ���� �Է����ּ���.\n");
			break;
		}
		break;

	case 2:											//���̸� �������� �˻�
		printf("����: ");
		scanf("%d", &dage);
		system("cls");

		printf("�˻����\n");
		printf("----------------------------------------------------\n");
		printf("NUM		�̸�		����		��ȣ\n");

		while (tmp != tail) {
			if (dage == tmp->age) {
				printf("%d		%s		%d		%s\n", dcnt + 1, tmp->name, tmp->age, tmp->number);
				dcnt++;
			}
			tmp = tmp->next;
		}

		printf("==%d �� �˻��Ǿ����ϴ�.==\n", dcnt);

		if (dcnt == 0) {							//0���� �˻��� ��� Delete�Լ� ����
			system("pause");
			system("cls");
			return;
		}

		printf("--------------------------------\n");
		printf("������ ���� NUM�� �Է����ּ���: ");
		scanf("%d", &dchoice1);

		if (dchoice1 <= dcnt) {						//�ùٸ� MUM�� �Է����� ��� �ش��ϴ� ��带 ã�Ƽ� dNode�����ͷ� ����Ŵ
			tmp = head;
			while (tmp != tail) {
				tmp = tmp->next;
				if (dage == tmp->age) {
					i++;
					dNode = tmp;
				}
				if (i == dchoice1) {
					tmp = tail;
				}
			}
		}
		else {										//�˻��� NUM�� �ƴ� �ٸ� NUM�� �Է��� ��� Delete�Լ� ����
			system("cls");
			printf("�ùٸ� NUM�� �Է����ּ���.\n");
			system("pause");
			system("cls");
			return;
		}

		printf("\n--------------------------------\n");
		printf("������ ����ðڽ��ϱ�?(Y/N) : ");
		while (getchar() != '\n');					//�Է¹��� ����
		scanf("%c", &dchoice2);

		switch (dchoice2) {							//�������� ����
		case 'y':
		case 'Y':
			tmp = dNode->prev;
			tmp->next = dNode->next;
			dNode->next->prev = tmp;
			free(dNode);

			system("cls");
			printf("�ش� ������ �����Ǿ����ϴ�.\n");
			break;
		case 'n':
		case 'N':
			system("cls");
			return;
		default:
			system("pause");
			system("cls");
			printf("����ε� ���� �Է����ּ���.");
			break;
		}
		break;
	case 3:											//��ȭ��ȣ�� �������� �˻�
		printf("��ȭ��ȣ: ");
		scanf("%s", &dnumber);
		system("cls");

		printf("�˻����\n");
		printf("----------------------------------------------------\n");
		printf("NUM		�̸�		����		��ȣ\n");

		while (tmp != tail) {
			if (strcmp(dnumber, tmp->number) == 0) {
				printf("%d		%s		%d		%s\n", dcnt + 1, tmp->name, tmp->age, tmp->number);
				dcnt++;
			}
			tmp = tmp->next;
		}

		printf("==%d �� �˻��Ǿ����ϴ�.==", dcnt);

		if (dcnt == 0) {							//0���� �˻��� ��� Delete�Լ� ����
			system("pause");
			system("cls");
			return;
		}

		printf("--------------------------------\n");
		printf("������ ���� NUM�� �Է����ּ���: ");
		scanf("%d", &dchoice1);

		if (dchoice1 <= dcnt) {						//�ùٸ� MUM�� �Է����� ��� �ش��ϴ� ��带 ã�Ƽ� dNode�����ͷ� ����Ŵ
			tmp = head;
			while (tmp != tail) {
				tmp = tmp->next;
				if (strcmp(dnumber, tmp->number) == 0) {
					i++;
					dNode = tmp;
				}
				if (i == dchoice1) {
					tmp = tail;
				}
			}
		}
		else {										//�˻��� NUM�� �ƴ� �ٸ� NUM�� �Է��� ��� Delete�Լ� ����
			system("cls");
			printf("�ùٸ� NUM�� �Է����ּ���.\n");
			system("pause");
			system("cls");
			return;
		}

		printf("\n--------------------------------\n");
		printf("������ ����ðڽ��ϱ�?(Y/N) : ");
		while (getchar() != '\n');					//�Է¹��� ����
		scanf("%c", &dchoice2);

		switch (dchoice2) {							//�������� ����
		case 'y':
		case 'Y':
			tmp = dNode->prev;
			tmp->next = dNode->next;
			dNode->next->prev = tmp;
			free(dNode);

			system("cls");
			printf("�ش� ������ �����Ǿ����ϴ�.\n");
			break;
		case 'n':
		case 'N':
			system("cls");
			return;
		default:
			system("pause");
			system("cls");
			printf("����ε� ���� �Է����ּ���.");
			break;
		}
		break;
	case 5:											//���ư���
		system("cls");
		return;
	default:										//����ó��
		printf("1,2,3,5�� ���ڸ� �Է����ּ���.\n");
		exit(0);
	}
	system("pause");
	system("cls");
}