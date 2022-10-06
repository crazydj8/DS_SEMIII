#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *link;
}node;

typedef struct llist{
	node *head;
}llist;

struct node *getnode(int ele){
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = ele;
	temp->link = NULL;
	return temp;
}

void init(llist *p){
	p->head = NULL;
}

void insert_front(llist *p, int ele){
	struct node *newnode = getnode(ele), *temp = p->head;
	if(p->head == NULL){
		p->head = newnode;
	}
	else{
		newnode->link = p->head;
		p->head = newnode;
	}
}

void insert_rear(llist *p, int ele){
	struct node *newnode = getnode(ele), *temp = p->head;
	if(p->head == NULL){
		p->head = newnode;
	}
	else{
		while(temp->link != NULL){
			temp = temp->link;
		}
		temp->link = newnode;
	}
}

void display(llist *p){
	node* temp = p->head;
	while(temp != NULL){
		printf("%d\n", temp->data);
		temp = temp->link;
	}
}

//display in reverse
void display_r(node *p){
	if(p->link != NULL){
		display_r(p->link);
	}
	printf("%d\n", p->data);
}

int main(){
	llist l1;
	init(&l1);
	insert_front(&l1, 20);
	insert_front(&l1, 10);
	insert_front(&l1, 5);
	display(&l1);
	printf("$$$$$$$$$$$$\n");
	display_r(l1.head);
	return 0;
}

