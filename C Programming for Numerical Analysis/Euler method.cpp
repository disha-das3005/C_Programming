//Subrata Bera
#include<stdio.h>
#include<math.h>
double pi=4*atan(1);
double f(double x,double y,double R)
{
return(x*x+y*y+R*sin(x*y*pi));
}				 			
main()
{
	int i,n;
	double x[100],y[100],h,R;
	printf("\n Enter The initial Value(x([0]),The initial Value(y[0],step length(h),number of step(n),roll(R) : ");
	scanf("%lf %lf %lf %d %lf",&x[0],&y[0],&h,&n,&R);
	if(R>10)
	R=R/10.0;
	printf("\n\n x[i]\ty[i]\tf(x[i],y[i])\ty[i+1]");
	for(i=0;i<=n;i++)
	{
		x[i+1]=x[i]+h;
		y[i+1]=y[i]+h*f(x[i],y[i],R);
		printf("\n\n %lf\t%lf\t%lf\t%lf", x[i],y[i],f(x[i],y[i],R),y[i+1]);					 							
	} 				
} 		
