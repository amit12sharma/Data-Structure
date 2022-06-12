#include<stdio.h>
int main()
{
	int a[10],i,item,BEG,END,MID;
	for(i=0;i<=10;i++)
	{
		printf("Enter the element");
		scanf("%d",&a[i]);
	}
	BEG=0;
	END=9;
	printf("enter the search element");
	scanf("%d",&item);
	
	
	while(BEG<=END)
	{
	MID=(BEG+END)/2;

     if(item==a[MID])
     {
        printf("%d",MID);
        break;
     }
     
else if (item<a[MID])
	 {
	END=MID-1;
	 }
	 
	 else{
	 
	BEG=MID+1;
 }
}
 
}

