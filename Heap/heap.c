#include <stdio.h>
#include <stdlib.h>

int h1[20];


void heap_bottom_up(int n){
    int k, v, heap, j;
    for(int i = n / 2; i >= 1; i--){
        k = i;
        v = h1[k];
        heap = 0;
        while(!heap && 2 * k <= n){
            j = 2 * k;
            if(j < n){ //parent node has 2 child nodes
                if(h1[j + 1] > h1[j]){ //if right child value is more than left child
                    j++;
                }
            }
            if(v >= h1[j]){
                heap = 1;
            }
            else{
                h1[k] = h1[j];
                k = j;
            }
        }
        h1[k] = v;
    }
}

void heap_top_down(int n){
    int i = n, j = i / 2, v, temp;
    //v = h1[j];
    while(i > 1 && h1[i] >= h1[j]){
        temp = h1[j];
        h1[j] = h1[i];
        h1[i] = temp;
        i = j;
        j = i / 2;
    }
    //h1[j] = v;
}

void display(int n){
    printf("Heap = \n");
    for(int i = 1; i <= n; i++){
        printf("%d\n", h1[i]);
    }
}

int main(){
    int n;
    printf("Enter the number of elements:");
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        printf("Enter element:");
        scanf("%d", &h1[i]);
    }
    // for(int i = 1; i <= n; i++){
    //     heap_top_down(i);
    // }
    heap_bottom_up(n);
    display(n);
    return 0;
}    