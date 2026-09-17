#include <stdio.h>
int main()
{
	int arr1[50],arr2[50],size1,size2;
	int merge [100];
	int i,j,k;
	printf("enter array1 size:""");
	scanf("%d",&size1);
	printf("Enter array1 elements in sorted order:\n");
	for(i=0;i<size1;i++)
	{
		scanf("%d",&arr1[i]);
		
	}
	printf("Enter array2 size:");
	scanf("%d",&size2);
	printf("Enter array2 elements in sorted order:\n");
	for(i=0;i<size2;i++)
	{
		scanf("%d",&arr2[i]);
	}
	i=0;
	j=0;
	k=0;
	while(i<size1&&j<size2)
	{
		if(arr1[i]<arr2[j])
		{
			merge[k]=arr1[i];
			i++;
		}
		else
		{
			merge[k]=arr2[j];
			j++;
		}
		k++;
	}
	while(i<size1)
	{
		merge[k]=arr1[i];
		i++;
		k++;
	}
	while(j<size2)
	{
		merge[k]=arr2[j];
		j++;
		k++;
	}
	printf("\n The new array after merging is : \n");
	for(i=0;i<k;i++)
	{
	printf("%d",merge[i]);
		
	}
	return 0;
	}
   
