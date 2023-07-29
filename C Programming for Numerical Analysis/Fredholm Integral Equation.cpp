#include<stdio.h>
#include<math.h>
float kar(float,float,float);
float f(float,float);
int main()
{
    int i,j,R,n,p;
    float h,m,a,l,sum,x[10],s[10],k[10][10],y[10],t[10][10],w[10];
    printf("\nenter step length(h),lower limit(x[0]),number of step(n),roll(R),lamda(l) = ");
    scanf("%f %f %d %d %f",&h,&x[0],&n,&R,&l);
    a=1+(0.01*R);
    for(i=0;i<=n;i++)
    {
        s[i]=x[i]=x[0]+i*h;
    }
    printf("\n The karnel matrix Kij is as follows:\n\n");
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            k[i][j]=kar(x[i],s[j],a);
            printf(" %f\t",k[i][j]);
        }
         printf("\n");
    }
    w[0]=w[n]=h/3.0;
    for(i=1;i<n;i++)
    {
        if(i%2==0)
        w[i]=2.0*h/3.0;
        else
        w[i]=4.0*h/3.0;
    }
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(i!=j)
            {
                t[i][j]=-l*w[j]*k[i][j];
            }
            else
            {
                t[i][j]=1.0-l*w[j]*k[i][j];
            }
        }
    }
      printf("\n printing f(x):\n\n");
    for(i=0;i<=n;i++)
    {
        t[i][n+1]=f(x[i],a);
        printf(" %f\t",t[i][n+1]);
        
    }
   printf("\n\n The augmented matrix is as follows:\n\n");
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n+1;j++)
        {
            printf(" %f\t",t[i][j]);
        }
        printf("\n");
    }
      printf("\n\n The Gauss elimination table is as follows:\n\n");
   for(i=0;i<n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            m=t[j][i]/t[i][i];
            for(p=i+1;p<=n+1;p++)
            {
            	t[j][p]-=m*t[i][p];
            	printf(" %f\t",t[j][p]);
			}
             printf("\n");
        }
         printf("\n\n");
    }
    for(i=n;i>=0;i--)
    {
        sum=0.0;
        for(j=i+1;j<=n;j++)
        sum+=t[i][j]*y[j];
        y[i]=(t[i][n+1]-sum)/t[i][i];
    }
    printf("The approximate solution is as follows:\n\n");
    for(i=0;i<=n;i++)
        printf("y[%.1f]=%.4f\n",x[i],y[i]);
        printf("\t\t(correct upto 4D)");

}

float kar(float x,float s,float a)
{
    return((a+x+s)/(1.5+x*x+s*s));
}

float f(float x,float a)
{
    return(2+x+2*x*x+x*x*x);
}



