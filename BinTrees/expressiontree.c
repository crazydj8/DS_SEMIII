#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node{
    char data;
    struct node *rlink;
    struct node *llink;
}node;

node *stk[20];
/*typedef struct tree{
	node *root;
}*/

node *getnode(char ele){
	node *temp = (node*)malloc(sizeof(node));
	temp->data = ele;
	temp->llink = NULL;
	temp->rlink = NULL;
	return temp;
}

node *create_tree(){
	char postfix[30], ch;
	node *temp;
	int i = 0, k = -1;
	printf("Enter the postfix expression:");
	scanf("%s", postfix);
	while(postfix[i] != '\0'){
		ch = postfix[i];
		temp = getnode(ch);
		if(isalpha(ch)){
			stk[++k] = temp;
		}
		else{
			temp->rlink = stk[k--];
			temp->llink = stk[k--];
			stk[++k] = temp;
		}
		i++;
	}
	return temp;
}

float eval(node *root){
	float x,  rval, lval;
	if (root == NULL){
		return 0;
	}
	if(root->llink == NULL && root->rlink == NULL){
		printf("Enter the value of %c: ", root->data);
		fflush(stdin);
		scanf("%f", &x);
		return x;
	}
	lval = eval(root->llink);
	rval = eval(root->rlink);
	switch(root->data){
		case '+':
			return lval + rval;
		case '-':
			return lval - rval;
		case '*':
			return lval * rval;
		case '/':
			return lval / rval;
		case '^':
			int ans = 1;
			while(rval != 0){
				ans *= lval;
				--rval;
			}
			return ans;
	}
	return -1;
}
			
	

void inorder(node *root){
	if(root != NULL){
		inorder(root->llink);
		printf("%c", root->data);
		inorder(root->rlink);
	}
	else{
		return;
	}
}

int main(){
	node *root = NULL;
	root = create_tree();
	inorder(root);
	printf("\n");
	float res = eval(root);
	printf("\nResult = %0.2f\n", res);
	return 0;
}