// create listA, B ordered listC
// ordered doubly linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *llink;
	struct node *rlink;
}node;

typedef struct dlist{
	node *head;
}dlist;

struct node *getnode(int ele){
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = ele;
	temp->rlink = NULL;
	temp->llink = NULL;
	return temp;
}

void init(dlist *p){
	p->head = NULL;
}

void insert(dlist *p){
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
						newnode->rlink = curr;
						curr->llink = newnode;
						p->head = newnode;
						con = 0;
						break;
					}
					else if(newnode->data <= curr->data && prev != NULL){
						break;
					}
					else if(newnode->data > curr->data){
						prev = curr;
						curr = curr->rlink;
					}
				}	
				if (con == 1){
					prev->rlink = newnode;
					newnode->llink = prev;
					newnode->rlink = curr;
					if (curr != NULL){
						curr->llink = newnode;
					}
				}
			}			
		}
	}
}

void insert_rear(dlist *p, int ele){
	struct node *newnode = getnode(ele), *temp = p->head;
	if(p->head == NULL){
		p->head = newnode;
	}
	else{
		while(temp->rlink != NULL){
			temp = temp->rlink;
		}
		temp->rlink = newnode;
		newnode->llink = temp;
	}
}

void merge(dlist *a, dlist *b, dlist *c){
	node *curra = a->head, *currb = b->head;
	int which = 0;
	while(1){
		if(curra->data <= currb->data){
			insert_rear(c, curra->data);
			curra = curra->rlink;
		}
		else if(currb->data <= curra->data){
			insert_rear(c, currb->data);
			currb = currb->rlink;
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
			currb = currb->rlink;
		}
	}
	else if(which == 2){
		while(curra != NULL){
			insert_rear(c, curra->data);
			curra = curra->rlink;
		}
	}
}

void display(dlist *p){
	node* temp = p->head;
	while(temp != NULL){
		printf("%d\n", temp->data);
		temp = temp->rlink;
	}
}
	
int main(){
	dlist l1, l2, l3;
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
	