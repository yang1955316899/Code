#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int max = -1;
int cnt2 = 0;
char a[4][30];
char str[30][30];
int b[5];
int DaAn[4];   //��Ŵ� ��
int DaAnYH[4]; //����û��𰸣�
int TiHao[4];  //��Ŵ������;
int LiSh[100]; //�����ʷ�ɼ���

typedef char ElementType;

struct SNode
{
	ElementType *Data;
	int Top;
	int MaxSize;
};
typedef struct SNode *Stack;

struct S2Node
{
	int *Data;
	int Top;
	int MaxSize;
};
typedef struct S2Node *Stack2;

Stack s1, s2, s3;
Stack CreateStack(int MaxSize)
{
	Stack S = (Stack)malloc(sizeof(struct SNode));
	S->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
	S->Top = -1;
	S->MaxSize = MaxSize;
	return S;
}

Stack2 CreateStack2(int MaxSize)
{
	Stack2 S = (Stack2)malloc(sizeof(struct S2Node));
	S->Data = (int *)malloc(MaxSize * sizeof(int));
	S->Top = -1;
	S->MaxSize = MaxSize;
	return S;
}

bool push(Stack S, ElementType X)
{
	S->Data[++(S->Top)] = X;
	return true;
}

bool push2(Stack2 S, int X)
{
	S->Data[++(S->Top)] = X;
	return true;
}

bool IsEmpty(Stack S)
{
	return (S->Top == -1); //�ж�ջ���Ƿ�ָ��-1
}

bool IsEmpty2(Stack2 S)
{
	return (S->Top == -1); //�ж�ջ���Ƿ�ָ��-1
}

char top(Stack S)
{
	return (S->Data[S->Top]);
}

ElementType pop(Stack S)
{
	return (S->Data[(S->Top)--]);
}

int pop2(Stack2 S)
{
	if (IsEmpty2(S))
	{
		printf("��ջ��");
		return ERROR;
	}
	else
		return (S->Data[(S->Top)--]);
}

int IsHigherThan(char x, char y) //���ȼ�����
{
	if (((x == '*') || (x == '/')) && ((y == '+') || (y == '-')))
		return 1;
	else
		return 0;
}

void Exchange(char a[])
{
	//��ʼ������ջ��s1�洢�����,s2�洢�м���
	s1 = CreateStack(50);
	s2 = CreateStack(50);
	s3 = CreateStack(50);
	int i = 0;
	while (a[i] != '\0') //������ɨ����ʽ
	{
		if (a[i] >= '0' && a[i] <= '9') //����������ʱ����ѹ��s2
			push(s2, a[i]);

		else
		{
			if (IsEmpty(s1) || a[i] == '(') //s1Ϊ�ջ������Ϊ������ʱֱ����ջs1
				push(s1, a[i]);
			else if ((a[i]) == ')')
			{
				while (s1->Data[s1->Top] != '(')
					push(s2, pop(s1));
				pop(s1);
			}
			else
			{
				while (IsHigherThan(s1->Data[s1->Top], a[i])) //���������ʱ���Ƚ�����s1ջ������������ȼ�
					push(s2, pop(s1));						  //�����������s1ջ�������ʱѹ��s1,���򵯳�s1ջ��Ԫ��
				push(s1, a[i]);								  //���������s2�������Ƚ�
			}
		}
		i++;
	}
	while (!IsEmpty(s1)) //��ʣ���s1�е�Ԫ��ѹ��s2;
		push(s2, pop(s1));

	while (!IsEmpty(s2))
		push(s3, pop(s2));
}

int evaluation(Stack s3) //��׺���ʽ��ֵ
{
	Stack2 S;
	S = CreateStack2(50);

	char a;
	int op1, op2;

	while (op1 != -1) //������ɨ���׺���ʽ
	{
		if (isdigit(top(s3)))
		{
			int n = top(s3) - 48;
			push2(S, n);
		}

		else
		{
			op2 = pop2(S);

			if (!IsEmpty2(S))
				op1 = pop2(S);
			else
				op1 = -1;

			switch (top(s3))
			{
			case '+':
				push2(S, (op1 + op2));
				break;
			case '-':
				push2(S, (op1 - op2));
				break;
			case '*':
				push2(S, (op1 * op2));
				break;
			case '/':
				push2(S, (op1 / op2));
				break;
			}
		}
		pop(s3);
	}
	return op2;
}

void GiveQuestion() //�������
{

	int j; //����������ֵΪ��ʮ���ڵ�����������b
	for (j = 0; j < 5; j++)
		b[j] = rand() % 30;

	int i = 0; //���ļ����ά����д������
	FILE *fp;
	fp = fopen("test.txt", "r");
	for (i = 0; i < 30; i++)
		fscanf(fp, "%s", str[i]);
	fclose(fp);

	printf("\t\t\t-------------------------\n");
	for (i = 0; i < 5; i++) //�����str�����ѡ�������a����
	{
		strcpy(a[i], str[b[i]]);
		printf("\t\t\t%s=\n", a[i]);
	}
	printf("\t\t\t-------------------------\n");
}

void menu()
{
	int button = 1, i;
	char str[20];
	int x, x1, x2, x3;
	while (button)
	{
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t\t----------\n");
		printf("\t\t\t\t|��ӭʹ��|\n");
		printf("\t\t\t\t-----------\n");

		Sleep(1000);
		system("cls");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t-------------------------\n");
		printf("\t\t\t�������ѡ����Ҫ���еĲ���\n");
		printf("\t\t\t1:����ģʽ:\n");
		printf("\t\t\t2:��ʷ�ɼ�:\n");
		printf("\t\t\t3:�˳�\n");
		printf("\t\t\t-------------------------\n");
		printf("\t\t\t");
		scanf("%d", &x);
		system("cls");
		switch (x)
		{
		case 1:
			printf("\n\n\n\n\n\n\n");
			printf("\t\t\t-------------------------\n");
			printf("\t\t\t������������������Ŀ,��\n");
			printf("\t\t\t�밴˳����д��Ĵ�\n");
			printf("\t\t\t-------------------------\n");
			GiveQuestion();

			int n1, n2, n3, n4, n5;
			for (n1 = 0; n1 < 5; n1++)
			{
				Exchange(a[n1]);
				DaAn[n1] = evaluation(s3);
			}

			printf("\t\t\t-------------------------\n");
			printf("\t\t\t�����������Ĵ�:\n");
			printf("\t\t\t");
			for (n1 = 0; n1 < 5; n1++)
				scanf("%d", &DaAnYH[n1]);
			int cnt = 0;
			n3 = 0;
			for (n2 = 0; n2 < 5; n2++)
			{
				if (DaAn[n2] == DaAnYH[n2])
					cnt++;
				else
				{
					TiHao[n3] = n2;
					n3++;
				}
			}

			system("cls");
			printf("\n\n\n\n\n");
			printf("\t\t\t-------------------------\n");
			printf("\t\t\t�����δ����%d����Ŀ\n", cnt);
			printf("\t\t\t���д������Ŀ�ʹ�����\n");
			for (n4 = 0; n4 < n3; n4++)
				printf("\t\t\t%s=%d\n", a[TiHao[n4]], DaAn[TiHao[n4]]);
			if (cnt2 > 0)
				if (cnt >= max)
				{
					printf("\t\t\t����Ϊ��ʷ��ȷ�����!\n");
					max = cnt;
				}
				else
					printf("\t\t\t��ʷ��߷�Ϊ: ", max);

			printf("\t\t\t-------------------------\n");
			system("pause");
			LiSh[cnt2] = cnt;
			cnt2++;
			break;

		case 2:
			printf("\n\n\n\n");
			printf("\t\t\t-------------------\n");
			int j;
			if (cnt2 == 0)
				printf("\n\t\t\t����ʱ��û����ʷ�ɼ�\n");
			else
			{
				for (j = 1; j <= cnt2; j++)
					printf("\t\t\t���ĵ�%d�γɼ�Ϊ: %d\n", j, LiSh[j - 1]);
				if (max != -1)
					printf("\t\t\t��ʷ��߳ɼ�Ϊ:%d\n", max);
			}
			printf("\n\t\t\t-------------------");
			printf("\n\t\t\t��1�������˵�����0�˳�����\n");
			scanf("%d", &x3);
			switch (x3)
			{
			case 1:
				break;
			case 0:
				button = 0;
				break;
			}
			printf("\t\t\t-------------------------\n");
			break;

		case 3:
			button = 0;
			break;
		}
	}
	system("cls");
	printf("\n\n\n\n\n\n\n");
	printf("\t\t\t\t--------\n");
	printf("\t\t\t\tллʹ��\n");
	printf("\t\t\t\t--------\n");
}

int main()
{
	menu();

	return 0;
}
