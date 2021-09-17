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
int DaAn[4];   //存放答案 ；
int DaAnYH[4]; //存放用户答案；
int TiHao[4];  //存放错题题号;
int LiSh[100]; //存放历史成绩；

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
	return (S->Top == -1); //判断栈顶是否指向-1
}

bool IsEmpty2(Stack2 S)
{
	return (S->Top == -1); //判断栈顶是否指向-1
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
		printf("堆栈空");
		return ERROR;
	}
	else
		return (S->Data[(S->Top)--]);
}

int IsHigherThan(char x, char y) //优先级定义
{
	if (((x == '*') || (x == '/')) && ((y == '+') || (y == '-')))
		return 1;
	else
		return 0;
}

void Exchange(char a[])
{
	//初始化两个栈，s1存储运算符,s2存储中间结果
	s1 = CreateStack(50);
	s2 = CreateStack(50);
	s3 = CreateStack(50);
	int i = 0;
	while (a[i] != '\0') //从左到右扫描表达式
	{
		if (a[i] >= '0' && a[i] <= '9') //遇到操作数时将其压入s2
			push(s2, a[i]);

		else
		{
			if (IsEmpty(s1) || a[i] == '(') //s1为空或运算符为左括号时直接入栈s1
				push(s1, a[i]);
			else if ((a[i]) == ')')
			{
				while (s1->Data[s1->Top] != '(')
					push(s2, pop(s1));
				pop(s1);
			}
			else
			{
				while (IsHigherThan(s1->Data[s1->Top], a[i])) //遇到运算符时，比较其于s1栈顶运算符的优先级
					push(s2, pop(s1));						  //当运算符大于s1栈顶运算符时压入s1,否则弹出s1栈顶元素
				push(s1, a[i]);								  //，将其放入s2，继续比较
			}
		}
		i++;
	}
	while (!IsEmpty(s1)) //把剩余的s1中的元素压入s2;
		push(s2, pop(s1));

	while (!IsEmpty(s2))
		push(s3, pop(s2));
}

int evaluation(Stack s3) //后缀表达式求值
{
	Stack2 S;
	S = CreateStack2(50);

	char a;
	int op1, op2;

	while (op1 != -1) //从左到右扫描后缀表达式
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

void GiveQuestion() //随机出题
{

	int j; //随机产生五个值为三十以内的数放入数组b
	for (j = 0; j < 5; j++)
		b[j] = rand() % 30;

	int i = 0; //从文件向二维数组写入数据
	FILE *fp;
	fp = fopen("test.txt", "r");
	for (i = 0; i < 30; i++)
		fscanf(fp, "%s", str[i]);
	fclose(fp);

	printf("\t\t\t-------------------------\n");
	for (i = 0; i < 5; i++) //随机从str题库中选五题放入a数组
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
		printf("\t\t\t\t|欢迎使用|\n");
		printf("\t\t\t\t-----------\n");

		Sleep(1000);
		system("cls");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t-------------------------\n");
		printf("\t\t\t输入序号选择您要进行的操作\n");
		printf("\t\t\t1:做题模式:\n");
		printf("\t\t\t2:历史成绩:\n");
		printf("\t\t\t3:退出\n");
		printf("\t\t\t-------------------------\n");
		printf("\t\t\t");
		scanf("%d", &x);
		system("cls");
		switch (x)
		{
		case 1:
			printf("\n\n\n\n\n\n\n");
			printf("\t\t\t-------------------------\n");
			printf("\t\t\t接下来将会给你五道题目,请\n");
			printf("\t\t\t请按顺序填写你的答案\n");
			printf("\t\t\t-------------------------\n");
			GiveQuestion();

			int n1, n2, n3, n4, n5;
			for (n1 = 0; n1 < 5; n1++)
			{
				Exchange(a[n1]);
				DaAn[n1] = evaluation(s3);
			}

			printf("\t\t\t-------------------------\n");
			printf("\t\t\t依次输入您的答案:\n");
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
			printf("\t\t\t您本次答对了%d道题目\n", cnt);
			printf("\t\t\t其中错误的题目和答案如下\n");
			for (n4 = 0; n4 < n3; n4++)
				printf("\t\t\t%s=%d\n", a[TiHao[n4]], DaAn[TiHao[n4]]);
			if (cnt2 > 0)
				if (cnt >= max)
				{
					printf("\t\t\t本次为历史正确率最高!\n");
					max = cnt;
				}
				else
					printf("\t\t\t历史最高分为: ", max);

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
				printf("\n\t\t\t您暂时还没有历史成绩\n");
			else
			{
				for (j = 1; j <= cnt2; j++)
					printf("\t\t\t您的第%d次成绩为: %d\n", j, LiSh[j - 1]);
				if (max != -1)
					printf("\t\t\t历史最高成绩为:%d\n", max);
			}
			printf("\n\t\t\t-------------------");
			printf("\n\t\t\t按1返回主菜单，按0退出程序\n");
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
	printf("\t\t\t\t谢谢使用\n");
	printf("\t\t\t\t--------\n");
}

int main()
{
	menu();

	return 0;
}
