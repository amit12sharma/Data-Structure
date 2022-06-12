#include<stdio.h>
void enter_data(int a[3][3],int x ,int y)
{
	int i,k;
	for(i=0;i<x;i++)
	{
		for(k=0;k<y;k++)
		{
			printf("Enter the data");
			scanf("%d",&a[i][k]);
		}
	}
}
void spare(int a[3][3],int x,int y)
{
	int i,k,count=0;
	for(i = 0; i < x; i++){
      for(k = 0; k < y; k++){
         if(a[i][k] == 0)
            count++;
      }
   }
   if(count > ((x * y)/2))
      printf("Matrix is a sparse matrix \n");
   else
      printf("Matrix is not sparse matrix\n");
}

int main()
{
	int y[3][3];
	enter_data(y,3,3);
	 spare(y,3,3);
}
