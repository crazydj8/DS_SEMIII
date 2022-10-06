#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *link;
}node;

typedef struct clist{
    node *tail;
}clist;

node *getnode(int ele){
    node *temp = (node *)malloc(sizeof(node));
    temp->data = ele;
    temp->link = NULL;
	return temp;
} 

void init(clist *p){
    p->tail = NULL;
}

void insert_front(clist *p, int ele){
    node *newnode = getnode(ele);
    if(p->tail == NULL){
		newnode->link = newnode;
        p->tail = newnode;
    }
    else{
        newnode->link = p->tail->link;
		p->tail->link = newnode;
    }
}

void insert_rear(clist *p, int ele){
    node *newnode = getnode(ele);
    if(p->tail == NULL){
		newnode->link = newnode;
        p->tail = newnode;
    }
    else{
		newnode->link = p->tail->link;
		p->tail->link = newnode;
		p->tail = newnode;
    }
}

void delete_rear(clist *p){
	node *prev = p->tail->link, *temp = p->tail;
	if(p->tail == NULL){
		printf("Empty list.\n");
    }
	else if(p->tail->link == p->tail){
		printf("Deleted: %d\n", p->tail->data);
		p->tail = NULL;
		free(temp);
	}
	else{
		while(prev->link != p->tail){
			prev = prev -> link;
		}
		printf("Deleted: %d\n", p->tail->data);
		prev->link = p->tail->link;
		p->tail = prev;
		free(temp);
	}
}

void display(clist *p){
	node *current = p->tail->link;
	if(p->tail == NULL){
		printf("Empty list\n");
		return;
	}
	while(current != p->tail){
		printf("%d\n", current->data);
		current=current->link;
	}
	printf("%d\n", current->data);
}
	

int main(){
	clist l1;
	init(&l1);
	insert_front(&l1, 100);
	insert_rear(&l1, 200);
	insert_front(&l1, 50);
	insert_rear(&l1, 300);
	display(&l1);
	delete_rear(&l1);
	display(&l1);
	return 0;
}