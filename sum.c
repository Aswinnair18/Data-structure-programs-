#include <stdio.h>
int main(){
	int num1,num2,sum;
	printf("Enter two Integers:");
	scanf("%d %d",&num1,&num2);
	sum=num1+num2;
	printf("Sum of %d and %d=%d \n",num1,num2,sum);
	return 0;
}