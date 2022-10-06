#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *link;
}node;

typedef struct queue{
	node *front;
	node *rear;
}queue;

void init(queue *q){
	q->front = NULL;
	q->rear = NULL;
}

node *getnode(int ele){
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = ele;
	temp->link = NULL;
	return temp;
}

void enqueue(queue *q, int ele){
	struct node *newnode = getnode(ele), *temp = q->front;
	if(q->rear == NULL){
		q->front = newnode;
	}
	else{
		q->rear->link = newnode;
	}
	q->rear = newnode;
	printf("Enqueued %d successfully\n", ele);
}

int dequeue(queue *q){
	if (q->front  == NULL){
		printf("Underflow\n");
		return(NULL);
	}
	else{
		node *temp = q->front;
		int x = temp->data;
		q->front = temp->link;
		free(temp);
		return(x);
	}
}

int peep(queue *q){
	if (q->front  == NULL){
		printf("Underflow\n");
		return(NULL);
	}
	else{
		return (q->front->data);
	}
}

void display(queue *q){
	node *temp = q->front;
	printf("Queue:\n");
	while(temp != NULL){
		printf("%d\n", temp->data);
		temp = temp->link;
	}
}

int main(){
	queue q1;
	init(&q1);
	enqueue(&q1, 10);
	enqueue(&q1, 20);
	enqueue(&q1, 30);
	enqueue(&q1, 40);
	display(&q1);
	printf("Dequeued %d\n", dequeue(&q1));
	display(&q1);
	return 0;
}