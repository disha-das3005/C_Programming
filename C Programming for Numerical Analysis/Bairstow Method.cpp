#include<stdio.h>
#include<math.h>
main()
{
int i,n;
float a[100],b[100],c[100],r,s,delr,dels;
printf("Enter the degree of polynomial\n");
scanf("%d",&n);
printf("Enter the coefficients\n");
for(i=0;i<=n;i++)
{
scanf("%f",&a[i]);
}
r=-a[1]/a[0];
s=-a[2]/a[0];
do
{
b[0]=a[0];
b[1]=a[1]+r*b[0];
for(i=2;i<=n;i++)
{
b[i]=a[i]+r*b[i-1]+s*b[i-2];
}
c[0]=b[0];
c[1]=b[1]+r*c[0];
for(i=2;i<=n;i++)
{
c[i]=b[i]+r*c[i-1]+s*c[i-2];
}
delr=(b[n]*c[n-3]-b[n-1]*c[n-2])/(c[n-2]*c[n-2]-c[n-1]*c[n-3]);
dels=(b[n-1]*c[n-1]-b[n]*c[n-2])/(c[n-2]*c[n-2]-c[n-1]*c[n-3]);
r=r+delr;
s=s+dels;
}
while(fabs(delr)>0.000001 && fabs(dels)>0.000001);
printf("the factors are\n");
printf("x^2-(%9.5f)x-(%9.5f)\n",r,s);
printf("x^2+(%9.5f)x+(%9.5f)\n",b[1],b[2]);
}



