#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define SIZE 10

typedef struct {
    int id;
    char name[20];
    char number[30];
    int age;
}employee;


int main()
{
    employee employee_arr[SIZE];
    int i;
    char hong[10] = "";
    char name_num[10] = "0";
    char default_number[30] = "";
    char number_num[10] = "0";

    srand((unsigned)time(NULL));

    for(i=0;i<SIZE;i++){
        employee_arr[i].id = i+1;

        strcpy(hong, "홍길동");
        sprintf(name_num, "%d",i+1);
        strcat(hong, name_num);
        strcpy(employee_arr[i].name, hong);

        strcpy(default_number, "010-0000-");
        sprintf(number_num, "%04d", i+1);
        strcat(default_number, number_num);
        strcpy(employee_arr[i].number, default_number);

        employee_arr[i].age = rand() % 41 + 19;
    }
    printf("사번\t | 이름\t\t | 전화번호\t | 나이|\n");
    for(i=0; i<SIZE;i++){
        printf("%d\t | %s\t | %s | %d  |\n", employee_arr[i].id, employee_arr[i].name, employee_arr[i].number, employee_arr[i].age);
    }

    printf("\n20세이상 30세이하인 직원\n");
    printf("사번\t | 이름\t\t | 전화번호\t | 나이|\n");
    for(i=0; i<SIZE; i++){
        if(20 <= employee_arr[i].age && employee_arr[i].age <= 30){
            printf("%d\t | %s\t | %s | %d  |\n", employee_arr[i].id, employee_arr[i].name, employee_arr[i].number, employee_arr[i].age);
        }
    }

    return 0;
}
