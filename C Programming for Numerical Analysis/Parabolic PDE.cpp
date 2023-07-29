#include<stdio.h>
		#include<math.h>
		double g1(double x,double a)
		{
			return(a*x*(1-x)*(x*x+2));
		}
		main()
		{
			int i,j;
			double x[50],t[50],h,k,a,sigma,u[50][50],r;
			printf("Enter roll(r),initial value(x[0]),initial value(t[0]),step length(h),sigma = ");
    	    scanf("%lf %lf %lf %lf %lf",&r,&x[0],&t[0],&h,&sigma);
			k=0.016;
			a=3+(0.01*r);
			for(i=0;i<=5;i++)
			{
				u[i][0]=g1(x[i],a);
				x[i+1]=x[i]+h;
			}
			for(j=0;j<5;j++)
			{
				u[0][j]=0;
				u[5][j]=0;
				t[j]=j*k;
			}
			for(j=0;j<4;j++)
			{
				for(i=1;i<=4;i++)
				{
				u[i][j+1]=(sigma*(u[i+1][j]+u[i-1][j]))+((1-2*sigma)*u[i][j])+k*3*x[i]*t[j];
				x[i+1]=x[i]+h;
				}
			}
		printf("t[j]:x[i]");
		for(i=0;i<=5;i++)
		{
			printf("%.8lf  ",x[i]);
		}
		for(j=0;j<5;j++)
		{
			printf("\n%.8lf  ",t[j]);
			for(i=0;i<=5;i++)
			{
				printf("%.8lf  ",u[i][j]);
			}
		}
		}

