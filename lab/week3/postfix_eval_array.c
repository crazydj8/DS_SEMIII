#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACKSIZE 20

typedef struct stack{
	int top;
	int items[STACKSIZE];
}stack;

void init(stack *ps){
	ps->top = -1;
}

void push(stack *ps, int ele){
	if(ps->top == STACKSIZE -1){
		printf("Stack Overflow\n");
	}
	else{
		(ps->top)++;
		ps->items[ps->top] = ele;
	}
}

int pop(stack *ps){
	if (ps->top  == -1){
		printf("Underflow\n");
		return(NULL);
	}
	else{
		int x = ps->items[ps->top];
		(ps->top)--;
		return x;
	}
}

int peep(stack *ps){
	if (ps->top  == -1){
		printf("Underflow\n");
		return(NULL);
	}
	else{
		return (ps->items[ps->top]);
	}
}


void display(stack *ps){
	printf("Stack:\n");
	for(int i = ps->top; i >= 0; i--){
		printf("%d\n", ps->items[i]);
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

