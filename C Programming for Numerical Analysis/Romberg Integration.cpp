#include<stdio.h>
		#include<math.h>
		double f(double x,double r)
		{
			return(1/(pow((1-r*(pow(sin(x),2))),3/2)));
		}
		main()
		{
			int i,j,k,m,l;
			double x,a,b,r,I[50][50],h,sum;
	    	printf("Enter roll(r),lower limit(a),uper limit(b) = ");
        	scanf("%lf%lf%lf",&r,&a,&b);
			printf("\nk  I[K][0]     I[K][1]     I[K][2]     I[K][3]     I[K][4]     I[K][5]\n\n");
			for(i=0;i<=5;i++)
			{
				h=(b-a)/pow(2,i);
				sum=0;
				x=a;
				for(j=0;x+h<b;j++)
				{
					x=x+h;
					sum=sum+f(x,r);
				}
				I[i][0]=(h/2.0)*(f(a,r)+f(b,r)+2*sum);
			}
			for(k=0;k<5;k++)
			{
				for(m=1;m<=k+1;m++)
				{
					I[k+1][m]=((pow(4,m)*I[k+1][m-1])-I[k][m-1])/(pow(4,m)-1);
				}
			}
			for(k=0;k<=5;k++)
			{
				printf("%d  ",k);
				for(m=0;m<=k;m++)
				{
		    		printf("%.9lf  ",I[k][m]);
				}
				printf("\n",k);
			}
			printf("\nthe required value of the integral is = %.6lf\n",I[5][5]);
			printf("%lf",r);
		}

