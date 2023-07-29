#include<stdio.h>
#include<math.h>
float K(float,float,float,float);
float f(float,float,float);
main()
{
    int i,j,R,n;
    float h,a,b,l,pi,sum,x[10],y[10];
    printf("enter step length(h),lower limit(x[0]),number of step(n),roll(R),lamda(l) = ");
    scanf("%f %f %d %d %f",&h,&x[0],&n,&R,&l);
    a=1.5+(0.01*R);
    b=2.5+0.01*R;
    pi=4.*atan(1.);
    printf("\n The karnel matrix Kij is as follows:\n");
    printf("%f \n\n",K(x[0],x[0],a,pi));
    y[0]=f(x[0],b,pi);
    for(i=1;i<=n;i++)
    {        
        x[i]=x[i-1]+h;
        sum=l*h*0.5*K(x[i],x[0],a,pi)*y[0];
        if(i>1)
        for(j=1;j<i;j++)
        sum=sum+l*h*K(x[i],x[j],a,pi)*y[j];
        y[i]=(f(x[i],b,pi)+sum)/(1-h*l*K(x[i],x[i],a,pi)/2);
        for(j=0;j<=i;j++)
        printf("%f ",K(x[i],x[j],a,pi));
        printf("\n\n");
    }
        printf("\n printing f(x):\n\n");
    for(i=0;i<=n;i++)
    {
        printf(" %f\t",f(x[i],b,pi));
        
    }
    printf("\nThe approximate solution is as follows:\n\n");
    printf(" \nx[i]\ty[i]\n\n");
    for(i=0;i<=n;i++)
    printf("%f\t%f\n",x[i],y[i]);
}
    
float K(float x,float s,float a,float pi)
{
    return(1./(a+sin(pi*(x+s))));
}

float f(float x,float b,float pi)
{
    return(b-sin(pi*x));
}

