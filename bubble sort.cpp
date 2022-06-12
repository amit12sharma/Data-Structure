#include<stdio.h>
int main()
{
	int a[10],i,j,Temp;
	for(i=0;i<10;i++)
	{
		printf("Enter the element");
		scanf("%d",&a[i]);
	}
	for(i=0;i<10;i++)
	{
	
	for(j=0;j<10-i;j++)

	if(a[j]>a[j+1])
	{
		Temp=a[j];
		a[j]=a[j+1];
		a[j+1]=Temp;
		
	}    
}
for(i=0;i<10;i++)
printf("%d\n",a[i]);
}

