#include <stdio.h>
#include <string.h>

int main(){
	char stack[1000];
	char input[1000];
	int top = 0;
	int correct_check = 1;

	scanf("%[^\n]",input);
	for(int i=0; i<strlen(input);i++){
		if(input[i]=='['){
			stack[top++] = '[';
	//		printf("in[\n");
		}
		else if(input[i]=='{'){
			stack[top++] = '{';
	//		printf("in{\n");
		}
		else if(input[i]=='('){
			stack[top++] = '(';
	//		printf("in(\n");
		}

		else if(input[i] == ']'){
	//		printf("in]\n");
			if(stack[--top] != '['){
				correct_check = 0;
				break;
			}
		}
		else if(input[i] == '}'){
	//		printf("in}\n");
			if(stack[--top] != '{'){
				correct_check = 0;
				break;
			}
		}
		else if(input[i]== ')'){
	//		printf("in)\n");
			if(stack[--top] != '('){
				correct_check = 0;
				break;
			}
				
		}
	}
	if(top!=0)
		correct_check = 0;
	printf("top : %d\n",top);
	if(correct_check == 1)
		printf("옳은 가로입니다.\n");
	else
		printf("옳지 않은 가로입니다.\n");



	return 0;
}
