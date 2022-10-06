#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	char data;
	struct node *link;
}node;

typedef struct stack{
	node *top;
}stack;

void init(stack *ps){
	ps->top = NULL;
}

node *getnode(char ele){
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = ele;
	temp->link = NULL;
	return temp;
}

void push(stack *ps, char ele){
	struct node *newnode = getnode(ele), *temp = ps->top;
	if(ps->top == NULL){
		ps->top = newnode;
	}
	else{
		newnode->link = ps->top;
		ps->top = newnode;
	}
}

char pop(stack *ps){
	if (ps->top  == NULL){
		printf("Underflow\n");
		return(NULL);
	}
	else{
		node *temp = ps->top;
		char x = temp->data;
		ps->top = temp->link;
		free(temp);
		return(x);
	}
}

char peep(stack *ps){
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
	while(temp != NULL){
		printf("%c\n", temp->data);
		temp = temp->link;
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

