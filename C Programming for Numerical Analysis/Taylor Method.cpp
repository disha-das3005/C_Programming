#include<stdio.h>
#include<math.h>		
main()
{
				int i=0,n;
				double x,y,y1,y2,y3,y4,f,fx,fxx,fxxx,fy,fyy,fyyy,fxxy,fxyy,fxy,h;
   double pi=4*atan(1);
				printf("\n Enter The Value Of x(0) : ");
				scanf("%lf",&x);
				printf("\n Enter The Value Of y(0) : ");
				scanf("%lf",&y);
				printf("\n Enter The Value Of n : ");
				scanf("%d",&n);
			 printf("\n Enter The Value Of h : ");
				scanf("%lf",&h);
				printf("\n\n n  x\ty\ty1\ty2\ty3\ty4\n\n");
    do
    {
    f=x*x+y*6;
    fx=2*x;
    fy=6;
    fxx=2;
    fyy=0;
    fxy=0;
    fxxx=0;
    fyyy=-0;
    fxxy=0;
    fxyy=0;
    y1=f;
    y2=fx+f*fy;
    y3=fxx+2*f*fxy+fyy*f*f+fx*fy+f*fy*fy;
    y4=fxxx+3*f*fxxy+3*f*f*fxyy+f*f*f*fyyy+4*f*f*fy*fyy+f*fy*fy*fy+3*f*fx*fyy+5*f*fy*fxy+fx*fy*fy+3*fx*fxy+fxx*fy;
        printf(" %d)  %0.8lf  %0.8lf  %0.8lf  %0.8lf %0.8lf %0.8lf\n\n",i,x,y,y1,y2,y3,y4);
        x=x+h;
        y=y+h*y1+(h*h*y2)/2+(h*h*h*y3)/6+(h*h*h*h*y4)/24;               
        i++;
    }		
    while(i<=n)	;
} 		
