#include <stdio.h>

char arr[100] = {0, 'A', 'B', 'C', 'D', 'E', 'F'};

void inOrder(char x, int pos) //중위 왼-자신-오
{
	if(x!='\0'){
		inOrder(arr[pos*2],pos*2);
		printf("[%c] ",x);
		inOrder(arr[pos*2+1],pos*2+1);
	}
}

void preOrder(char x, int pos) //전위 자신-왼-오
{
	if(x!='\0'){
		printf("[%c] ",x);
		preOrder(arr[pos*2],pos*2);
		preOrder(arr[pos*2+1],pos*2+1);
	}
}

void postOrder(char x, int pos) //후위 왼-오-자신
{
	if(x!='\0'){
		postOrder(arr[pos*2],pos*2);
		postOrder(arr[pos*2+1],pos*2+1);
		printf("[%c] ",x);
	}
}

int main()
{
/*	
	if(arr[20]=='\0')
		printf("NULL check\n");
*/
	// 중위 순회
	printf("중위 순회 : ");
	inOrder(arr[1], 1);
	printf("\n");
	// 전위 순회
	printf("전위 순회 : ");
	preOrder(arr[1], 1);
	printf("\n");
	// 후위 순회
	printf("후위 순회 : ");
	postOrder(arr[1], 1);
	printf("\n");
	return 0;

}

