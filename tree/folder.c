#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct File{
	char name[40];
	int kb;
	struct File *left;
	struct File *right;

} File;

//함수 원형
void made_tree(File *tree, char *in_name, int in_kb, File *lef, File *rig);
void preOrder_check(File *check, char *input, int *check_name, int *answer);
void preOrder_plus(File *check, int *answer);

//노드(트리)에 값을 넣어주는 함수
void made_tree(File *tree, char *in_name, int in_kb, File *lef, File *rig){
	strcpy(tree->name,in_name);
	tree->kb = in_kb;
	tree->left = lef;
	tree->right = rig;

}

//전위탐색을 통해 노드를 찾고 동시에 preOrder_plus함수를 수행하는 함수
void preOrder_check(File *check, char *input, int *check_name, int *answer) //전위(자신-왼-오)
{
	if(check!=NULL){
		if(strcmp(check->name,input)==0){
			*check_name = 1; //원하는 노드 찾았다!
			preOrder_plus(check,answer);
		}
		preOrder_check(check->left,input,check_name,answer);
		preOrder_check(check->right,input,check_name,answer);
	}
}

//해당 노드부터 시작해 전위탐색을 진행하며 총합크기를 구하는 함수
void preOrder_plus(File *check, int *answer){
	if(check!=NULL){
		*answer+=check->kb;
		preOrder_plus(check->left,answer);
		preOrder_plus(check->right,answer);
	}
}


int main(){
//사전준비 - 노드 생성 및 트리  연결
	File *root, *one, *two, *three, *four, *five, *six, *seven, *eight;
	root = (File *)calloc(1,sizeof(File));
	one = (File *)calloc(1,sizeof(File));
	two = (File *)calloc(1,sizeof(File));
	three = (File *)calloc(1,sizeof(File));
	four = (File *)calloc(1,sizeof(File));
	five = (File *)calloc(1,sizeof(File));
	six = (File *)calloc(1,sizeof(File));
	seven = (File *)calloc(1,sizeof(File));
	eight = (File *)calloc(1,sizeof(File));
	
	made_tree(root, "Document", 0, one, two);
	made_tree(one, "Music", 50, three, four);
	made_tree(two, "Picutre", 100, five, six);
	made_tree(three, "K-Pop", 200, NULL, NULL);
	made_tree(four, "Pop", 300, NULL, NULL);
	made_tree(five, "Photo", 200, seven, eight);
	made_tree(six, "Movie", 500, NULL, NULL);
	made_tree(seven, "2020", 1000, NULL, NULL);
	made_tree(eight, "2021", 50, NULL, NULL);

	char input[32];
	scanf("%s",input);
	int check_name = 0;
	int answer = 0;
	

	 
	preOrder_check(root,input,&check_name,&answer);
	if(check_name == 0)
		printf("없는 디렉토리명 입니다.\n");
	else{	
		printf("출력 : %d\n",answer);
	}
	



}
