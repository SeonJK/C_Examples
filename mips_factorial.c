#include <stdio.h>
#include <stdlib.h>

#define SIZE 16 // Stack의 크기 지정

int stack[SIZE] = { 0 }; // Stack 초기화
const int factFuncAddr = 0x00500000; // fact함수의 초기 위치
const int firstCallerAddr = 0x0040FF00; // main프로그램이 fact함수를 호출한 주소
const int firstSp = 0x7FFF0000; // Stack Pointer의 처음 위치
int sp = 0x0, pc = 0x0, ra = 0x0, a0 = 0x0, t0 = 0x0, v0 = 0x0; // Register 초기화

void showStack() // Stack 출력 함수
{
     printf("============= [ State of Stack ] ============\n"); // Stack의 바닥
     int i;
     for (i = 0; i < sizeof(stack) / 4; ++i)
     {
          printf("           %8X    [ %8X ]\n", firstSp - 4 * (i + 1), stack[i]);
     }
     printf("===============    ↓   ↑    ===============\n"); // Stack의 입구
     system("pause");
}

void showRegister()
{
     printf("========== [ State of Registers ] ===========\n"); // Register 출력 함수
     printf(" PC : %8X, $sp : %8X, $ra: %8X\n$a0 : %8X, $t0 : %8X, $v0: %8X\n", pc, sp, ra, a0, t0, v0);
     printf("=============================================\n");
     system("pause");
}

void pushStack(int sp, int reg) // Push 함수
{
     if ((firstSp - sp) / 4 - 1 > sizeof(stack) / 4 - 1) // Stack Pointer가 Stack의 입구보다 위를 가리키면
     {
          printf("\n!!! STACK OVERFLOW !!!\n"); // 오버플로우 처리 후 프로그램 강제종료
          system("pause");
          exit(1);
     }
     stack[((firstSp - sp) / 4 - 1)] = reg;
     showStack();
}

void popStack(int sp, int* ptrreg) // Pop 함수
{
     if ((firstSp - sp) / 4 - 1 < 0) // Stack Pointer가 Stack의 바닥보다 아래를 가리키면
     {
          printf("\n!!! STACK UNDERFLOW !!!\n"); // 언더플로우 처리 후 프로그램 강제종료
          system("pause");
          exit(1);
     }
     *ptrreg = stack[((firstSp - sp) / 4 - 1)];
     stack[((firstSp - sp) / 4 - 1)] = 0;
     showStack();
}

int main()
{
	int num = 6;
	//printf("숫자를 입력: ");
	//scanf("%n", &num);
     // --------------------------------------------------------------
     pc = firstCallerAddr + 0x4; // fact함수 호출시점에서 PC 1회 증가
     sp = firstSp; // Stack Pointer 초기 값 지정
     printf("*** Function called. 'n' is %d ***\n\n", num);
     ra = pc; // fact 함수로 진입하면서 마지막 PC값을 ra에 저장
     a0 = num; // 인자로 받은 num으로 a0를 초기화
     pc = factFuncAddr; // PC가 fact함수 주소로 변경됨
     showRegister();
     // --------------------------------------------------------------
fact: // fact 함수 시작 부분
     printf("%8X fact :\n", pc);
     pc += 0x4;
     showRegister();
     // --------------------------------------------------------------
     printf("%8X        addi $sp, $sp, -8\n", pc);
     sp = sp - 0x8;
     pc += 0x4;
     showRegister();
     printf("%8X        sw   $ra, 4($sp)\n", pc);
     pushStack(sp + 0x4, ra);
     pc += 0x4;
     showRegister();
     printf("%8X        sw   $a0, 0($sp)\n", pc);
     pushStack(sp, a0);
     pc += 0x4;
     showRegister();
     // --------------------------------------------------------------
     printf("%8X        slti $t0, $a0, 1\n", pc);
     if (a0 < 1)
          t0 = 1;
     else
          t0 = 0;
     pc += 0x4;
     showRegister();
     printf("%8X        beq  $t0, $zero, L1\n", pc);
     if (t0 == 0)
     {
          pc = 0x00500024;
          showRegister();
          goto L1;
     }
     else
     {
          pc += 0x4;
          showRegister();
     }
     // --------------------------------------------------------------
     printf("%8X        addi $v0, $zero, 1\n", pc);
     v0 = 0x0 + 0x1;
     pc += 0x4;
     showRegister();
     printf("%8X        addi $sp, $sp, 8\n", pc);
     sp = sp + 0x8;
     pc += 0x4;
     showRegister();
     printf("%8X        jr   $ra\n", pc);
     if (ra == 0x0050002C)
     {
          pc = 0x0050002C;
          showRegister();
          goto pc0050002C;
     }
     else
     {
          printf("\n!!! ADRESS IN PC IS STRANGE !!!\n.");
     }
     // --------------------------------------------------------------
L1:
     printf("%8X L1 :   addi $a0, $a0, -1\n", pc);
     a0 = a0 - 0x1;
     pc += 0x4;
     showRegister();
     printf("%8X        jal  fact\n", pc);
     ra = pc + 0x4;
     pc = 0x00500000;
     showRegister();
     goto fact;
     // --------------------------------------------------------------
pc0050002C:
     printf("%8X        lw   $a0, 0($sp)\n", pc);
     int* ptra0 = &a0;
     popStack(sp, ptra0);
     pc += 0x4;
     showRegister();
     printf("%8X        lw   $ra, 4($sp)\n", pc);
     int* ptrra = &ra;
     popStack(sp + 4, ptrra);
     pc += 0x4;
     showRegister();
     printf("%8X        addi $sp, $sp, 8\n", pc);
     sp = sp + 8;
     pc += 0x4;
     showRegister();
     // --------------------------------------------------------------
     printf("%8X        mul  $v0, $a0, $v0\n", pc);
     v0 = v0 * a0;
     pc += 0x4;
     showRegister();
     // --------------------------------------------------------------
     printf("%8X        jr   $ra\n", pc);
     if (ra == 0x0050002C)
     {
          pc = 0x0050002C;
          showRegister();
          goto pc0050002C;
     }
     else if (ra == 0x0040ff04)
     {
          pc = 0x0040ff04;
          showRegister();
          goto pc0040ff04;
     }
     else
          printf("\n!!! ADRESS IN PC IS STRANGE !!!\n.");
     // --------------------------------------------------------------
pc0040ff04:
     printf("\n*** Function ended ***\n");
     printf("*** Returned value(in $v0) is %X ***\n", v0);
     printf("*** %Xh is %d in decimal ***\n", v0, v0);
     // --------------------------------------------------------------
     printf("\n*** Program ended ***\n");
     system("pause");
     return 0;
}