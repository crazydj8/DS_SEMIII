//postfix evaluation using array and linked list

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	int data;
	struct node *link;
}node;

typedef struct stack{
	node *top;
}stack;

void init(stack *ps){
	ps->top = NULL;
}

node *getnode(int ele){
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = ele;
	temp->link = NULL;
	return temp;
}

void push(stack *ps, int ele){
	struct node *newnode = getnode(ele), *temp = ps->top;
	if(ps->top == NULL){
		ps->top = newnode;
	}
	else{
		newnode->link = ps->top;
		ps->top = newnode;
	}
}

int pop(stack *ps){
	if (ps->top  == NULL){
		printf("Underflow\n");
		return(NULL);
	}
	else{
		node *temp = ps->top;
		int x = temp->data;
		ps->top = temp->link;
		free(temp);
		return(x);
	}
}

int peep(stack *ps){
	if (ps->top  == NULL){
		printf("Underflow\n");
		return(NULL);
	}
	else{
		return (ps->top->data);
	}
}

void display(stack *ps){
	node *temp = ps->top;
	printf("Stack:\n");
	while(temp != NULL){
		printf("%d\n", temp->data);
		temp = temp->link;
	}
}

int isdigit(int x){
	if (x >= 0 && x <= 9){
		return 1;
	}
	else{
		return 0;
	}
}

float postfix_eval(char *exp){
	stack s1;
	init(&s1);
	char op1, op2;
	int op3;
	int len = strlen(exp);
	float x = 0;
	for (int i = 0; i < len; i++){
		op3 = exp[i] - 48;
		if (isdigit(op3) == 1){
			push(&s1, op3);
		}
		else{
			op1 = pop(&s1);
			op2 = pop(&s1);
			if (exp[i] == '+'){
				x = op2 + op1;
			}
			else if (exp[i] == '-'){
				x = op2 - op1;
			}
			else if (exp[i] == '*'){
				x = op2 * op1;
			}
			else if (exp[i] == '/'){
				x = op2 / (float)op1;
			}
			else if (exp[i] == '%'){
				x = op2 % op1;
			}
			push(&s1, x);
		}
		display(&s1);
	}
	return(x);
}

int main(){
	char exp[20];
	printf("Enter Expression: ");
	scanf("%s", exp);
	float x = postfix_eval(exp);
	printf("Answer is: %f\n", x); 
	return 0;
}

