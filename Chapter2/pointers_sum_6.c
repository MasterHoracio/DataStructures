#include <stdio.h>

int main(){
	void test(int *);

	int n = 14;
	printf("%d\n",n);
	test(&n);
	printf("%d\n",n);

	return 0;
}

void test(int *a){
	*a = *a + 6;
	printf("%d\n",*a);
}