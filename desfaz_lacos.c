#include<stdio.h>
#define MAX 100000
int main()
{
	int a[MAX], b[MAX], c[MAX];
	for (unsigned int i=0; i < MAX; i++) {
		a[i] = b[i] + c[i];
	}
	return 1;
}
