#include <stdio.h>

int main(){
	void print(void *, int);

	int n = 375;
	float d = 2.718;

	print(&n,1);
	print(&d,2);

	return 0;
}

void print(void *p, int t){
	if(t == 1)
		printf("%d\n",*(int *)p);
	else if(t == 2)
		printf("%.3f\n",*(float *)p);
	else
		printf("error: unknown type\n");
}