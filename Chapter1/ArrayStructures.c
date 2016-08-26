#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	char name[20];
	int age;
	char gender;
}Student;

void getName(FILE *in, char str[]){
	char c, delimiter;
	int  n = 0;
	str[0] = '\0';

	while(isspace(c = getc(in)));
	if(c == EOF)
		return;
	delimiter = c;
	while( ((c = getc(in)) != delimiter) && (c != EOF) ){
		str[n++] = c;
	}
	str[n] = '\0';
}

char getGender(FILE * in){
	char c;
	while(isspace(c = getc(in)));
	return c;
}

int main(){
	FILE * in = fopen("input.txt","r");
	Student studnt[10];
	int n = 0;
	char tmp[20];


	getName(in,tmp);
	while(strcmp(tmp,"END") != 0){
		strcpy(studnt[n].name,tmp);
		fscanf(in,"%d",&studnt[n].age);
		studnt[n].gender = getGender(in);
		n++;
		getName(in,tmp);
	}

	for(int i = 0; i < n; i++)
		printf("%s %d %c\n",studnt[i].name,studnt[i].age,studnt[i].gender);

	return 0;
}