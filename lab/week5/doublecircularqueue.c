// make a program to make a circular double ended queue

/* Functions to be implemented:
1. create queue
2. init queue
3. insert rear
4. insert front
5. delete rear
6. delete front
7. display queue
8. destroy queue
9. isempty() //front == -1
10. isfull() //(front+1)%size = rear
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct queue{
	int front;
	int rear;
	int size;
	int *items;
}queue;

void init(queue *q){
	q->front = -1;
	q->rear = -1;
	q->items = NULL;
	q->size = -1;
}

void create_q(queue *q, int n){
	q->size = n;
	q->items = (int*)calloc(q->size, sizeof(int));
}

int isempty(queue *q){
	if(q->front == -1 && q->rear == -1){
		return 1;
	}
	else{
		return 0;
	}
}

int isfull(queue *q){
	if((q->rear + 1) % q->size == q->front){
		return 1;
	}
	else{
		return 0;
	}
}

void insert_rear(queue *q, int ele){
	if(isfull(q) == 1){
		printf("Overflow\n");
		return;
	}
	else if(isempty(q) == 1){
		q->front = 0;
		q->rear = 0;
		q->items[q->front] = ele;
	}
	else{
		q->rear = (q->rear + 1) % q->size;
		q->items[q->rear] = ele;
	}
	printf("%d Enqueued successfully\n", ele);
}

void insert_front(queue *q, int ele){
	if(isfull(q) == 1){
		printf("Overflow\n");
		return;
	}
	else if(isempty(q) == 1){
		q->front = 0;
		q->rear = 0;
		q->items[q->front] = ele;
	}
	else{
		q->front = (q->front - 1) % q->size;
		if(q->front < 0){
			q->front += q->size;
		}
		q->items[q->front] = ele;
	}
	printf("%d Enqueued successfully\n", ele);
}

int delete_front(queue *q){
	if (isempty(q)  == 1){
		printf("Underflow\n");
		return(NULL);
	}
	else{
		int x = q->items[q->front];
		if(q->front == q->rear){
			q->front = -1;
			q->rear = -1;
		}
		else{
			q->front = (q->front + 1) % q->size;
		}
		return x;
	}
}

int delete_rear(queue *q){
	if (isempty(q)  == 1){
		printf("Underflow\n");
		return(NULL);
	}
	else{
		int x = q->items[q->rear];
		if(q->front == q->rear){
			q->front = -1;
			q->rear = -1;
		}
		else{
			q->rear = (q->rear - 1) % q->size;
			if(q->rear < 0){
				q->rear += q->size;
			}
		}
		return x;
	}
}

void display(queue *q){
	int i = q->front, j = q->rear;
	if (i == -1 && j == -1){
		printf("Queue Empty\n");
		return;
	}
	printf("Queue:\n");
	while (i != j){
		printf("%d\n", q->items[i]);
		i= (i+1) % q->size;
	}
	printf("%d\n", q->items[i]);
}

void destroy(queue *q){
	free(q);
}

int main(){
	queue *q1 = (queue *)malloc(sizeof(queue));
	init(q1);
	int size = -1, x = -1;
	printf("Enter the size of the queue:");
	scanf("%d", &size);
	create_q(q1, size);
	insert_front(q1, 10);
	insert_rear(q1, 20);
	insert_front(q1, 5);
	insert_rear(q1, 30);
	insert_front(q1, 40);
	insert_rear(q1, 40);
	display(q1);
	x = delete_front(q1);
	printf("%d deleted successfully\n", x);
	x = delete_rear(q1);
	printf("%d deleted successfully\n", x);
	x = delete_front(q1);
	printf("%d deleted successfully\n", x);
	x = delete_rear(q1);
	printf("%d deleted successfully\n", x);
	display(q1);
	destroy(q1);
	return 0;
}