#include <stdio.h>
#include <ctype.h>

#define MAX 100

typedef struct{
	char ch;
}StackData;

#include "stack.h"

int precedence(char);
char getToken();
int readConvert(char[]);
void printPostfix(char[], int);

int main(){
	char postfix[MAX];

	int n = readConvert(postfix);
	printPostfix(postfix, n);

	return 0;
}

int readConvert(char postfix[]){
	Stack S = initStack();
	StackData temp;
	char token, c;
	int h = 0;

	printf("Ingrese una operacion: ");
	token = getToken();

	while(token != '\n'){
		if(isdigit(token)){
			postfix[h++] = token;
		}else if(token ==  '('){
			temp.ch = token;
			push(S, temp);
		}else if(token == ')'){
			while( (c = pop(S).ch) != '(')
				postfix[h++] = c;
		}else{
			while(!empty(S) && (precedence(peek(S).ch) >= precedence(token)))
				postfix[h++] = pop(S).ch;
			temp.ch = token;
			push(S,temp);
		}
		token = getToken();
	}
	while(!empty(S))
		postfix[h++] = pop(S).ch;
	return h;
}

void printPostfix(char postfix[], int h){
	printf("Postfijo de operacion: ");
	int i;
	for(i = 0; i < h; i++)
		printf("%c ",postfix[i]);
	printf("\n");
}

int precedence(char c){
	if(c == '(')
		return 0;
	else if(c == '+' || c == '-')
		return 3;
	else
		return 5;
}

char getToken(){
	char c;
	while( (c = getchar()) == ' ');
	return c;
}