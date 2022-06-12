#include<stdio.h>
int main()
{
	int a[10],i,b,j,loc,temp;
	for(i=0;i<=10;i++)
	{
		printf("Enter the element");
		scanf("%d",&a[i]);
	}
	for(i=0;i<=9;i++){
	
	loc=i;
	for(j=i+1;j<=10;j++)
	{
		if(a[j]<a[loc])
		loc=j;
	}
		temp=a[i];
		a[i]=a[loc];
		a[loc]=temp;
	}

for(i=0;i<=10;i++)
{

printf("%d\n",a[i]);
}
}


