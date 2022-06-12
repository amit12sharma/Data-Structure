#include<stdio.h>
int main()
{
	int a[10],i,search;
	for(i=0;i<10;i++)
	{
		printf("Enter the element");
		scanf("%d",&a[i]);
	}
	printf("enter the search element");
	scanf("%d",&search);
	
	while(a[i]!=search)
	{
		i++;
		break;
}
for(i=0;i<10;i++)
		if(a[i]==search)
	{
	printf("%d",i);
}

	}
