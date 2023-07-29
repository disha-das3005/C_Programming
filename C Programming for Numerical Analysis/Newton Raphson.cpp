//Subrata Bera
#include<math.h>
#include<stdio.h>
main()
{
    double R,f,g,fx,fy,gx,gy,x,y,h,k;
    int n=0;
    printf("Enter roll(R),initial value(x),y(x) = ");
    scanf("%8lf%8lf%8lf",&R,&x,&y);
    if(R>10)
    R=R/10;
    printf("\nn  x  y  f  fx  fy  g  gx  gy  h  k\n");
    do
    {
        f=4*x*x-y*y*y+28;
        fx=8*x;
        fy=-3*y*y;
        g=3*x*x*x+4*y*y-145+(R/10);
        gx=9*x*x;
        gy=8*y;
        h=(g*fy-f*gy)/(fx*gy-fy*gx);
        k=(f*gx-g*fx)/(fx*gy-fy*gx);
        printf("\n %d %0.8lf  %0.8lf  %0.8lf  %0.8lf  %0.8lf  %0.8lf  %0.8lf  %0.8lf  %0.8lf  %0.8lf\n",n,x,y,f,fx,fy,g,gx,gy,h,k);
        x=x+h;
        y=y+k;
        n++;
    }
    while(fabs(h)>0.000001 && fabs(k)>0.00001);
    printf("\n\n The roots are\n\n x = %.6lf \n y = %.6lf\n\n ",x,y);
}
