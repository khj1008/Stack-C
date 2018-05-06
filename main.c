#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int MAX = 20;
typedef struct stackNode {
	int data;
	struct stackNode* link;
}stackNode;

stackNode* top;
stackNode* free_s;
stackNode* createfree();
void push(int item);
int pop();
void delete();
int peek();
void returnNode(stackNode* old);
stackNode* getNode();
void printstack();
void printfree();
void printmenu();

int main()
{
	free_s = createfree();
	int item;
	int func;
	while (1) {
		printf("\n");
		printmenu();
		printf("����� �Է��ϼ��� : ");
		scanf("%d", &func);
		switch (func) {
		case 1:
			printf("������ ������ �Է��ϼ��� : ");
			scanf("%d", &item);
			push(item);
			printstack();
			printfree();
			break;
		case 2:
			item = pop();
			printf("������ ���� : %d\n", item);
			printstack();
			printfree();
			break;
		case 3:
			item = peek();
			printf("top�� �ִ� ���� : %d\n", item);
			printstack();
			printfree();
			break;
		case 4:
			delete();
			printstack();
			printfree();
			break;
		case 5:
			exit(1);
		default :
			printf("�߸� �Է��ϼ̽��ϴ�.\n");
			break;
		}
	}

	return 0;
}

stackNode* createfree()
{
	stackNode* free;
	free = (stackNode*)malloc(MAX*sizeof(stackNode));
	int i;
	for (i = 0; i < MAX - 1; i++) {
		free[i].link = &free[i + 1];
		free[i].data = 0;
	}
	free[MAX - 1].data = 0;
	free[MAX-1].link = NULL;
	return free;
}

stackNode* getNode()
{
	stackNode* newNode;
	newNode = free_s;
	free_s = free_s->link;
	return newNode;
}

void returnNode(stackNode* old)
{
	old->link = free_s;
	free_s = old;
}

void push(int item)
{
	stackNode* temp;
	temp = getNode();
	temp->data = item;
	temp->link = top;
	top = temp;
}

int pop()
{
	int item;
	stackNode* temp = top;
	if (top == NULL) {
		printf("Stack is empty!\n");
		return 0;
	}
	else{
	item = temp->data;
	top = temp->link;
	returnNode(temp);
	return item;
	}
}

void delete()
{
	stackNode* temp = top;
	if (top == NULL) {
		printf("Stack is empty!\n");
		return;
	}
	else{
	top = temp->link;
	returnNode(temp);
	}
}
int peek()
{
	int item;
	if (top == NULL) {
		printf("Stack is empty!\n");
		return 0;
	}
	else {
		item = top->data;
		return item;
	}
}

void printstack()
{
	stackNode* temp;
	temp = top;
	printf("Stack [");
	while (temp != NULL) {
		printf(" %d ", temp->data);
		temp = temp->link;
	}
	printf("]\n");
}

void printfree()
{
	stackNode* temp;
	temp = free_s;
	printf("Free [");
	while (temp != NULL) {
		printf(" %d ", temp->data);
		temp = temp->link;
	}
	printf("]\n");
}

void printmenu()
{
	printf("--------�޴�--------\n");
	printf("1. ���ÿ� ���� �����ϱ�\n");
	printf("2. ���ÿ��� ���� ��������\n");
	printf("3. top�� �ִ� ���� Ȯ���ϱ�\n");
	printf("4. top�� �ִ� ���� �����ϱ�\n");
	printf("5. �����ϱ�\n");
}