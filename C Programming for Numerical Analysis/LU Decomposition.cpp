//Subrata Bera
#include<stdio.h>
#include<math.h>
main()
{
    double a[100][100],l[100][100],u[100][100],li[100][100],ui[100][100],h[100][100],ai[100][100],s1,s2;
    int n,i,j,k;
    printf(" Enter order of square matrix n = ");
    scanf("%d",&n);
    printf("\n");
    printf(" Enter the matrix row wise : \n\n");
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    {            
        scanf("%lf",&a[i][j]);        
        l[i][1]=a[i][1];
        u[i][i]=1;
        u[1][j]=a[1][j]/l[1][1];
        if(j>i)
        l[i][j]=0;
        if(i>j)
        u[i][j]=0;   
        if(i==j)
        h[i][j]=1;
        else 
        h[i][j]=0;
    }
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    {        
        if(i>=j)
        {
            l[i][j]=a[i][j];
            for(k=1;k<j;k++)
            {                            
                l[i][j]=l[i][j]-l[i][k]*u[k][j];            
            }
        }
        if(j>=i)
        {
            u[i][j]=a[i][j]/l[i][i];
            for(k=1;k<i;k++)
            {                            
                u[i][j]=u[i][j]-l[i][k]*u[k][j]/l[i][i];            
            }
        }
    }
    printf("\n The lower triangular matrix is :\n \n");
        for(i=1;i<=n;i++)
        {
           {
              for(j=1;j<=n;j++)
               printf("%.8lf  ",l[i][j]);                            
           }
           printf("\n");
        }
    printf("\n The upper triangular matrix is :\n \n");
        for(i=1;i<=n;i++)
        {
           {
              for(j=1;j<=n;j++)
               printf("%.8lf  ",u[i][j]);                            
           }
           printf("\n");
        }
    for (j=1;j<=n;j++)
       for (i=1;i<=n;i++)
       { 
          s1=0;
        
    
          for(k=1;k<=i-1;k++)
          s1=s1+li[k][j]*l[i][k];    
          li[i][j]=(h[i][j]-s1)/l[i][i];   
        }    
    for (j=1;j<=n;j++)
       for (i=n;i>=1;i--)
       { 
          s2=0;
          for(k=n;k>=i+1;k--)
          s2=s2+ui[k][j]*u[i][k];    
          ui[i][j]=(h[i][j]-s2)/u[i][i];   
        } 
       printf("\n The inverse of lower triangular matrix is :\n \n");
        for(i=1;i<=n;i++)
        {
           {
              for(j=1;j<=n;j++)
               printf("%.8lf  ",li[i][j]);                            
           }
           printf("\n");
        }
    printf("\n The inverse of upper triangular matrix is :\n \n");
        for(i=1;i<=n;i++)
        {
           {
              for(j=1;j<=n;j++)
               printf("%.8lf  ",ui[i][j]);                            
           }
           printf("\n");
        }
    printf("\n The required inverse of the given matrix is :\n \n");
    for(i=1;i<=n;i++)
    {
    for(j=1;j<=n;j++)
        {
        ai[i][j]=0;
        for(k=1;k<=n;k++)
        ai[i][j]=ai[i][j]+ui[i][k]*li[k][j];
        printf("%.8lf  ",ai[i][j]);
            }
        printf("\n");
        }
}          
