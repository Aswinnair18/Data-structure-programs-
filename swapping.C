#include<stdio.h>
int main()
{
	int a,b,t;
	printf("enter a&b");
	scanf("%d,%d",&a,&b);
	printf("before swapping a=%d,b=%d\n",a,b);
	t=a;
	a=b;
	b=t;
	printf("after swapping a=%d,b=%d",a,b);
	return 0;
}
