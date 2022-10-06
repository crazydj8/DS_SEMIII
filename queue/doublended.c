#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct queue{
	int items[MAX_SIZE];
	int front, rear;
}queue;

void init(queue *q){
	q->front = -1;
	q->rear = -1;
}

void insert_rear(queue *q, int ele){
	if ((q->rear + 1) % MAX_SIZE == q->front){
		printf("Overflow\n");
		return;
	}
	else if(q->rear == MAX_SIZE - 1){
		q->rear = 0;
	}
	else{
		q->rear++;
	}
	q->items[q->rear] = ele;
	if (q->front == -1){
		q->front = 0;
	}
	printf("%d Enqueued successfully at rear\n", ele);
}

void insert_front(queue *q, int ele){
	if ((q->rear + 1) % MAX_SIZE == q->front){
		printf("Overflow\n");
		return;
	}
	else if(q->front == 0){
		q->front = MAX_SIZE - 1;
	}
	else{
		q->front--;
	}
	q->items[q->front] = ele;
	if (q->rear == -1){
		q->rear = 0;
	}
	printf("%d Enqueued successfully at front\n", ele);
}

int delete_front(queue *q){
	if (q->front  == -1){
		printf("Underflow\n");
		return(NULL);
	}
	else{
		int x = q->items[q->front];
		if(q->front == q->rear){
			q->front = -1;
			q->rear = -1;
		}
		else if (q->front == MAX_SIZE - 1){
			q->front = 0;
		}
		else{
			q->front++;
		}
		return x;
	}
}

int delete_rear(queue *q){
	if (q->front  == -1){
		printf("Underflow\n");
		return(NULL);
	}
	else{
		int x = q->items[q->rear];
		if(q->front == q->rear){
			q->front = -1;
			q->rear = -1;
		}
		else if (q->rear == 0){
			q->rear = MAX_SIZE - 1;
		}
		else{
			q->rear--;
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
		i= (i+1) % MAX_SIZE;
	}
	printf("%d\n", q->items[i]);
}

int main(){
	queue q1;
	init(&q1);
	insert_rear(&q1, 10);
	insert_rear(&q1, 20);
	insert_rear(&q1, 30);
	insert_rear(&q1, 40);
	insert_rear(&q1, 50);
	display(&q1);
	printf("Dequeued %d from front successfully\n", delete_front(&q1));
	display(&q1);
	printf("Dequeued %d from front successfully\n", delete_front(&q1));
	display(&q1);
	printf("Enqueue\n");
	insert_front(&q1, 60);
	display(&q1);
	printf("Dequeued %d from front successfully\n", delete_front(&q1));
	display(&q1);
	printf("Dequeued %d from front successfully\n", delete_front(&q1));
	display(&q1);
	printf("Dequeued %d from rear successfully\n", delete_rear(&q1));
	display(&q1);
	printf("Dequeued %d from front successfully\n", delete_front(&q1));
	display(&q1);
	return 0;
}
