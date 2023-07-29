#include<stdio.h>
#include<math.h>
double f (double x, double y)
{
return 5*x*cos(y)+0.007*y*y;
}
double g (double x, double y)
{
return y*sin(x) - 0.6*x*x;
}
main()
{
    double x0,y0,t0,t1,h,k1,k2,k3,k4,l1,l2,l3,l4,x1,y1;
    printf("enter x0,y0,to,h,t1:");
    scanf("%lf%lf%lf%lf%lf",&x0,&y0,&t0,&h,&t1);
    do
    {
        k1=h*f(x0,y0);
        l1=h*g(x0,y0);
        k2=h*f(x0+(l1/2),y0+(k1/2));
        l2=h*g(x0+(l1/2),y0+(k1/2));
        k3=h*f(x0+(l2/2),y0+(k2/2));
        l3=h*g(x0+(l2/2),y0+(k2/2));
        k4=h*f(x0+l3,y0+k3);
        l4=h*g(x0+l3,y0+k3);
        y1=y0+((k1+2*k2+2*k3+k4)/6);
        x1=x0+((l1+2*l2+2*l3+l4)/6);
        printf("t=%.8lf x=%.8lf y=%.8lf k1=%.8lf l1=%.8lf k2=%.8lf l2=%.8lf k3=%.8lf l3=%.8lf k4=%.8lf l4=%.8lf \n",t0,x0,y0,k1,l1,k2,l2,k3,l3,k4,l4);
        t0=t0+h;
        x0=x1;
		y0=y1;
		}
    while(t0<=t1);
    }

