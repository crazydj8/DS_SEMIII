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

node *getnode(int ele){
    node *temp = (node *)malloc(sizeof(node));
    temp->data = ele;
    temp->llink = NULL;
    temp->rlink = NULL;
	return temp;
} 

void init(dlist *p){
    p->head = NULL;
}

void insert_front(dlist *p, int ele){
    node *newnode = getnode(ele);
    if(p->head == NULL){
        p->head = newnode;
    }
    else{
        newnode->rlink = p->head;
        p->head->llink = newnode;
        p->head = newnode;
    }
}

void insert_rear(dlist *p, int ele){
    node *newnode = getnode(ele), *current = p->head;
    if(p->head == NULL){
        p->head = newnode;
    }
    else{
        while(current->rlink != NULL){
            current = current->rlink;
        }
        current->rlink = newnode;
        newnode->llink = current;
    }
}

void delete_front(dlist *p){
    node *temp = p->head;
    if (p->head == NULL){
        printf("List is empty");
        return;
    }
    p->head->llink = NULL;
    p->head = p->head->rlink;
    printf("Deleted element = %d\n", temp->data); 
    free(temp);
}

void delete_rear(dlist *p){
    node *current = p->head;
    if (p->head == NULL){
        printf("List is empty");
        return;
    }
    while(current->rlink != NULL){
        current = current->rlink;
    }
    current->llink->rlink = NULL;
    printf("Deleted element = %d\n", current->data); 
    free(current);
}

void delete_spec(dlist *p, int n){
    if (p->head == NULL){
        printf("List is empty");
        return;
    }
    
}

void display(dlist *p){
    node *current = p->head;
    while(current != NULL){
        printf("%d\n", current->data);
        current = current->rlink;
    }
}

int main(){
    dlist l1;
    init(&l1);
    insert_front(&l1, 20);
    insert_front(&l1, 10);
    insert_front(&l1, 5);
    insert_front(&l1, 3);
    insert_rear(&l1, 100);
    insert_rear(&l1, 300);
    display(&l1);
    delete_front(&l1);
    delete_rear(&l1);
    display(&l1);

    return 0;
}