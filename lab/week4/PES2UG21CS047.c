// Infix to prefix
// Complete algorithm by Akshat Aryan
// SRN: PES2UG21CS047

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
		//printf("Underflow\n");
		return('\0');
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
		//printf("Underflow\n");
		return('\0');
	}
	else{
		return (ps->top->data);
	}
}

void display(stack *ps){
	node *temp = ps->top;
	if(temp == NULL){
		printf("Stack Empty\n");
		return;
	}
	printf("Stack=\n");
	while(temp != NULL){
		printf("%c\n", temp->data);
		temp = temp->link;
	}
}

char bracket_reverse(char a){
	switch (a){
		case '(':
			return (')');
		case ')':
			return ('(');
		case ']':
			return ('[');
		case '[':
			return ('[');
		case '}':
			return ('{');
		case '{':
			return ('}');
		default:
			return(a);
	}
	return('\0');
}

void reverse(char *exp, char *nexp){
	int i = 0, j = strlen(exp) - 1;
	while (exp[i] != '\0'){
		nexp[i++] = bracket_reverse(exp[j--]);
	}
	nexp[i++] = '\0';
}

int isalnum(char a){
	if (a >= 97 && a <= 122){
		return 1;
	}
	else if (a >= 65 && a <= 90){
		return 1;
	}
	else if(a >= 48 && a <= 57){
		return 1;
	}
	else{
		return 0;
	}
}

int isoperator(char a){
	if(a == '+' || a == '-' || a == '*' || a == '/' || a == '^' || a == '(' || a == '[' || a == '{'){
		return 1;
	}
	else{
		return 0;
	}
}

int precedence(char a){
	switch (a){
		case '+':
			return 1;
		case '-':
			return 1;
		case '*':
			return 2;
		case '/':
			return 2;
		case '^':
			return 3;
		case '(':
			return 4;
		case '[':
			return 4;
		case '{':
			return 4;
	}
	return -1;
}

int checkprec(char a, char b){
	if (precedence(a) > precedence(b)){
		return 1;
	}
	else if (precedence(a) < precedence(b)){
		return -1;
	}
	else{
		return 0;
	}
}

int bothpower(char a, char b){
	if(a == '^'){
		if(b == '^'){
			return 1;
		}
	}
	else{
		return 0;
	}
	return -1;
}

void infixtoprefix(){
	printf("Enter Expression:");
	char oexp[20], exp[20], nexp[20], pexp[20];
	scanf("%s", oexp);
	reverse(oexp, exp);
	stack s1;
	init(&s1);
	int condition = 0, brace = 1;
	int j = 0, i = 0;
	char top = peep(&s1);
	while (exp[i] != '\0'){
		if(isalnum(exp[i]) == 1){
			nexp[j++] = exp[i];
		}
		else if(isoperator(exp[i]) == 1){
			if(top == '\0'){
				if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{'){
					brace++;
				}
				push(&s1, exp[i]);
			}
			
			else if(checkprec(exp[i], top) > 0 || checkprec(exp[i], top) == 0 && bothpower(exp[i], top) == 1){
				top = peep(&s1);
				if (top == '(' || top == '[' || top == '{'){
					brace++;
				}
				push(&s1, exp[i]);
			}
			
			else if(checkprec(exp[i], top) < 0 || checkprec(exp[i], top) == 0 && bothpower(exp[i], top) != 1){
				top = peep(&s1);
				while (top != '\0' && checkprec(exp[i], top) < 0){
					if(top != '(' && top != '[' && top != '{'){
						nexp[j++] = pop(&s1);
					}
					else{
						break;
					}
					top = peep(&s1);
				}
				push(&s1, exp[i]);
			}
		}
		else if(exp[i] == ')'){
			brace--;
			top = peep(&s1);
			while(top != '('){
				if (top == '\0'){
					condition = 1;
					break;
				}
				nexp[j++] = pop(&s1);
				top = peep(&s1);
			}
			if (condition != -1){
				pop(&s1);
			}
		}
		else if(exp[i] == ']'){
			brace--;
			top = peep(&s1);
			while(top != '['){
				if (top == '\0'){
					condition = 1;
					break;
				}
				nexp[j++] = pop(&s1);
				top = peep(&s1);
			}
			if (condition != -1){
				pop(&s1);
			}
		}
		else if(exp[i] == '}'){
			brace--;
			top = peep(&s1);
			while(top != '{'){
				if (top == '\0'){
					condition = 1;
					break;
				}
				nexp[j++] = pop(&s1);
				top = peep(&s1);
			}
			if (condition != -1){
				pop(&s1);
			}
		}
		if (i == strlen(exp) - 1){
			top = peep(&s1);
			while(top != '\0'){
				if(top != '(' && top != '[' && top != '{'){
					nexp[j++] = pop(&s1);
				}
				else{
					pop(&s1);
				}
				top = peep(&s1);
			}
		}
		if (brace != 0){
			condition = 0;
		}
		if (condition == 1){
			printf("Wrong Input");
			return;
		}	
		i++;
		top = peep(&s1);
	}
	nexp[j++] = '\0';
	reverse(nexp, pexp);
	printf("%s", pexp);
}

int main(){
	infixtoprefix();
	return 0;
}
	