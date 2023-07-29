#include<stdio.h>
#include<math.h>
double p(double x)
{
	return(x);
}
double q(double x,double r)
{
	return(exp(-r*x));
}
double s(double x,double r)
{
	return(sin(x)+pow(x,r*0.1));
}
int main()
{
    int i,j,R,n;
    double h,r,a,b,A,B,a0,a1,b0,b1,x[100],y[100],m[100],k[100],phi[100],c[100],d[100];
    printf("enter step length(h),initial value(x[0]),number of step(n),roll(R), = ");
    scanf("%lf %lf %d %d",&h,&x[0],&n,&R);
    r=1.5+(R/5.0);
	a0=3.;
	a1=4.;
	b0=2.;
	b1=5.;
	A=5.;
	a=0.;
	b=1.;
	B=10.;
	for(i=0;i<=n;i++)
		{
			m[i]=(2*h*h*q(x[i],r)-4)/(2+h*p(x[i]));
			k[i]=(2-h*p(x[i]))/(2+h*p(x[i]));
			phi[i]=(2*h*h*s(x[i],r))/(2+h*p(x[i]));
			x[i+1]=x[i]+h;
}
		c[1]=(a1-a0*h)/(m[1]*(a1-a0*h)+a1*k[1]);
		d[1]=phi[1]+(k[1]*A*h/(a1-a0*h));
		for(i=2;i<=n;i++)
		{
			c[i]=1/(m[i]-c[i-1]*k[i]);
			d[i]=phi[i]-k[i]*c[i-1]*d[i-1];
		}
y[n]=(2*B*h-b1*(d[n]-c[n-1]*d[n-1]))/(2*b0*h+b1*(c[n-1]-1/c[n]));
		for(i=1;i<10;i++)
		{
			j=10-i;
			y[j]=c[j]*(d[j]-y[j+1]);
		}
		y[0]=(a1*y[1]-A*h)/(a1-a0*h);
		printf("\n\n x\tp\tq\tr\tc\td\tphi\tl\tm\ty\n");
		printf("%.1lf %.7lf %.7lf %.7lf %.7lf %.7lf %.7lf \t\t\t%.7lf\n",x[0],p(x[0]),q(x[0],r),s(x[0],r),m[0],k[0],phi[0],y[0]);
		for(i=1;i<=n;i++)
		{
			printf("%.1lf %.7lf %.7lf %.7lf %.7lf %.7lf %.7lf %.7lf %.7lf %.7lf\n",x[i],p(x[i]), q(x[i],r),   s(x[i],r),   m[i],   k[i],  phi[i],  c[i],  d[i],  y[i]);
		}
	}

