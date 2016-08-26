#include <stdio.h>

int main(){
	void makeTable(int, int, double (*fp)(int));
	double reciprocal(int);
	makeTable(1,10,reciprocal);
	return 0;
}

void makeTable(int first, int last, double (*fp)(int)){
	for(int i = first; i <= last; i++)
		printf("%d  %.3lf\n",i,(*fp)(i));
}

double reciprocal(int x){
	return 1.0 / x;
}