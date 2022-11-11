#include <stdio.h>
#include<stdlib.h>
#define SIZE 13

void insertIntoHash(int key, int *hashtable)
{
    int prime = 7;
    int ind = key % SIZE;
    int full = 1;
    for(int i = 0; i < SIZE; i++){
        if(hashtable[i] == 0){
            full = 0;
            break;
        }
    }
    if(full == 1){
        printf("-1\n");
        return;
    }
    else{
        int i = 1;
        int hash1 = ind;
        int hash2 = prime - (key % prime);
        while(hashtable[ind] != 0){
            ind = (hash1 + i * hash2) % SIZE;
            i++;
        }
        hashtable[ind] = key;
    }
    // TODO
}

void printHashTable(int *hashtable)
{
    for(int i = 0; i < SIZE; i++){
        printf("%d ", hashtable[i]);
    }
    // TODO
}

int main()
{
    int i;
    int h[SIZE]={0};

    int n;
    scanf("%d", &n);

    int stk[n];
    for(int k=0;k<n;k++){
        scanf("%d", &stk[k]);
    }

    for(int i=0;i<n;i++){
        insertIntoHash(stk[i], h);
    }

    printHashTable(h);

    return 0;
}