#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *llink;
	struct node *rlink;
}node;

typedef struct cdlist{
    node *head;
}cdlist;

node *getnode(int ele){
    node *temp = (node *)malloc(sizeof(node));
    temp->data = ele;
    temp->llink = NULL;
	temp->rlink = NULL;
	return temp;
} 

void init(cdlist *p){
    p->head = NULL;
}

void insert_front(cdlist *p, int ele){
	node *newnode = getnode(ele);
    if(p->head == NULL){
		newnode->rlink = newnode;
        newnode->llink = newnode;
		p->head = newnode;
    }
    else{
		newnode->llink = p->head->llink;
		p->head->llink->rlink = newnode;
		p->head->llink = newnode;
		newnode->rlink = p->head;
		p->head = newnode;
    }
}

//head element is zeroth position
void insert_pos(cdlist *p, int pos, int ele){
	node *newnode = getnode(ele);
    if(p->head == NULL){
		newnode->rlink = newnode;
        newnode->llink = newnode;
		p->head = newnode;
    }
    else{
		node *temp = p->head;
		int a = 0;
		while(temp->rlink != p->head){
			a++;
			if (a == pos){
				break;
			}
			temp = temp->rlink;
		}
		if(temp->rlink == p->head && a < pos){
			printf("Please enter a position <= length of list");
		}
		else{
			newnode->rlink = temp->rlink;
			temp->rlink = newnode;
			newnode->llink = temp;
			newnode->rlink->llink = newnode;
		}
    }
}

void insert_rear(cdlist *p, int ele){
    node *newnode = getnode(ele);
    if(p->head == NULL){
		newnode->rlink = newnode;
        newnode->llink = newnode;
		p->head = newnode;
    }
    else{
		newnode->llink = p->head->llink;
		p->head->llink->rlink = newnode;
		p->head->llink = newnode;
		newnode->rlink = p->head;
    }
}

void delete_rear(cdlist *p){
	node *temp = p->head->llink;
	if(p->head == NULL){
		printf("Empty list.\n");
    }
	else if(p->head->rlink == p->head){
		printf("Deleted: %d\n", p->head->data);
		p->head = NULL;
		free(temp);
	}
	else{
		printf("Deleted: %d\n", temp->data);
		p->head->llink = temp->llink;
		temp->llink->rlink = p->head;
		free(temp);
	}
}

void delete_front(cdlist *p){
	node *temp = p->head;
	if(p->head == NULL){
		printf("Empty list.\n");
    }
	else if(p->head->rlink == p->head){
		printf("Deleted: %d\n", p->head->data);
		p->head = NULL;
		free(temp);
	}
	else{
		printf("Deleted: %d\n", temp->data);
		temp->llink->rlink = temp->rlink;
		temp->rlink->llink = temp->llink;
		p->head = temp->rlink;
		free(temp);
	}
}

void display(cdlist *p){
	node *current = p->head;
	if(p->head == NULL){
		printf("Empty list\n");
		return;
	}
	while(current->rlink != p->head){
		printf("%d\n", current->data);
		current=current->rlink;
	}
	printf("%d\n", current->data);
}

int main(){
	cdlist l1;
	init(&l1);
	insert_front(&l1, 10);
	insert_front(&l1, 5);
	insert_rear(&l1, 20);
	insert_front(&l1, 1);
	insert_pos(&l1, 2, 8);
	display(&l1);
	/*delete_rear(&l1);
	delete_front(&l1);
	display(&l1);*/
	return 0;
}