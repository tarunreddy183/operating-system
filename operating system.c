#include<stdio.h>
	// given three processes
	// contains the maximum sizes
	int maxa[3]={8,4,3};
	int maxb[3]={6,2,0};
	int maxc[3]={3,3,3};
	// resources available
	int avail[3]={3,3,2};
	// allocation of input
	int a[3],b[3],c[3];
	int needa[3],needb[3],needc[3];
	int i=0;
	int flag = 0;
	int main()
	{
		// taking input of allocation
		for(i=0;i<3;i++)
		{
			printf("\n Enter the allocation of process p0 : \n");
			scanf("%d",&a[i]);
		}
		for(i=0;i<3;i++)
		{
			printf("\n Enter the allocation of process p1 : \n");
			scanf("%d",&b[i]);
		}
		for(i=0;i<3;i++)
		{
			printf("\n Enter the allocation of process p2 : \n");
			scanf("%d",&c[i]);
		}
		// Generating the need
		for(i=0;i<3;i++)
		{
			// for process p0
			needa[i]=maxa[i]-a[i];
			// for process p1
			needb[i]=maxb[i]-b[i];
			// for process p2
			needc[i]=maxc[i]-c[i];
		}
		// printing the need
		for(i=0;i<3;i++)
		{
			printf("\n Need p0: %d",needa[i]);
			printf("\n Need p1: %d",needb[i]);
			printf("\n Need p2: %d",needc[i]);
		}
		// implementing logic
		// checking need < allocation for p0
		
		if(needa[i]<a[i]&&needa[i+1]<a[i+1]&&needa[i+2]<a[i+2])
		{
			printf("\n p0 running safely !! \n");
			avail[i]=avail[i]+a[i];
			flag=1;
		}
		else
		{
			printf("\n deadlock");
			flag=5;
		}
		// checking need < allocation for p1
		if (needb[i]<b[i]&&needb[i+1]<b[i+1]&&needb[i+2]<b[i+2])
		{
			printf("\n p1 running safely !! \n");
			avail[i]=avail[i]+b[i];
			flag=2;
		}
		else
		{
			printf("\n deadlock");
			flag=6;
		}
		// checking need < allocation for p2 
		if(needc[i]<c[i]&&needc[i+1]<c[i+2]&&needc[i+2]<c[i+2])
		{
			printf("\n p2 running safely !! \n");
			avail[i]=avail[i]+c[i];
			flag=3;
		}
		else
		{
			printf("\n deadlock");
			flag=7;
		}
		// checking safe state
		if(flag==1&&flag==2&&flag==3)
		{
			printf("\n The system is in safe state. \n");
		}
		if(flag==5)
		{
			printf("\n p0 is in deadlock.");
		}
		if(flag==6)
		{
			printf("\n p1 is in deadlock.");
		}
		if(flag==7)
		{
			printf("\n p2 is in deadlock.");
		}
	}

