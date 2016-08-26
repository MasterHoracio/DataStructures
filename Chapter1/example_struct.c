#include <stdio.h>

struct date{
	int day;
	int month;
	int year;
};

void printDate(struct date d){
	printf("%d / %d / %d\n",d.day,d.month,d.year);
}

int main(){
	struct date dob;

	dob.day = 25;
	dob.month = 8;
	dob.year = 1993;

	printDate(dob);
	
	return 0;
}