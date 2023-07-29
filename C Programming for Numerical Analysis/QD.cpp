#include<stdio.h>
	#include<math.h>
	double f(double x)
	{
		return((x*x*x*x)-(11.2*x*x*x)+(42.41*x*x)-(63.83*x)+31.62);
	}
	double f1(double x)
	{
		return((4.*x*x*x)-(11.2*3.*x*x)+(42.41*2.*x)-63.83);
	}
	main()
	{
		double a[50],e[50][50],q[50][50],q1,q2,q3,q4,c,p,p1;
		int i,j,r=0;
		printf("Enter the coefficients a[0],a[1],a[2],a[3],a[4] = ");
		scanf("%lf%lf%lf%lf%lf",&a[0],&a[1],&a[2],&a[3],&a[4]);
		for(i=1;i<=3;i++)
		{
			e[i][0]=a[i+1]/a[i];
		}
	    for(i=1;i<=4;i++)
	    {
	    	if(i==1)
	    	q[i][0]=-(a[1]/a[0]);
	    	else
	    	q[i][0]=0;
		}	
		do
		{
			e[0][r]=0;
			e[4][r]=0;
			r++;
			for(i=1;i<=4;i++)
			{
			q[i][r]=e[i][r-1]-e[i-1][r-1]+q[i][r-1];
			}
			for(i=1;i<=3;i++)
			{
			e[i][r]=(q[i+1][r]*e[i][r-1])/q[i][r];
			}	
		}
		while(r<=6);
		printf("\nTable for quotient difference method \n\ne[0][r]  q[1][r]  e[1][r]  q[2][r]  e[2][r]  q[3][r]  e[3][r] q[4][r]  e[4][r]\n\n");
		for(j=0;j<=r;j++)
		{
			printf("%lf  ",e[0][r]);
			for(i=1;i<=4;i++)
			{
				printf("%lf  %lf ",q[i][j],e[i][j]);
			}
			printf("\n");	
		}
		printf("\nTable for Newton-Raphson method \n\n");
		printf("q[i][k]  p(q[i][k])  p'(q[i][k])  p(q[i][k])/p'(q[i][k])\n\n");
		for(i=1;i<=4;i++)
		{
			do
			{
				p=f(q[i][r]);
				p1=f1(q[i][r]);
				c=p/p1;
				printf("%.8lf  %.8lf  %.8lf  %.8lf\n",q[i][r],p,p1,c);
				q[i][r]=q[i][r]-c;
			}
			while(fabs(c)>=0.00000001);
			printf("\n\n");
		}
		printf("\nthe roots of the equations are %.5lf , %.5lf , %.5lf , %.5lf \n",q[1][r],q[2][r],q[3][r],q[4][r]);
	}

