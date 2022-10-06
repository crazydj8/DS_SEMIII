// double pointer implementation of josephus problem
#include <stdio.h>
#include <stdlib.h>


typedef struct node{
	int name;
	struct node *link;
}node;

void create_cirlist(node **tail, int num){
	node *newnode, *prev, *temp, *first;
	for(int i = 0; i < num; i++){
		newnode = (node *)malloc(sizeof(node));
		newnode->name = i;
		newnode->link = NULL;
		if(i != 0){
			prev->link = newnode;
		}
		else{
			first = newnode;
		}
		prev = newnode;
	*tail = newnode;
	(*tail)->link = first;
	}
}

int survivor(node **tail, int n){
	node *cur, *prev = NULL;
	cur = (*tail)->link;
	while(cur->link != cur){
		for(int i = 0; i < n - 1; i++){
			prev = cur;
			cur = cur->link;
		}
		prev->link = cur->link;
		printf("The Soldier removed from circle is : %d\n", cur->name);
		free(cur);
		cur = prev->link;
	}
	(*tail) = cur;
	return ((*tail)->name);
}

int main(){
	struct node *tail = NULL;
	int n, m;
	printf("Enter Number of Soldiers:");
	scanf("%d", &n);
	create_cirlist(&tail, n);
	printf("Enter Number pulled from chit:");
	scanf("%d", &m);
	survivor(&tail, m);
	return 0;
}