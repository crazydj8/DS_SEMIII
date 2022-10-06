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

void enqueue(queue *q, int ele){
	if ((q->rear + 1) % MAX_SIZE == q->front){
		printf("Overflow\n");
		return;
	}
	q->rear = (q->rear + 1) % MAX_SIZE;
	q->items[q->rear] = ele;
	if (q->front == -1){
		q->front = 0;
	}
	printf("%d Enqueued successfully\n", ele);
}

int dequeue(queue *q){
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
		else{
			q->front = (q->front + 1) % MAX_SIZE;
		}
		return x;
	}
}

void display(queue *q){
	int i = q->front, j = q->rear;
	if (i == -1 && j == -1){
		printf("Queue Empty\n");
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
	enqueue(&q1, 10);
	enqueue(&q1, 20);
	enqueue(&q1, 30);
	enqueue(&q1, 40);
	enqueue(&q1, 50);
	display(&q1);
	printf("Dequeued %d successfully\n", dequeue(&q1));
	display(&q1);
	printf("Dequeued %d successfully\n", dequeue(&q1));
	display(&q1);
	printf("Enqueue\n");
	enqueue(&q1, 60);
	display(&q1);
	printf("Dequeued %d successfully\n", dequeue(&q1));
	display(&q1);
	printf("Dequeued %d successfully\n", dequeue(&q1));
	display(&q1);
	printf("Dequeued %d successfully\n", dequeue(&q1));
	display(&q1);
	printf("Dequeued %d successfully\n", dequeue(&q1));
	display(&q1);
	printf("Dequeued %d successfully\n", dequeue(&q1));
	display(&q1);
	
	return 0;
}
