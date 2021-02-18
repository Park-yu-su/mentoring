#include <stdio.h>

int visit[20] = {0};


void check(int n){
	visit[n] = 1;
	check(n+2);
}

int main(){
	int i=1;
	check(i);
	for(int j=0; j<20; j++)
		printf("visit의 %d번째 값 : %d\n",j,visit[j]);


	return 0;
}
