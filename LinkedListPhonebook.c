#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>									//malloc, free
#include<windows.h>									//화면바꿈을 위해 사용
#include<string.h>									//strcmp, strcpy

typedef struct pbNode{								//노드 구조체정의
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

int main() {										//Main 문
	int choice;	

	Init();
	while (1) {
		printf("전화번호부\n");
		printf("------------------------------------------\n");
		printf("1.입력 2.출력 3.검색 4.탐색 5.삭제 6.종료\n");
		printf("선택: ");
		scanf("%d", &choice);
			
		switch (choice)								//입력된 숫자를 가지고 함수 실행
		{
		case 1:										//입력
			system("cls");
			Input();
			break;
		case 2:										//출력
			system("cls");
			Output();
			break;
		case 3:										//검색
			system("cls");
			Search();
			break;
		case 4:										//탐색
			system("cls");
			Lookup();
			break;
		case 5:										//삭제
			system("cls");
			Delete();
			break;
		case 6:										//종료
			return 0;
		default:									//예외처리
			system("cls");
			printf("1-6의 숫자를 입력하세요.\n");
			system("pause");
			break;
		}
	}
}

void Init() {										//노드 초기설정
	head = (pbNode*)malloc(sizeof(pbNode));
	tail = (pbNode*)malloc(sizeof(pbNode));
	
	head->prev = head;
	head->next = tail;
	tail->prev = head;
	tail->next = tail;

	count = 0;
}

void Input() {										//삽입함수
	pbNode* new_node;
	new_node = (pbNode*) malloc(sizeof(pbNode));
	new_node->next = NULL;
	new_node->prev = NULL;

	printf("<삽입>\n");
	printf("이름: ");
	scanf("%s", new_node->name);
	printf("나이: ");
	scanf("%d", &new_node->age);
	printf("전화번호: ");
	scanf("%s", new_node->number);

	tail->prev->next = new_node;
	new_node->prev = tail->prev;
	new_node->next = tail;
	tail->prev = new_node;

	count++;

	system("cls");
	return;
}

void Output() {										//출력함수
	if (count == 0) {								//주소록이 비었을 경우
		printf("전화번호부가 비어있습니다!!\n");
		system("pause");
		system("cls");
		return;
	}
	
	tmp = head->next;
	int ocnt = 0;

	printf("<출력>\n");								//출력
	printf("출력결과\n");
	printf("----------------------------------------------------\n");
	printf("NUM		이름		나이		번호\n");
		
	while (tmp != tail) {
		printf("%d		%s		%d		%s\n", ocnt+1, tmp->name, tmp->age, tmp->number);
		tmp = tmp->next;
		ocnt++;
	}

	system("pause");
	system("cls");
	return;
}
	
void Search() {										//검색함수
	if (count == 0) {								//주소록이 비었을 경우
		printf("전화번호부가 비어있습니다!!\n");
		system("pause");
		system("cls");
		return;
	}
	
	int schoice1;
	char schoice2[20];
	int scnt = 0;

	tmp = head->next;

	printf("<검색>\n");								//검색
	printf("무엇을 기준으로 찾으시겠습니까?\n\n");
	printf("1.이름	2.나이	3.전화번호	5.돌아가기\n\n");
	printf("입력: ");
	scanf("%d", &schoice1);

	switch (schoice1) {
	case 1:											//이름을 기준으로 검색
		printf("이름: ");
		scanf("%s", &schoice2);
		system("cls");

		printf("검색결과\n");
		printf("----------------------------------------------------\n");
		printf("NUM		이름		나이		번호\n");

		while (tmp != tail) {
			if (strcmp(schoice2, tmp->name) == 0) {
				printf("%d		%s		%d		%s\n", scnt + 1, tmp->name, tmp->age, tmp->number);
				scnt++;
			}
			tmp = tmp->next;
		}

		printf("==%d 건 검색되었습니다.==\n", scnt);
		break;
	case 2:											//나이를 기준으로 검색
		printf("나이: ");
		scanf("%d", &schoice1);
		system("cls");

		printf("검색결과\n");
		printf("----------------------------------------------------\n");
		printf("NUM		이름		나이		번호\n");

		while (tmp != tail) {
			if (schoice1 == tmp->age) {
				printf("%d		%s		%d		%s\n", scnt + 1, tmp->name, tmp->age, tmp->number);
				scnt++;
			}
			tmp = tmp->next;
		}

		printf("==%d 건 검색되었습니다.==\n", scnt);
		break;
	case 3:											//전화번호를 기준으로 검색
		printf("전화번호: ");
		scanf("%s", &schoice2);
		system("cls");

		printf("검색결과\n");
		printf("----------------------------------------------------\n");
		printf("NUM		이름		나이		번호\n");

		while (tmp != tail) {
			if (strcmp(schoice2, tmp->number) == 0) {
				printf("%d		%s		%d		%s\n", scnt + 1, tmp->name, tmp->age, tmp->number);
				scnt++;
			}
			tmp = tmp->next;
		}

		printf("==%d 건 검색되었습니다.==\n", scnt);
		break;	
	case 5:											//돌아가기
		system("cls");
		return;
	default:										//예외처리
		printf("1,2,3,5의 숫자를 입력해주세요.\n");
		exit(0);
	}
	system("pause");
	system("cls");
	
}

void Lookup() {										//탐색함수
	if (count == 0) {								//주소록이 비었을 경우
		printf("전화번호부가 비어있습니다!!\n");
		system("pause");
		system("cls");
		return;
	}

	int lchoice1;
	char lchoice2;

	pbNode* tmp;
	tmp = head->next;
	
	printf("<탐색>\n");								//탐색
	printf("몇 번째 노드를 보고 싶으세요?\n");
	printf("현재 %d번 노드까지 있습니다.\n", count);
	printf("입력: ");
	scanf("%d", &lchoice1);
	system("cls");

	if (lchoice1 <= count) {						//해당 노드 안의 수를 입력했는지 검사
		for (int i = 1; i < lchoice1; i++) {
			tmp = tmp->next;
		}
	}
	else {
		printf("잘못 입력하셨습니다.\n");
		system("pause");
		system("cls");
		return;
	}

	while (1) {										//이동구간
		printf("탐색결과\n");
		printf("----------------------------------------------------\n");
		printf("NUM		이름		나이		번호\n");
		printf("%d		%s		%d		%s\n", lchoice1, tmp->name, tmp->age, tmp->number);
		printf("A: 앞으로 이동, D: 뒤로 이동 X: 종료\n");
		printf("어디로 이동하시겠습니까?: ");
		while (getchar() != '\n');					//입력버퍼 비우기
		scanf("%c", &lchoice2);
		system("cls");

		switch(lchoice2){
		case 'A':									//앞으로이동
		case 'a':
			if (tmp->prev != head) {
				tmp = tmp->prev;
				lchoice1--;
			}
			else {
				printf("더 이상 앞으로 갈 수 없습니다.\n");
				system("pause");
				system("cls");
			}
			break;
		case 'D':									//뒤로 이동
		case 'd':
			if (tmp->next != tail) {
				tmp = tmp->next;
				lchoice1++;
			}
			else {
				printf("더 이상 뒤로 갈 수 없습니다.\n");
				system("pause");
				system("cls");
			}
			break;
		case 'X':									//종료
		case 'x':
			system("cls");
			return;
		default:									//예외처리
			printf("제대로된 값을 입력해주세요.\n");
			system("pause");
			system("cls");
			break;
		}
	}
}

void Delete() {										//삭제함수
	if (count == 0) {								//주소록이 비었을 경우
		printf("전화번호부가 비어있습니다!!\n");
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

	printf("<삭제>\n");								//삭제
	printf("무엇을 기준으로 찾으시겠습니까?\n\n");
	printf("1.이름	2.나이	3.전화번호	5.돌아가기\n\n");
	printf("입력: ");
	scanf("%d", &dchoice1);

	switch (dchoice1) {
	case 1:											//이름을 기준으로 검색
		printf("이름: ");
		scanf("%s", &dname);
		system("cls");

		printf("검색결과\n");
		printf("----------------------------------------------------\n");
		printf("NUM		이름		나이		번호\n");

		while (tmp != tail) {
			if (strcmp(dname, tmp->name) == 0) {
				printf("%d		%s		%d		%s\n", dcnt + 1, tmp->name, tmp->age, tmp->number);
				dcnt++;
			}
			tmp = tmp->next;
		}

		printf("==%d 건 검색되었습니다.==\n", dcnt);

		if (dcnt == 0) {							//0건이 검색될 경우 Delete함수 종료
			system("pause");
			system("cls");
			return;
		}

		printf("--------------------------------\n");
		printf("삭제할 값의 NUM을 입력해주세요: ");
		scanf("%d", &dchoice1);

		if (dchoice1 <= dcnt) {						//올바른 MUM을 입력했을 경우 해당하는 노드를 찾아서 dNode포인터로 가리킴
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
		else {										//검색한 NUM이 아닌 다른 NUM을 입력할 경우 Delete함수 종료
			system("cls");
			printf("올바른 NUM을 입력해주세요.\n");
			system("pause");
			system("cls");
			return;
		}

		printf("\n--------------------------------\n");
		printf("정말로 지우시겠습니까?(Y/N) : ");
		while (getchar() != '\n');					//입력버퍼 비우기
		scanf("%c", &dchoice2);

		switch (dchoice2) {							//삭제여부 결정
		case 'Y':
		case 'y':
			tmp = dNode->prev;
			tmp->next = dNode->next;
			dNode->next->prev = tmp;
			free(dNode);		
			count--;

			system("cls");
			printf("해당 정보가 삭제되었습니다.\n");
			break;
		case 'N':
		case 'n':
			system("cls");
			return;
		default:
			system("cls");
			printf("제대로된 값을 입력해주세요.\n");
			break;
		}
		break;

	case 2:											//나이를 기준으로 검색
		printf("나이: ");
		scanf("%d", &dage);
		system("cls");

		printf("검색결과\n");
		printf("----------------------------------------------------\n");
		printf("NUM		이름		나이		번호\n");

		while (tmp != tail) {
			if (dage == tmp->age) {
				printf("%d		%s		%d		%s\n", dcnt + 1, tmp->name, tmp->age, tmp->number);
				dcnt++;
			}
			tmp = tmp->next;
		}

		printf("==%d 건 검색되었습니다.==\n", dcnt);

		if (dcnt == 0) {							//0건이 검색될 경우 Delete함수 종료
			system("pause");
			system("cls");
			return;
		}

		printf("--------------------------------\n");
		printf("삭제할 값의 NUM을 입력해주세요: ");
		scanf("%d", &dchoice1);

		if (dchoice1 <= dcnt) {						//올바른 MUM을 입력했을 경우 해당하는 노드를 찾아서 dNode포인터로 가리킴
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
		else {										//검색한 NUM이 아닌 다른 NUM을 입력할 경우 Delete함수 종료
			system("cls");
			printf("올바른 NUM을 입력해주세요.\n");
			system("pause");
			system("cls");
			return;
		}

		printf("\n--------------------------------\n");
		printf("정말로 지우시겠습니까?(Y/N) : ");
		while (getchar() != '\n');					//입력버퍼 비우기
		scanf("%c", &dchoice2);

		switch (dchoice2) {							//삭제여부 결정
		case 'y':
		case 'Y':
			tmp = dNode->prev;
			tmp->next = dNode->next;
			dNode->next->prev = tmp;
			free(dNode);

			system("cls");
			printf("해당 정보가 삭제되었습니다.\n");
			break;
		case 'n':
		case 'N':
			system("cls");
			return;
		default:
			system("pause");
			system("cls");
			printf("제대로된 값을 입력해주세요.");
			break;
		}
		break;
	case 3:											//전화번호를 기준으로 검색
		printf("전화번호: ");
		scanf("%s", &dnumber);
		system("cls");

		printf("검색결과\n");
		printf("----------------------------------------------------\n");
		printf("NUM		이름		나이		번호\n");

		while (tmp != tail) {
			if (strcmp(dnumber, tmp->number) == 0) {
				printf("%d		%s		%d		%s\n", dcnt + 1, tmp->name, tmp->age, tmp->number);
				dcnt++;
			}
			tmp = tmp->next;
		}

		printf("==%d 건 검색되었습니다.==", dcnt);

		if (dcnt == 0) {							//0건이 검색될 경우 Delete함수 종료
			system("pause");
			system("cls");
			return;
		}

		printf("--------------------------------\n");
		printf("삭제할 값의 NUM을 입력해주세요: ");
		scanf("%d", &dchoice1);

		if (dchoice1 <= dcnt) {						//올바른 MUM을 입력했을 경우 해당하는 노드를 찾아서 dNode포인터로 가리킴
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
		else {										//검색한 NUM이 아닌 다른 NUM을 입력할 경우 Delete함수 종료
			system("cls");
			printf("올바른 NUM을 입력해주세요.\n");
			system("pause");
			system("cls");
			return;
		}

		printf("\n--------------------------------\n");
		printf("정말로 지우시겠습니까?(Y/N) : ");
		while (getchar() != '\n');					//입력버퍼 비우기
		scanf("%c", &dchoice2);

		switch (dchoice2) {							//삭제여부 결정
		case 'y':
		case 'Y':
			tmp = dNode->prev;
			tmp->next = dNode->next;
			dNode->next->prev = tmp;
			free(dNode);

			system("cls");
			printf("해당 정보가 삭제되었습니다.\n");
			break;
		case 'n':
		case 'N':
			system("cls");
			return;
		default:
			system("pause");
			system("cls");
			printf("제대로된 값을 입력해주세요.");
			break;
		}
		break;
	case 5:											//돌아가기
		system("cls");
		return;
	default:										//예외처리
		printf("1,2,3,5의 숫자를 입력해주세요.\n");
		exit(0);
	}
	system("pause");
	system("cls");
}