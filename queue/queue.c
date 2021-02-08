#include <stdio.h>

#define MAX_QUEUE_SIZE 100

int data[MAX_QUEUE_SIZE];
int front; //맨 처음값 -1 위치
int rear; //맨 끝값위치

void init_queue() {front = rear = 1; }
int is_empty() {return front==rear; }
int is_full() {return (rear+1)%MAX_QUEUE_SIZE==front; }
int size() {return (rear-front+MAX_QUEUE_SIZE)%MAX_QUEUE_SIZE; }

void enqueue(int x){
	rear = (rear+1)%MAX_QUEUE_SIZE;
	//printf("rear값 : %d\n",rear);
	data[rear] = x;

}

int dequeue(){
	front = (front+1)%MAX_QUEUE_SIZE; //front는 맨앞 값의 이전을 가리킴
	//printf("front값 : %d\n",front);
	return data[front]; //즉 +1 때리고 값을 리턴해주는 것이다?

}


int main(){

	init_queue(); //data[1] 자리는 항상 공백으로 둔다?

	/*	for(int i=1; i < 10; i++)
		enqueue(i);
		printf("선형큐 enqueue 9회\n"); 

		printf("front: %d rear: %d\n",front,rear);

		printf("\tdequeue() --> %d\n", dequeue()); 
		printf("\tdequeue() --> %d\n", dequeue()); 
		printf("\tdequeue() --> %d\n", dequeue()); 
		printf("선형큐 dequeue 3회\n");
	 */

	for(int i=1; i < 100; i++){
		enqueue(i);
		enqueue(i);
		printf("[%d]dequeue() --> %d\n", i, dequeue());
		printf("[%d]dequeue() --> %d\n", i, dequeue());
	}


	return 0;
}
