	#include<stdio.h>
		#include<math.h>
		double g1(double x,double a,double pi)
		{
			return(a*sin(pi*x/2));
		}
		main()
		{
			int i,j;
			double x[50],t[50],h,k,a,pi,sigma,u[50][50],r;
			printf("Enter roll(r),initial value(x[0]),initial value(t[0]),step length(h),sigma = ");
    	    scanf("%lf %lf %lf %lf %lf",&r,&x[0],&t[0],&h,&sigma);
			k=0.05;
			a=5+(0.01*r);
			pi=4.*atan(1.);
			for(i=0;i<=8;i++)
			{
				u[i][0]=g1(x[i],a,pi);
				x[i+1]=x[i]+h;
			}
			for(j=0;j<=5;j++)
			{
				u[0][j]=0;
				u[10][j]=0;
				t[j+1]=t[j]+k;
			}
			for(i=1;i<=7;i++)
			{
				u[i][1]=(0.5*sigma*(u[i+1][0]+u[i-1][0])+(1-sigma)*u[i][0]);
			}
			for(j=1;j<=4;j++)
			{
				for(i=1;i<=7;i++)
				{
				u[i][j+1]=(sigma*(u[i+1][j]+u[i-1][j]))+(2*(1-sigma)*u[i][j])-u[i][j-1];
				x[i+1]=x[i]+h;
				}
			}
		printf("t[j]:x[i]");
		for(i=0;i<=8;i++)
		{
			printf("%lf  ",x[i]);
		}
		for(j=0;j<=5;j++)
		{
			printf("\n%lf  ",t[j]);
			for(i=0;i<=8;i++)
			{
				printf("%lf  ",u[i][j]);
			}
		}
		}
