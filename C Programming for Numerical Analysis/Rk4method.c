#include<stdio.h>
#include<math.h>
#define pi 4*atan(1)
#define a 5
double f (double x, double y)
{return x*x+y*y+a*sin(pi*x*y);}
main()
{
    double x0,y0,x1,h,k1,k2,k3,k4,y1;
    printf("enter x0,y0,h,x1:");
    scanf("%lf%lf%lf%lf",&x0,&y0,&h,&x1);
    do
    {
        k1=h*f(x0,y0);
        k2=h*f(x0+(h/2),y0+(k1/2));
        k3=h*f(x0+(h/2),y0+(k2/2));
        k4=h*f(x0+h,y0+k3);
        y1=y0+((k1+2*k2+2*k3+k4)/6);
        printf("x=%l.8f k1=%l.8f k2=%l.8f k3=%l.8f k4=%l.8f y=%l.8f\n",x0+h,k1,k2,k3,k4,y1);
        x0=x0+h;
        y0=y1;}
    while(x0<x1);
    }