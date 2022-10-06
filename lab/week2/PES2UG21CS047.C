// merging 2 singly linked list
// create listA, B ordered listC
// ordered doubly linked list

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

void insert(llist *p){
	struct node *newnode = NULL, *curr = NULL, *prev = NULL;
	int ele = -1, con = -1;
	while(1){
		printf("Enter Data(Enter -1 to stop):");
		fflush(stdin);
		scanf("%d", &ele);
		if (ele == -1){
			break;
		}
		else{
			newnode = getnode(ele);
			curr = p->head;
			prev = NULL;
			if(p->head == NULL){
				p->head = newnode;
			}
			else{
				while(curr != NULL){
					con = 1;
					if(newnode->data <= curr->data && prev == NULL){
						newnode->link = curr;
						p->head = newnode;
						con = 0;
						break;
					}
					else if(newnode->data <= curr->data && prev != NULL){
						break;
					}
					else if(newnode->data > curr->data){
						prev = curr;
						curr = curr->link;
					}
				}	
				if (con == 1){
					prev->link = newnode;
					newnode->link = curr;
				}
			}			
		}
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

void merge(llist *a, llist *b, llist *c){
	node *curra = a->head, *currb = b->head;
	int which = 0;
	while(1){
		if(curra->data <= currb->data){
			insert_rear(c, curra->data);
			curra = curra->link;
		}
		else if(currb->data <= curra->data){
			insert_rear(c, currb->data);
			currb = currb->link;
		}
		if(currb == NULL){
			which = 2;
			break;
		}
		else if(curra == NULL){
			which = 1;
			break;
		}
	}
	if(which == 1){
		while(currb != NULL){
			insert_rear(c, currb->data);
			currb = currb->link;
		}
	}
	else if(which == 2){
		while(curra != NULL){
			insert_rear(c, curra->data);
			curra = curra->link;
		}
	}
}

void display(llist *p){
	node* temp = p->head;
	while(temp != NULL){
		printf("%d\n", temp->data);
		temp = temp->link;
	}
}
	
int main(){
	llist l1, l2, l3;
	init(&l1);
	init(&l2);
	init(&l3);
	insert(&l1);
	insert(&l2);
	printf("List l1 =\n");
	display(&l1);
	printf("List l2 =\n");
	display(&l2);
	merge(&l1, &l2, &l3);
	printf("List l3 =\n");
	display(&l3);
	return 0;
}
	