// delete alternate nodes from a singly linked list. list can have no, odd and even number of nodes. deletetion will be of even number nodes.
// made by Akshat Aryan
//SRN: PES2UG21CS047
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *link;
}node;

typedef struct llist{
	struct node *head;
}llist;

void init(llist *p){
	p->head = NULL;
}

node *get_node(int ele){
	node *newnode = (node*)malloc(sizeof(node));
	newnode->data = ele;
	newnode->link = NULL;
	return newnode;
}

void insert_rear(llist *p, int ele){
	node *newnode = get_node(ele), *current = p->head;
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

void read(llist *n){
	int ele = 1, con = -1;
	while(1){
		printf("Enter data:"); 
		fflush(stdin);
		scanf("%d", &ele);
		insert_rear(n, ele);
		printf("Continue to enter data?(0/1)"); 
		fflush(stdin);
		scanf("%d", &con);
		while(con != 1 && con != 0){
			printf("Please enter 1 to continue or 0 to stop.");
			fflush(stdin);
			scanf("%d", &con);
		}
		if(con == 0){
			break;
		}
	}
}

void delete_alt(llist *p){
	if (p->head == NULL){
        printf("List is empty");
        return;
    }
	int a = 1;
	node *current = p->head, *prev = NULL;
	while(current != NULL){
		if (a % 2 == 0){
			prev->link = current->link;
			printf("Deleted: %d\n", current->data);
			free(current);
			current = prev->link;
		}
		else{
			prev = current;
			current = current -> link;
		}
		a++;
	}
}

void display(llist *p){
    node *current = p->head;
    while(current != NULL){
        printf("%d\n", current->data);
        current = current->link;
    }
}

int main(){
	llist l1;
	init(&l1);
	read(&l1);
	printf("List before adding data:\n");
	display(&l1);
	delete_alt(&l1);
	printf("List after adding data:\n");
	display(&l1);
	return 0;
}