//Week 1 program 1
//Written by Akshat Aryan
//SRN: PES2UG21CS047

#include <stdio.h>
#include <stdlib.h>

typedef struct polynode{
	int coeff;
	int expo;
	struct polynode* link;
}polynode;

typedef struct llist{
    polynode *head;
}llist;

polynode* allocate(int c, int e){
	polynode *newnode = (polynode*)malloc(sizeof(polynode));
	newnode->coeff = c;
	newnode->expo = e;
	newnode->link = NULL;
	return newnode;
}

void init(llist *p){
    p->head = NULL;
}

void insert_rear(llist *p, int c, int e){
    polynode *newnode = allocate(c, e), *current = p->head;
    if(p->head == NULL){
        p->head = newnode;
    }
    else{
        while(current->link != NULL){
            current = current->link;
        }
        current->link = newnode;
    }
}

void readpoly(llist *n){
	int c = 1, e = 1;
	while(1){
		printf("Enter Coefficient:"); 
		fflush(stdin);
		scanf("%d", &c);
		printf("Enter Exponent(Enter -1 to stop input):"); 
		fflush(stdin);
		scanf("%d", &e);
		if(e == -1){
			break;
		}
		insert_rear(n, c, e);
	}
}

void addpoly(llist *c, llist *a, llist *b){
	polynode *curra = a->head, *currb = b->head;
	int newc, newe;
	int which = 0;
	while(1){
		if(curra->expo > currb->expo){
			newc = curra->coeff;
			newe = curra->expo;
			insert_rear(c, newc, newe);
			curra = curra->link;
		}
		else if(curra->expo < currb->expo){
			newc = currb->coeff;
			newe = currb->expo;
			insert_rear(c, newc, newe);
			currb = currb->link;
		}
		else{
			newc = curra->coeff + currb->coeff;
			if(newc != 0){
				newe = currb->expo;
				insert_rear(c, newc, newe);
			}
			curra = curra->link;
			currb = currb->link;
		}
		if(curra == NULL){
			which = 1;
			break;
		}
		else if(currb == NULL){
			which = 2;
			break;
		}
	}
	if(which == 1){
		while(currb != NULL){
			newc = currb->coeff;
			newe = currb->expo;
			insert_rear(c, newc, newe);
			currb = currb->link;
		}
	}
	else if(which == 2){
		while(currb != NULL){
			newc = curra->coeff;
			newe = curra->expo;
			insert_rear(c, newc, newe);
			curra = curra->link;
		}
	}
}


void display(llist *p){
	polynode *current = p->head;
	while(current != NULL){
		printf("%d, %d\n", current->coeff, current->expo);
		current = current->link;
    }
}

int main(){
    llist polyA, polyB, polyC;
	init(&polyA);
	init(&polyB);
	init(&polyC);
	printf("Enter data for PolyA:\n");
	readpoly(&polyA);
	printf("Enter data for PolyB:\n");
	readpoly(&polyB);
	printf("PolyA:\n");
	display(&polyA);
	printf("PolyB:\n");
	display(&polyB);
	addpoly(&polyC, &polyA, &polyB);
	printf("polyC:\n");
	display(&polyC);
    return 0;
}