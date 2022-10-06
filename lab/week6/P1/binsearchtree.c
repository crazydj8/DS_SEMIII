#include <stdio.h>

#define SIZE 7

typedef struct tree{
	int data;
	int used;
}tree;

int t1[SIZE];

void init(int a[]){
	for (int i = 0; i < SIZE; i++){
		a[i] = -1;
	}
}

void insert(int ele){
	int p = 0;
	if (t1[p] == -1){
		t1[p] = ele;
	}
	else{
		while (t1[p] != -1 && p < SIZE){
			if (ele < t1[p]){
				p = 2 * p + 1;
			}
			else if (ele > t1[p]){
				p = 2 * p + 2;
			}
		}
		if (p >= SIZE){
			printf("Invalid Insertion \n");
		}
		else{
			t1[p] = ele;
		}
	}
}

int delete_t(int key){
	int prev = -1, curr = 0, next = -1, inprev = -1, insucc = -1;
	
}

int search(int key){
    int p = 0;
    while(t1[p] != -1 && p < SIZE){
        if(t1[p] == key){
            return 1;
        }  
        else if(key < t1[p]){
            p = 2 * p + 1;
        }
        else{
            p = 2 * p + 2;
        } 
    }
    return -1;
}

void inorder(int p){
	{
		if(t1[p] != -1 && p < SIZE){
			inorder(2 * p + 1);
			printf("%d\t", t1[p]);
			inorder(2 * p + 2);
		}
		else{
			return;
		}
	}
}

void preorder(int p){
	{
		if(t1[p] != -1 && p < SIZE){
			printf("%d\t", t1[p]);
			preorder(2 * p + 1);
			preorder(2 * p + 2);
		}
		else{
			return;
		}
	}
}

void postorder(int p){
	{
		if(t1[p] != -1 && p < SIZE){
			postorder(2 * p + 1);
			postorder(2 * p + 2);
			printf("%d\t", t1[p]);
		}
		else{
			return;
		}
	}
}

void display(){
	for (int i = 0; i < SIZE; i++){
		printf("%d\t", t1[i]);
	}
}

int main(){
	init (t1);
	insert(100);
	insert(120);
	insert(25);
	insert(50);
	//delete_t(120);
	printf("Array:\n");
	display();
	printf("\nInorder display:\n");
	inorder(0);
	printf("\nPreorder display:\n");
	preorder(0);
	printf("\nPostorder display:\n");
	postorder(0);
	printf("\n");
    printf("%d\n", search(120));
    printf("%d\n", search(222));
	return 0;
}
