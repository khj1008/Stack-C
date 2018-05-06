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
		printf("기능을 입력하세요 : ");
		scanf("%d", &func);
		switch (func) {
		case 1:
			printf("삽입할 정수를 입력하세요 : ");
			scanf("%d", &item);
			push(item);
			printstack();
			printfree();
			break;
		case 2:
			item = pop();
			printf("가져온 원소 : %d\n", item);
			printstack();
			printfree();
			break;
		case 3:
			item = peek();
			printf("top에 있는 원소 : %d\n", item);
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
			printf("잘못 입력하셨습니다.\n");
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
	printf("--------메뉴--------\n");
	printf("1. 스택에 원소 삽입하기\n");
	printf("2. 스택에서 원소 가져오기\n");
	printf("3. top에 있는 원소 확인하기\n");
	printf("4. top에 있는 원소 삭제하기\n");
	printf("5. 종료하기\n");
}