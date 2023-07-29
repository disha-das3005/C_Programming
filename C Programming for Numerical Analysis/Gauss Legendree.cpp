	#include<stdio.h>
	#include<math.h>
	double f(double x,double r)
	{
		return(log(x)/(1.06+x*x+r));
	}
	main()
	{
		double t[50],c[50],x[50],F[50],a,b,I,sum,j[50],r,R;
		int i;
		printf("Enter roll(R),lower limit(a),uper limit(b) = ");
    	scanf("%lf%lf%lf",&R,&a,&b);
		r=R/100.0;
	    printf("\nEnter value of t[k] ");
		for(i=0;i<=3;i++)
		{
			scanf("%lf",&t[i]);
		}
		printf("\nEnter value of c[k] ");
		for(i=0;i<=3;i++)
		{
			scanf("%lf",&c[i]);
		}
		for(i=0;i<=3;i++)
		{
			x[i]=((a+b)/2.)+(((b-a)/2.)*t[i]);
			F[i]=f(x[i],r);
		}
		sum=0;
		printf("\ni\t\ttk\t\tck\t\txk\t\tf(xk)\t\tck*f(xk)\n\n");
		for(i=0;i<=3;i++)
		{
		j[i]=c[i]*F[i];
		printf("%d\t%.10lf\t%.10lf\t%.10lf\t%.10lf\t%.10lf\n",i,t[i],c[i],x[i],F[i],j[i]);
		sum=sum+j[i];
		}
		I=((b-a)/2)*sum;
		printf("\nthe required value of the integral is %.9lf(correct upto 9d)",I);
	}

