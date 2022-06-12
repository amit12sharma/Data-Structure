#include<stdio.h>
int main()
{
	int a[10],i,b,j;
	for(i=0;i<=10;i++)
	{
		printf("Enter the element");
		scanf("%d",&a[i]);
	}
	for(i=1;i<=10;i++){
	
	b=a[i];
	j=i-1;
while(b<=a[j] && j>=0)
{
	a[j+1]=a[j];
	j=j-1;
	
}
a[j+1]=b;
}
for(i=0;i<=10;i++)
{

printf("%d\n",a[i]);
}
}

