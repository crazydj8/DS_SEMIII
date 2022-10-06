#include <stdio.h>
#define STACKSIZE 5

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
	for(int i = ps->top; i >= 0; i--){
		printf("%d\n", ps->items[i]);
	}
}

int main(){
	stack s1;
	init(&s1);
	push(&s1, 10);
	push(&s1, 20);
	push(&s1, 30);
	push(&s1, 40);
	push(&s1, 50);
	push(&s1, 60);
	printf("Element at top = %d\n", peep(&s1)); 
	display(&s1);
	printf("Deleted %d\n", pop(&s1));
	printf("New Element at top = %d\n", peep(&s1));
	printf("New:\n");
	display(&s1);
	return 0;
}