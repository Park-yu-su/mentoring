#include <stdio.h>

#define MAX_QUEUE_SIZE 200
int data[MAX_QUEUE_SIZE][3]; //좌표 넣을 큐 (x좌표,y좌표,깊이)
int front; 
int rear;

void init_queue() {front = rear = 1; }
int is_empty() {return front==rear; }
int is_full() {return (rear+1)%MAX_QUEUE_SIZE==front; }
int size() {return (rear-front+MAX_QUEUE_SIZE)%MAX_QUEUE_SIZE; }

void enqueue(int x, int y, int dep){
	rear = (rear+1)%MAX_QUEUE_SIZE;
	data[rear][0] = x;
	data[rear][1] = y;
	data[rear][2] = dep;

}

int *dequeue(){
	front = (front+1)%MAX_QUEUE_SIZE; 
	return data[front]; 

}

int main(){  //미로의 x,y좌표와 list에 들어간 x,y좌표는 반대로 되어있다!
	init_queue();
	int go_x,go_y;

	scanf("%d %d",&go_x,&go_y);
	int miro[150][150] = {0};
	int went_miro[150][150] = {0}; //이미 간 곳을 다시 가지 않도록
	char ex[110]; //scanf 미로 받을 때
	for(int i=1; i<=go_x; i++){
		scanf("%s",ex);
		for(int j=0; j<go_y; j++){
			miro[i][j+1] = ex[j] - '0'; //문자열을 정수 아스키코드로
			went_miro[i][j+1] = ex[j] - '0';
		}
	}
	enqueue(1,1,1);
	while(is_empty()==0){
		int *check = dequeue();

	//	printf("꺼낸 좌표: %d %d\n",check[0],check[1]);
		if(check[0]==go_y && check[1]==go_x){ //꺼낸 좌표가 정답인 경우[입력된거 반대로] - 뒤늦게 알아 변수 변경 실패
			printf("%d\n",check[2]);
			break;
		}
		went_miro[check[1]][check[0]] = 0; //이미 간 길은 0으로 막기


		if(miro[check[1]-1][check[0]]==1 && went_miro[check[1]-1][check[0]]==1){ //위
			went_miro[check[1]-1][check[0]] = 0;
			enqueue(check[0],check[1]-1,check[2]+1);
//			printf("위: %d %d %d\n",check[0],check[1]-1,check[2]+1);
		}
		if(miro[check[1]+1][check[0]]==1 && went_miro[check[1]+1][check[0]]==1){ //아래
			went_miro[check[1]+1][check[0]] = 0;
			enqueue(check[0],check[1]+1,check[2]+1);
//			printf("아래: %d %d %d\n",check[0],check[1]+1,check[2]+1);
		}
		if(miro[check[1]][check[0]+1]==1 && went_miro[check[1]][check[0]+1]==1){ //오른쪽
			went_miro[check[1]][check[0]+1] = 0;
			enqueue(check[0]+1,check[1],check[2]+1);
//			printf("오른쪽: %d %d %d\n",check[0]+1,check[1],check[2]+1);
		}
		if(miro[check[1]][check[0]-1]==1 && went_miro[check[1]][check[0]-1]==1){ //왼쪽
			went_miro[check[1]][check[0]-1] = 0;
			enqueue(check[0]-1,check[1],check[2]+1);
//			printf("왼쪽: %d %d %d\n",check[0]-1,check[1],check[2]+1);
		}
	}


	/* 미로 프린팅
	   printf("\n");
	   for(int i=1; i<=go_x; i++){
	   for(int j=1; j<=go_y; j++){
	   printf("%d",went_miro[i][j]);
	   }
	   printf("\n");
	   }
	 */


	return 0;
}
