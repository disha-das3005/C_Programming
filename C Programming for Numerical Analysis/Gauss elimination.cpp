//Subrata Bera
#include<stdio.h>
#include<math.h>
main()
{
    double m,sum,x[100][100],y[100][100];
    int n,i,j,k;
    printf("Enter order of square matrix n = ");
    scanf("%d",&n);
    printf("\n");
    printf("Enter the matrix row wise : \n\n");
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    {            
        scanf("%lf",&x[i][j]);        
        if(i==j)
        x[i][n+j]=1;
        else
        x[i][n+j]=0;
    }    
    printf("\nThe augmented matrix are :\n\n");
    for(i=1;i<=n;i++)
    {
    	for(j=1;j<=2*n;j++)
    	{
    		printf("%0.8lf  ",x[i][j]);
		}
        printf("\n");
	}    
    printf("\nTables for Gauss elimination are :\n\n");
    for(i=1;i<n;i++)
	{
		for(k=i+1;k<=n;k++)
		{
			m=x[k][i]/x[i][i];
			for(j=i+1;j<=2*n;j++)
			{
				x[k][j]=x[k][j]-m*x[i][j];
			    printf("%0.8lf  ",x[k][j]);
			}
		    printf("\n");	
		}
		printf("\n");
	}    
    for (j=1;j<=n;j++)
    for (i=n;i>=1;i--)
    { 
        sum=0;
        for(k=n;k>=i+1;k--)
        sum=sum+y[k][j]*x[i][k];    
        y[i][j]=(x[i][j+n]-sum)/x[i][i];   
    }     
    printf("The inverse of the given matrix is :\n \n");
        for(i=1;i<=n;i++)
        {
           {
              for(j=1;j<=n;j++)
               printf("%0.6lf  ",y[i][j]);                            
           }
           printf("\n");
        }
}
