#include <stdio.h>
#include <stdlib.h>

#define SIZE 16 // Stack�� ũ�� ����

int stack[SIZE] = { 0 }; // Stack �ʱ�ȭ
const int factFuncAddr = 0x00500000; // fact�Լ��� �ʱ� ��ġ
const int firstCallerAddr = 0x0040FF00; // main���α׷��� fact�Լ��� ȣ���� �ּ�
const int firstSp = 0x7FFF0000; // Stack Pointer�� ó�� ��ġ
int sp = 0x0, pc = 0x0, ra = 0x0, a0 = 0x0, t0 = 0x0, v0 = 0x0; // Register �ʱ�ȭ

void showStack() // Stack ��� �Լ�
{
     printf("============= [ State of Stack ] ============\n"); // Stack�� �ٴ�
     int i;
     for (i = 0; i < sizeof(stack) / 4; ++i)
     {
          printf("           %8X    [ %8X ]\n", firstSp - 4 * (i + 1), stack[i]);
     }
     printf("===============    ��   ��    ===============\n"); // Stack�� �Ա�
     system("pause");
}

void showRegister()
{
     printf("========== [ State of Registers ] ===========\n"); // Register ��� �Լ�
     printf(" PC : %8X, $sp : %8X, $ra: %8X\n$a0 : %8X, $t0 : %8X, $v0: %8X\n", pc, sp, ra, a0, t0, v0);
     printf("=============================================\n");
     system("pause");
}

void pushStack(int sp, int reg) // Push �Լ�
{
     if ((firstSp - sp) / 4 - 1 > sizeof(stack) / 4 - 1) // Stack Pointer�� Stack�� �Ա����� ���� ����Ű��
     {
          printf("\n!!! STACK OVERFLOW !!!\n"); // �����÷ο� ó�� �� ���α׷� ��������
          system("pause");
          exit(1);
     }
     stack[((firstSp - sp) / 4 - 1)] = reg;
     showStack();
}

void popStack(int sp, int* ptrreg) // Pop �Լ�
{
     if ((firstSp - sp) / 4 - 1 < 0) // Stack Pointer�� Stack�� �ٴں��� �Ʒ��� ����Ű��
     {
          printf("\n!!! STACK UNDERFLOW !!!\n"); // ����÷ο� ó�� �� ���α׷� ��������
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
	//printf("���ڸ� �Է�: ");
	//scanf("%n", &num);
     // --------------------------------------------------------------
     pc = firstCallerAddr + 0x4; // fact�Լ� ȣ��������� PC 1ȸ ����
     sp = firstSp; // Stack Pointer �ʱ� �� ����
     printf("*** Function called. 'n' is %d ***\n\n", num);
     ra = pc; // fact �Լ��� �����ϸ鼭 ������ PC���� ra�� ����
     a0 = num; // ���ڷ� ���� num���� a0�� �ʱ�ȭ
     pc = factFuncAddr; // PC�� fact�Լ� �ּҷ� �����
     showRegister();
     // --------------------------------------------------------------
fact: // fact �Լ� ���� �κ�
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