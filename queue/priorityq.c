// ascending priority queue
#include <stdio.h>

typedef struct queue{
	int data;
	int priority;
}queue;

void enqueue(queue *q, int ele, int pty, int *count){
	queue item;
	item.data = ele;
	item.priority = pty;
	int j = (*count) - 1;
	while(j >= 0 && q[j].priority > item.priority){
		q[j+1] = q[j];
		j--;
	}
	q[j+1] = item;
	(*count)++;
}

queue dequeue(queue *q, int *count){
	queue item;
	if((*count) == 0){
		printf("Queue Empty");
		item.data = 0;
		item.priority = -1;
		return(item);
	}
	else{
		item = q[0];
		printf("%d ", *count);
		for(int i = 0; i < (*count) - 1;i++){
			q[i-1] = q[i];
		}
		printf("%d\n", *count);
		(*count)--;
		return item;
	}
}

void display(queue *q, int *count){
	for(int i = 0; i <= (*count)-1; i++){
		printf("%d %d\n", q[i].data, q[i].priority);
	}
}

int main(){
	queue pq[10];
	int count = 0;
	enqueue(pq, 10, 2, &count);
	enqueue(pq, 20, 1, &count);
	enqueue(pq, 30, 3, &count);
	display(pq, &count);
	//printf("@%d", count); 
	queue x = dequeue(pq, &count);
	printf("deleted item is: %d\n", x.data);
	printf("%d\n", count);
	enqueue(pq, 20, 1, &count);
	
	display(pq, &count);	
	return 0;
}