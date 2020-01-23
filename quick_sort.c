#include <stdio.h>
#include <stdlib.h>     //qsort.c
#include <time.h>
#include <string.h>
#define SIZE 20

typedef struct{
    int grade;
    char name[20];
}Student;

int compare(const void *p, const void *q);

int main()
{
    srand((unsigned)time(NULL));

    Student s[SIZE];
    int i;
    char name[20] = "";
    char name_num[10] = "0";

    for(i=0; i<SIZE;i++){
        s[i].grade = rand() % 101;

        sprintf(name, "%s","홍길동");
        sprintf(name_num, "%d", i+1);
        strcat(name, name_num);
        strcpy(s[i].name, name);
    }

    for(i=0;i<SIZE;i++){
        printf("%s - %d\n", s[i].name, s[i].grade);
    }

    qsort(s, SIZE, sizeof(Student), compare);

    printf("\n정렬한 후 구조체\n");
    for(i=0;i<SIZE;i++){
        printf("%s - %d\n", s[i].name, s[i].grade);
    }

    return 0;
}

int compare(const void *p, const void *q){
    int left = ((Student *)p)->grade;
    int right = ((Student *)q)->grade;

    return (left-right);
}
