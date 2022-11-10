#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

// separate chaining / open hashing

typedef struct node{
    int part_id;
    int qty;
    struct node *link;
}parts;

typedef struct ht{
    parts *head;
}hash_table;

void init(hash_table list[]){
    for(int i = 0; i < SIZE; i++){
        list[i].head = NULL;
    }
}

void insert(hash_table *ht, int part_id, int qty){
    parts *p;
    p = (parts *)malloc(sizeof(parts));
    p->part_id = part_id;
    p->qty = qty;
    p->link = NULL;
    int index = part_id % SIZE;
    p->link = ht[index].head;
    ht[index].head = p;
} 

void display(hash_table *ht){
    parts *temp = NULL;
    for(int i = 0; i < SIZE; i++){
        temp = ht[i].head;
        while(temp != NULL){
            printf("%d \t", temp->part_id);
            temp = temp->link;
        }
        printf("\n");
    }
}

int main(){
    int ch, partid, qty;
    hash_table ht[SIZE];
    init(ht);
    do{
        printf("Enter choice(0-3):");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                printf("Enter the part id and qty");
                scanf("%d %d", &partid, &qty);
                insert(ht, partid, qty);
                break;
            case 2:
                display(ht);
                break;
        }
    }while (ch != 3);
    return 0;
}