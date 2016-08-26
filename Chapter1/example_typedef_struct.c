#include <stdio.h>

typedef struct{
	int day;
	char month[4];
	int year;
}date;

void printDate(date d){
	printf("date: %s %d, %d\n",d.month,d.day,d.year);
}

int main(){
	date dob;

	printf("Give me: (day, month, year)\n");
	scanf("%d %s %d",&dob.day,dob.month,&dob.year);

	printDate(dob);

	return 0;
}