 #include<stdio.h>
    #include<math.h>
        double f(double x,double y, double r)
        {
        	return(y*(1.3+0.01*r+x*y-x*x*y*y*y)/(x*(1.5+x*x+y*y*y)));
		}
        int main() 
        {
	       int i,n,r;
               double x[10],y[10],h;
               double a,l,k,k1,k2,k3,k4,temp;
               printf("Enter roll(r),step length(h),initial value(x[0]),initial value(y[0]),number of step(n) = ");
			   scanf("%d%lf%lf%lf%d",&r,&h,&x[0],&y[0],&n); 
                printf("\nThe initialnodes by Rk4 method are:\n");
               printf("\n x[i]   y[i]   f(x[i],y[i],r)   k1   k2   k3  k4  y[i+1]");
               for(i=0;i<=3;i++)
               {
                     k1=h*f(x[i], y[i],r);
                     k2=h*f(x[i]+h/2, y[i]+k1/2,r);
					  k3=h*f(x[i]+h/2, y[i]+k2/2,r);
					  k4=h*f(x[i]+h, y[i]+k3,r);
					 y[i+1]=y[i]+(k1+2*k2+2*k3+k4)/6; 
					 printf("\n\n %.2lf  %lf  %lf  %lf  %lf  %lf  %lf  %lf",x[i],y[i],f(x[i],y[i],r),k1,k2,k3,k4,y[i+1]);                 
                     x[i+1]=x[i]+h;
               }
             printf("\n\nCOMPUTATIONAL TABLE OF MILNE'S METHOD \n");
        printf("\nx  yp[i]  f(x[i],y[i])  yc[i]\n");
		for(i=3;i<n;i++)
		{
			x[i+1]=x[i]+h;
			y[i+1]=y[i-3]+(4*h/3)*(2*f(x[i],y[i],r)-f(x[i-1],y[i-1],r)+2*f(x[i-2],y[i-2],r));
			printf("\n%.2lf  %lf   ",x[i+1],y[i+1]);
	        do
	        {
	        	temp=y[i+1];
	        	printf("%lf  ",f(x[i+1],y[i+1],r));
	            y[i+1]=y[i-1]+(h/3)*(f(x[i-1],y[i-1],r)+4*f(x[i],y[i],r)+f(x[i+1],y[i+1],r));
	            printf("%lf\n\t\t  ",y[i+1]);
			}
	        while(fabs(y[i+1]-temp)>0.0000001);		    
		}  
	}
