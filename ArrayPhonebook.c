#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>						//화면바꿈을 위해 사용
#include<string.h>						//strcmp, strcpy

typedef struct{							//구조체 정의
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
	phoneBook pb1[100];					//길이 100의 구조체배열 생성
	int c;
	int num = 0;						//배열의 정보 갯수 저장

	while(1){
		printf("전화번호부\n");
		printf("---------------------------------\n");
		printf("1.입력 2.출력 3.검색 4.삭제 5.종료\n");
		printf("선택: ");
		scanf("%d", &c);

		switch (c)						//입력된 숫자를 가지고 함수 실행
		{
		case 1:							//입력
			system("cls");
			Input(pb1, &num);
			break;
		case 2:							//출력
			system("cls");
			Output(pb1, &num);
			break;
		case 3:							//검색
			system("cls");
			Search(pb1, &num);
			break;
		case 4:							//삭제
			system("cls");
			Delete(pb1, &num);
			break;
		case 5:							//종료
			return 0;
		default:						//예외처리
			system("cls");
			printf("1-5의 숫자를 입력하세요.\n");
			system("pause");
			break;
		}
	}
}

void Input(phoneBook* ptr, int* num)				//Input 함수
{
	if (*num < 100) {
		printf("이름: ");
		scanf("%s", ptr[*num].name);
		printf("나이: ");
		scanf("%d", &ptr[*num].age);
		printf("번호: ");
		scanf("%s", ptr[*num].number);
		printf("\n입력되었습니다.\n");

		(*num)++;
	}else{
		printf("더 이상 입력할 수 없습니다!\n");
	}
	
	system("pause");
	system("cls");
	return;
}

void Output(phoneBook* ptr, int* num)				//Output 함수
{
	printf("출력결과\n");
	printf("------------------------------\n");

	if (*num == 0) {
		printf("연락처가 비어있습니다.\n");
		system("pause");
		system("cls");
		return;
	}

	printf("NUM		이름		나이		번호\n");
	
	for (int i = 0; i < *num; i++) {
		printf("%d		%s		%d		%s\n", i+1, ptr[i].name, ptr[i].age, ptr[i].number);
	}

	system("pause");
	system("cls");
	return ;
}

void Search(phoneBook* ptr, int* num)				//Search 함수
{
	int s1 =0, s3 =0;							//s1으로 검색기준, s2/s3로 검색기준에 대한 정보검색
	char s2[100];
	int cnt = 0;						//정보검색시 검색건수 저장

	printf("<검색>\n");

	if (*num == 0) {
		printf("연락처가 비어있습니다.\n");
		system("pause");
		system("cls");
		return;
	}

	printf("무엇을 기준으로 찾으시겠습니까?\n\n");
	printf("1.이름	2.나이	3.전화번호	5.돌아가기\n\n");
	printf("입력: ");
	scanf("%d", &s1);

	switch (s1) {					
		case 1:							//이름을 기준으로 검색
			printf("이름: ");
			scanf("%s", &s2);
			system("cls");
		
			printf("검색결과\n");
			printf("--------------------------------\n");
			printf("NUM		이름		나이		번호\n");

			for (int i = 0; i < *num; i++) {
				if (strcmp(s2, ptr[i].name) == 0) {
					printf("%d		%s		%d		%s\n", cnt+1, ptr[i].name, ptr[i].age, ptr[i].number);
					cnt++;
				}
				else {
					continue;
				}
			}

			printf("==%d 건 검색되었습니다.==\n", cnt);
			break;
		case 2:							//나이를 기준으로 검색
			printf("나이: ");
			scanf("%d", &s3);
			system("cls");

			printf("검색결과\n");
			printf("--------------------------------\n");
			printf("NUM		이름		나이		번호\n");
			
			for (int i = 0; i < *num; i++) {
				if (s3 == ptr[i].age) {
					printf("%d		%s		%d		%s\n", i + 1, ptr[i].name, ptr[i].age, ptr[i].number);
					cnt++;
				}
				else {
					continue;
				}
			}

			printf("==%d 건 검색되었습니다.==\n", cnt);
			break;
		case 3:							//전화번호를 기준으로 검색
			printf("전화번호: ");
			scanf("%s", &s2);
			system("cls");

			printf("검색결과\n");
			printf("--------------------------------\n");
			printf("NUM		이름		나이		번호\n");

			for (int i = 0; i < *num; i++) {
				if (strcmp(s2, ptr[i].number) == 0) {
					printf("%d		%s		%d		%s\n", i + 1, ptr[i].name, ptr[i].age, ptr[i].number);
					cnt++;
				}
				else {
					continue;
				}
			}

			printf("==%d 건 검색되었습니다.==", cnt);
			break;
		case 5:							//돌아가기
			return ;
		default:						//예외처리
			printf("1,2,3,5의 숫자를 입력해주세요.\n");
			exit(1);
	}
	system("pause");
	system("cls");
}

void Delete(phoneBook* ptr, int* num)				//Delete 함수
{
	int r1, r3, r4, i;					//r1으로 삭제기준, r2/r4로 기준에 대한 정보검색, r3로 삭제할 정보선정
	char r2[100];
	char r5[100];						//r4로 삭제여부 결정
	int tmp[100];						//검색된 값의 NUM 저장
	int cnt = 0;						//정보검색시 검색건수 저장
	int tnum = 0;						//tmp배열의 갯수 저장
	

	printf("<삭제>\n");

	if (*num == 0) {
		printf("연락처가 비어있습니다.\n");
		system("pause");
		system("cls");
		return;
	}

	printf("무엇을 기준으로 찾으시겠습니까?\n\n");
	printf("1.이름	2.나이	3.전화번호	etc.돌아가기\n\n");
	printf("입력: ");
	scanf("%d", &r1);

	switch (r1) {
	case 1:								//이름을 기준으로 검색
		printf("이름: ");
		scanf("%s", &r2);
		system("cls");

		printf("검색결과\n");
		printf("--------------------------------\n");
		printf("NUM		이름		나이		번호\n");

		for (i = 0; i < *num; i++) {					//입력한 값에 대한 정보출력
			if (strcmp(r2, ptr[i].name) == 0) {
				printf("%d		%s		%d		%s\n", i + 1, ptr[i].name, ptr[i].age, ptr[i].number);
				cnt++;
				tmp[tnum] = i + 1;
				tnum++;
			}
		}

		printf("==%d 건 검색되었습니다.==\n", cnt);

		if (cnt == 0) {									//0건이 검색될 경우 Delete함수 종료
			system("pause");
			system("cls");
			return ;
		}

		printf("--------------------------------\n");
		printf("삭제할 값의 NUM을 입력해주세요: ");
		scanf("%d", &r3);

		for (i = 0; i < tnum; i++) {					//검색한 NUM이 아닌 다른 NUM을 입력할 경우 Delete함수 종료
			if (r3 == tmp[i]) {
				continue;
			}
			else {
				system("cls");
				printf("올바른 NUM을 입력해주세요.\n");
				system("pause");
				system("cls");
				return;
			}
		}

		printf("\n--------------------------------\n");
		printf("정말로 지우시겠습니까?(Y/N) : ");
		scanf("%s", &r5);
			
		if (r5 == "y" || "Y") {							//삭제여부 결정
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
			printf("해당 정보가 삭제되었습니다.\n");
			system("pause");
		}
		else if (r5 == "n" || "N") {
			system("cls");
			return ;
		}
		else {
			system("pause");
			system("cls");
			printf("제대로된 값을 입력해주세요.");
		}
		break;

	case 2:												//나이를 기준으로 검색
		printf("나이: ");
		scanf("%d", &r4);
		system("cls");

		printf("검색결과\n");
		printf("--------------------------------\n");
		printf("NUM		이름		나이		번호\n");

		for (int i = 0; i < *num; i++) {				//입력한 값에 대한 정보출력
			if (r4 == ptr[i].age) {
				printf("%d		%s		%d		%s\n", i + 1, ptr[i].name, ptr[i].age, ptr[i].number);
				cnt++;
			}
		}

		printf("==%d 건 검색되었습니다.==\n", cnt);

		if (cnt == 0) {									//0건이 검색될 경우 Delete함수 종료
			system("pause");
			system("cls");
			return;
		}

		printf("--------------------------------\n");
		printf("삭제할 값의 NUM을 입력해주세요: ");
		scanf("%d", &r3);

		for (i = 0; i < tnum; i++) {					//검색한 NUM이 아닌 다른 NUM을 입력할 경우 Delete함수 종료
			if (r3 == tmp[i]) {
				continue;
			}
			else {
				system("cls");
				printf("올바른 NUM을 입력해주세요.\n");
				system("pause");
				system("cls");
				return;
			}
		}

		printf("\n--------------------------------\n");
		printf("정말로 지우시겠습니까?(Y/N) : ");
		scanf("%s", &r5);

		if (r5 == "y" || "Y") {			//삭제여부 결정
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
			printf("해당 정보가 삭제되었습니다.\n");
			system("pause");
		}
		else if (r5 == "n" || "N") {
			system("cls");
			return;
		}
		else {
			system("cls");
			printf("제대로된 값을 입력해주세요.\n");
		}

		break;
	case 3:								//전화번호를 기준으로 검색
		printf("전화번호: ");
		scanf("%s", &r2);
		system("cls");

		printf("검색결과\n");
		printf("--------------------------------\n");
		printf("NUM		이름		나이		번호\n");

		for (int i = 0; i < *num; i++) {				//입력한 값에 대한 정보출력
			if (strcmp(&r2, ptr[i].number) == 0) {
				printf("%d		%s		%d		%s\n", i + 1, ptr[i].name, ptr[i].age, ptr[i].number);
				cnt++;
			}
		}

		printf("==%d 건 검색되었습니다.==\n", cnt);

		if (cnt == 0) {									//0건이 검색될 경우 Delete함수 종료
			system("cls");
			return;
		}

		printf("--------------------------------\n");
		printf("삭제할 값의 NUM을 입력해주세요: ");
		scanf("%d", &r3);

		for (i = 0; i < tnum; i++) {					//검색한 NUM이 아닌 다른 NUM을 입력할 경우 Delete함수 종료
			if (r3 == tmp[i]) {
				continue;
			}
			else {
				system("cls");
				printf("올바른 NUM을 입력해주세요.\n");
				system("pause");
				system("cls");
				return;
			}
		}

		printf("\n--------------------------------\n");
		printf("정말로 지우시겠습니까?(Y/N) : ");
		scanf("%s", &r5);

		if (r5 == "y" || "Y") {			//삭제여부 결정
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
			printf("해당 정보가 삭제되었습니다.\n");
			system("pause");
		}
		else if (r5 == "n" || "N") {
			system("cls");
			return;
		}
		else {
			system("cls");
			printf("제대로된 값을 입력해주세요.\n");
		}

		break;
	default:						//기준검색에 대한 예외처리
		exit(1);
	}
}