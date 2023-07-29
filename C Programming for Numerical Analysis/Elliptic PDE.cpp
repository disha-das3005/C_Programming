#include<stdio.h>
		#include<math.h>
		main()
		{
		int i,j,k,r;
		float sum,m,u[20][20],a[20][20],x[10];
		printf("Enter roll(r) = ");
		scanf("%d",&r);
		u[0][1]=0;
		u[0][2]=0;
		u[1][0]=0.20+0.001*r; 
		u[1][3]=0.20+0.001*r; 
		u[2][0]=0.40+0.001*r; 
		u[2][3]=0.40+0.001*r; 
		u[3][1]=0.75; 
		u[3][2]=0.75;
		for(i=0;i<=3;i++)
		for(j=0;j<=3;j++)
		{
		    if(i==j)
		    a[i][j]=4;
		    else if(i+j==3)
		    a[i][j]=0;
		    else
		    a[i][j]=-1;
		}
	    a[0][4]=u[0][1]+u[1][0];
	    a[1][4]=u[2][0]+u[3][1];
	    a[2][4]=u[0][2]+u[1][3];
	    a[3][4]=u[2][3]+u[3][2];
		printf("\nThe augmented matrix be:\n\n");
		for(i=0;i<=3;i++)
		{ 
	    	for(j=0;j<=4;j++)
	    	printf("%f  ",a[i][j]);
	    	printf("\n");
		} 
		printf("\nThe Gauss elimination table is :\n\n");
		for(i=0;i<3;i++)
		{
			for(k=i+1;k<=3;k++)
			{
				m=a[k][i]/a[i][i];
				for(j=i+1;j<=4;j++)
				{
					a[k][j]=a[k][j]-m*a[i][j];
				    printf("%f  ",a[k][j]);
				}
			    printf("\n");	
			}
			printf("\n");
		}
		for(i=3;i>=0;i--)
		{
			sum=0;
			for(j=i+1;j<=3;j++)
			sum =sum+a[i][j]*x[j];
			x[i]=(a[i][4]-sum)/a[i][i];
		}		
		printf("The required values are:\n\n");
		for(i=0;i<4;i++)
		{
		printf("%f  ",x[i]);
		}
		}	

