#include <stdio.h>

#define MAX 25

int main(){
	int length_matrix(char string[]);
	int length_pointer(char *string);

	char name[MAX];
	printf("give me your name: ");
	gets(name);

	printf("length: %d\n",length_matrix(name));
	printf("length: %d\n",length_pointer(name));
	return 0;
}

int length_matrix(char string[]){
	int n = 0;
	while(string[n] != '\0')
		n++;
	return n;
}

int length_pointer(char *string){
	int n = 0;
	while(*string++ != '\0'){
		n++;
	}
	return n;
}