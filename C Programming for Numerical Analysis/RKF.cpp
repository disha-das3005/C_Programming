//********rk45 method******//
#include<stdio.h>
#include<math.h>

double f(double x,double y)
{
    return(1-x*y);
}
main()
{
    double h,k1,k2,k3,k4,k5,k6,x,y ;
    int i;
    h=0.02;
    x=0;
    y=1;
    for(i=0;i<=6;i++)
    {  
         k1=h*f(x,y);
         k2=h*f(x+(h/4),y+(k1/4));  
         k3=h*f(x+((3*h)/8),y+((3*k1)/32)+((9*k2)/32));
         k4=h*f(x+((12*h)/13),y+((1932*k1)/2197)-((7200*k2)/2197)+((7296*k3)/2197));
         k5=h*f(x+h,y+((439*k1/216))-8*k2+((3680*k3/513))-((845*k4/4104)));
        k6=h*f(x+(h/2),y-((8*k1/27))+(2*k2)-((3544*k3/2565))+((1859*k4/4104))-((11*k5/40))); 
		       printf(" %0.8lf %0.8lf %0.8lf %0.8lf %0.8lf %0.8lf %0.8lf %0.8lf  \n\n",x,y,k1,k2,k3,k4,k5,k6);
         x=x+h;      y=y+25*k1/216+1408*k3/2565+2197*k4/4104-1*k5/5; 
		  
             }   
}                      
