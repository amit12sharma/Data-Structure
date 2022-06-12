#include<stdio.h>
int main()
{
	int a[10],i,BEG,END,MID,lbindex,rbindex,tbindex,temp[10];
	for(i=0;i<10;i++)
	{
		printf("Enter the element");
		scanf("%d",&a[i]);
	}
	BEG=0;
	END=9;
	MID=(BEG+END)/2;

lbindex=BEG;
rbindex=MID+1;
tbindex=BEG;
while((lbindex<=MID) && (rbindex<=END) )
{
	if(a[lbindex]<a[rbindex])
	{
	
	temp[tbindex]=a[lbindex];
	lbindex=lbindex+1;
}
else{
	temp[tbindex]=a[rbindex];
	rbindex=rbindex+1;
	
}
tbindex=tbindex+1;
}
while(lbindex<=MID)
{
	temp[tbindex]=a[lbindex];
	lbindex=lbindex+1;
	tbindex=tbindex+1;
}
while(rbindex<=END)
{
	temp[tbindex]=a[rbindex];
	rbindex=rbindex+1;
	tbindex=tbindex+1;
}
for(i=BEG;i<=END;i++)
{
	a[i]=temp[i];
}
for(i=0;i<10;i++)
	{
		printf("%d\n",a[i]);
		
	}
}
