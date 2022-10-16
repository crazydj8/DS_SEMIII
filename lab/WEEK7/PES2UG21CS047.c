#include <stdio.h>
#include <stdlib.h>

typedef struct MinHeap MinHeap;
struct MinHeap {
    int* arr;
    int size;  //size of the heap
};

MinHeap* init_minheap(int size) {
    MinHeap* minheap = (MinHeap*)calloc(1, sizeof(MinHeap));
    minheap->size = size;
    minheap->arr = (int*)calloc(size, sizeof(int));
    return minheap;
}

void create_minheap(MinHeap *heap) 
{   
    //IMPLEMENT HERE
    int k, v, hc, j;
    for(int i = heap->size / 2; i >= 1; i--){
        k = i;
        v = heap->arr[k];
        hc = 0;
        while(!hc && 2 * k <= heap->size){
            j = 2 * k;
            if(j < heap->size){ //parent node has 2 child nodes
                if(heap->arr[j + 1] < heap->arr[j]){ //if right child value is more than left child
                    j++;
                }
            }
            if(v <= heap->arr[j]){
                hc = 1;
            }
            else{
                heap->arr[k] = heap->arr[j];
                k = j;
            }
        }
        heap->arr[k] = v;
    }
}


void print_minheap(MinHeap* heap) {
    // IMPLEMENT HERE
    for(int i = 1; i <= heap->size; i++){
        printf("%d ", heap->arr[i]);
    }
}

void free_minheap(MinHeap* heap) {
    if (!heap)
        return;
    free(heap->arr);
    free(heap);
}

int main() {

    int capacity; 
    scanf("%d", &capacity);
    MinHeap* heap = init_minheap(capacity); //number of elements 
    int i=1;
    while(i <= capacity){
        scanf("%d", &heap->arr[i++]);

    }
    create_minheap(heap);
    print_minheap(heap);
    free_minheap(heap);
    return 0;
}