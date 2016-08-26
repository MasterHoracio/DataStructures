#include <stdio.h>

int main(){
	void test(int val[], int max);
	int list[5];

	for(int i = 0; i < 5; i++)
		list[i] = i;
	test(list,5);

	for(int i = 0; i < 5; i++)
		printf("%d ",list[i]);
	printf("\n"); 

	return 0;
}

void test(int val[], int max){
	for(int i = 0; i < max; i++)
		val[i] += 25;
}