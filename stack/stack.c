#include <stdio.h>
#define MAX_SIZE 1000
#define TRUE 1
#define FALSE 0
typedef struct stack{
	int data[MAX_SIZE];
	int top;
} stack;

stack st;

void init(){
	st.top = 0;
}

int is_empty(){
	if(st.top!=0)
		return FALSE;
	else
		return TRUE;
}

int is_full(){
	if(st.top!=MAX_SIZE)
		return FALSE;
	else
		return TRUE;
}

int size(){
	return st.top;
}

int push(int x){ //top 값은 data 넣은 후 다음 빈 공간을 가리킨다.
	if(is_full())
		return -1;
	else{
		st.data[st.top++] = x; //값 넣고 천장 +1
	}
}

int pop(){
	if(is_empty())
		return -1;
	else{
		return st.data[--st.top]; //최대 천장 값 (top은 암것도 X니 -1)
	}
}

int peek(){
	return st.data[st.top-1];
}

int main(){
	
	init();
	for(int i=1; i<=10; i++)
		push(i);
	
	printf("peek : %d\n",peek());

	for(int i=0; i<10; i++){
		printf("pop : %d\n",pop());
	}


	return 0;
}
