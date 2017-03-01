#include <stdio.h>
#include <ctype.h>

typedef struct{
	char ch;
	int num;
}StackData;

#include "stack.h"

int readConvert(char[]);
void printPostfix(char[], int);
char getToken(void);
int precedence(char);
int evalPostfix(char[], int);

int main(){
	char post[50];

	int n = readConvert(post);
	printPostfix(post, n);

	printf("Resultado = %d\n",evalPostfix(post,n));

	return 0;
}

char getToken(){
	char ch;
	while( (ch = getchar()) == ' ');
	return ch;
}

int precedence(char ch){
	if(ch == '(')
		return 0;
	if(ch == '+' || ch == '-')
		return 3;
	if(ch == '*' || ch == '/')
		return 5;
	return 8;
}

void printPostfix(char post[], int n){
	int i;
	for(i = 0; i < n; i++)
		printf("%c ",post[i]);
	printf("\n");
}

int readConvert(char pos[]){
	StackData temp;
	char token, c;
	int n = 0;

	Stack S = initStack();

	printf("Escriba una operacion: ");
	token = getToken();

	while(token != '\n'){
		if(isdigit(token))
			pos[n++] = token;
		else if(token == '('){
			temp.ch = token;
			push(S,temp);
		}else if(token == ')'){
			while( (c = pop(S).ch) != '(')
				pos[n++] = c;
		}else{
			while(!empty(S) && precedence(peek(S).ch) >= precedence(token))
				pos[n++] = pop(S).ch;
			temp.ch = token;
			push(S,temp);
		}
		token = getToken();
	}
	while(!empty(S))
		pos[n++] = pop(S).ch;

	return n;
}

int evalPostfix(char post[], int n){
	int a, b, c, i;
	StackData temp;
	Stack S = initStack();

	for(i = 0; i < n; i++){
		if(isdigit(post[i])){
			temp.num = post[i] - '0';
			push(S, temp);
		}else{
			b = pop(S).num;
			a = pop(S).num;

			if(post[i] == '+')
				c = a + b;
			else if(post[i] == '-')
				c = a - b;
			else if(post[i] == '*')
				c = a * b;
			else
				c = a / b;
			temp.num = c;
			push(S, temp);
		}
	}
	return pop(S).num;
}