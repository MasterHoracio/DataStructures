#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef struct{
	char name[20];
	int age;
	char gender;
} Student;

int count = 0;

void getString(FILE *in, char str[]){
	char c, delimiter;
	int n = 0;
	str[0] = '\0';
	while(isspace(c = getc(in)));
	if(c == EOF)
		return;
	delimiter = c;
	while( ((c = getc(in)) != delimiter) && (c != EOF)){
		str[n++] = c;
	}
	str[n] = '\0';
}

char readChar(FILE *in){
	char c;
	while(isspace(c = getc(in)));
	return c;
}

void getData(FILE *in, Student student[]){
	char tmp[20];
	int n = 0;
	getString(in,tmp);
	while(strcmp(tmp,"END") != 0){
		strcpy(student[n].name,tmp);
		fscanf(in,"%d",&student[n].age);
		student[n].gender = readChar(in);
		n++;count++;
		getString(in,tmp);
	}
}

void sort(Student student[], int n){
	Student tmp;
	int k;
	for(int h = 1; h < n; h++){
		tmp = student[h];
		k = h - 1;
		while(k >= 0 && (tmp.age < student[k].age)){
			student[k + 1] = student[k];
			k -= 1;
		}
		student[k + 1] = tmp;
	}
}

int main(){
	Student student[10];
	FILE * in = fopen("input.txt","r");

	getData(in,student);

	for(int i = 0; i < count; i++)
		printf("%s %d %c\n",student[i].name,student[i].age,student[i].gender);

	sort(student,count);
	printf("\n\n");

	for(int i = 0; i < count; i++)
		printf("%s %d %c\n",student[i].name,student[i].age,student[i].gender);

	return 0;
}