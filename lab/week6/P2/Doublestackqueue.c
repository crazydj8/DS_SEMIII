#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXSIZE 20

typedef struct{
    int stack1[MAXSIZE];
    int stack2[MAXSIZE];
    int top1;
    int top2;
}MyQueue;

void init(MyQueue *q){
    q->top1 = -1;
    q->top2 = -1;
}

bool empty(MyQueue *q);
void enqueue(MyQueue *q, int x);
int dequeue(MyQueue *q);
int peek(MyQueue *q);
int validate(MyQueue *q, int x);

int main(){
    MyQueue *q1;
    init(q1);
    char choice[5];
    int count = 0, n, num = -1, res = -1;
    fflush(stdin);
    scanf("%d", &n);
    while(n > 0){
        count = 0;
        fflush(stdin);
        gets(choice);
        while(choice[count] != '\0'){
            count++;
        }
        if(count == 3){
            num = choice[2] - '0';
        }
        switch (choice[0]){
            case 'E':
                enqueue(q1, num);
                break;
            case 'D':
                res = dequeue(q1);
                printf("%d ", res);
                break;
            case 'V':
                res = validate(q1, num);
                printf("%d ", res);
                break;
            case 'P':
                res = peek(q1);
                printf("%d ", res);
                break;
        }
        n--;
    }
    return 0;
}

bool empty(MyQueue *q){
    if (q->top1 == -1){
        return true;
    }
    else{
        return false;
    }
}

void enqueue(MyQueue *q, int x){
    (q->top1)++;
	if(q->top1 == MAXSIZE - 1){
        return;
    }
    else{
        q->stack1[q->top1] = x;
        printf("1 ");
    }
}

int dequeue(MyQueue *q){
    int x;
    if(empty(q) == true){
        return -1;
    }
    else{
        while(q->top1 >= 0){
            q->stack2[++(q->top2)] = q->stack1[(q->top1)--];
        }
        x = q->stack2[(q->top2)--];
        while(q->top2 >= 0){
            q->stack1[++(q->top1)] = q->stack2[(q->top2)--];
		}
		return x;
    }
}

int peek(MyQueue *q){
    if(empty(q) == true){
        return -1;
    }
    else{
        return q->stack1[0];
    }
}

int validate(MyQueue *q, int x){
    if(empty(q) == true){
        return -1;
    }
	else if(x == 0){
		return q->stack1[q->top1];
	}
    else{
		int llim = q->top1 - x;
        while (q->top1 > llim){
            q->stack2[++(q->top2)] = q->stack1[(q->top1)--];
            if(q->top1 == -1){
                while(q->top2 >= 0){
                    q->stack1[++(q->top1)] = q->stack2[(q->top2)--];
                }
                return -1;
            }
        }
        int k = q->stack1[q->top1];
        while(q->top2 >= 0){
            q->stack1[++(q->top1)] = q->stack2[(q->top2)--];
        }
        return k;
    }
}