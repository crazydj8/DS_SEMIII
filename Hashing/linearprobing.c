#include <stdio.h>
#include <stdio.h>

#define MAXSIZE 10

typedef struct node{
    int part_id;
    int qty;
    int used;
}parts;

void init(parts *ht){
    for(int i = 0; i < MAXSIZE; i++){
        ht[i].used = -1;
    }
}

void insert(parts *ht, int id, int qty, int *count){
    int ind = id % MAXSIZE;
    if (*count == MAXSIZE){
        printf("Table full\n");
        return;
    }
    while(ht[ind].used != -1){
        ind = (ind + 1) % MAXSIZE;
    }
    ht[ind].used = 1;
    ht[ind].part_id = id;
    ht[ind].qty = qty;
    (*count)++;
}


int search(parts *ht, int key, int *count){
    if(*count == 0){
        return 0;
    }
    int ind = key % MAXSIZE;
    int i = 0;
    while(ht[ind].part_id != key && i < *count){
        ind = (ind + 1) % MAXSIZE;
        if(ht[ind].used == 1){
            i++;
        }
    }
    if(ht[ind].part_id == key && ht[ind].used == 1){
        printf("Part id: %d, Qty:, %d\n", ht[ind].part_id, ht[ind].qty);
        return 1;
    }
    else{
        return 0;
    }
}

void htdelete(parts *ht, int key, int *count){
    if(*count == 0){
        printf("Hash table empty\n");
        return;
    }
    int ind = key % MAXSIZE;
    int i = 0;
    while(ht[ind].part_id != key && i < *count){
        ind = (ind + 1) % MAXSIZE;
        if(ht[ind].used == 1){
            i++;
        }
    }
    if(ht[ind].part_id == key && ht[ind].used == 1){
        ht[ind].used = -1;
        (*count)--;
    }
    else{
        printf("Part Id not found\n");
    }
}

void display(parts *ht, int *count){
    if(*count == 0){
        printf("Hash table empty\n");
        return;
    }
    for(int i = 0; i < MAXSIZE; i++){
        printf("%d::::", i);
        if(ht[i].used == 1){
            printf("Part Id: %d Qty: %d\n", ht[i].part_id, ht[i].qty);
        }
        else{
            printf("\n");
        }
    }
}

int main(){
    int ch, id, qty, count = 0;
    parts p[MAXSIZE];
    init(p);
    do{
        printf("Menu- 1.Insert 2. Delete 3. Search 4. Display 5. Exit. Enter your choice:");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                printf("Enter Part ID:");
                scanf("%d", &id);
                printf("Enter Quantity:");
                scanf("%d", &qty);
                insert(p, id, qty, &count);
                break;
            case 2:
                printf("Enter Part ID you want to delete:");
                scanf("%d", &id);
                htdelete(p, id, &count);
                break;
            case 3:
                printf("Enter Part ID you want to search:");
                scanf("%d", &id);
                int x = search(p, id, &count);
                if(x == 0){
                    printf("Part ID not found");
                }
                break;
            case 4:
                display(p, &count);
                break;
        }
    }while (ch != 5);
    return 0;
}