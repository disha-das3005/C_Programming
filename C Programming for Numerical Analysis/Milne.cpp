#include<stdio.h>
    #include<math.h>
        double f(double x,double y)
        {
        	return((1+1.1*x*x+0.3*y*y*y)/(3+0.9*x*x*y*y*y));
		}
        int main() 
        {
	       int i,n,r;
               double x[10],y[10],z[10],h;
               double a,l,k,k1,k2,k3,k4,k5,k6,err,temp;
               printf("Enter roll(r),step length(h),initial value(x[0]),initial value(y[0]),number of step(n) = ");
			   scanf("%d%lf%lf%lf%d",&r,&h,&x[0],&y[0],&n); 
               a=1+(r/10.0);
               z[0]=y[0];
               printf("\nThe initialnodes by Runge Felberg method are:\n");
               printf("\n x[i]   y[i]  z[i]  f(x[i],y[i])  err  k1  k2  k3  k4  k5  k6 y[i+1]");
               for(i=0;i<=3;i++)
               {
                     k1=h*f(x[i], y[i]);
                     k2=h*f(x[i]+h/4, y[i]+k1/4);     
                     k3=h*f(x[i]+3*h/8, y[i]+3*k1/32+9*k2/32);
                     k4=h*f(x[i]+12*h/13, y[i]+1932*k1/2197-7200*k2/2197+7296*k3/2197);
                     k5=h*f(x[i]+h, y[i]+439*k1/216-8*k2+3680*k3/513-845*k4/4104);
                     k=25*k1/216+1408*k3/2565+2197*k4/4104-k5/5;
                     k6=h*f(x[i]+h/2, y[i]-8*k1/27+2*k2-3544*k3/2565+1859*k4/4104-11*k5/40);
                     l=16*k1/135+6656*k3/12825+28561*k4/56430-9*k5/50+2*k6/55;
					 err=fabs(z[i]-y[i]);
					 y[i+1]=y[i]+k; 
					 printf("\n\n %.2lf  %lf  %lf  %lf  %lf  %lf  %lf  %lf  %lf  %lf  %lf  %lf",x[i],y[i],z[i],f(x[i],y[i]),err,k1,k2,k3,k4,k5,k6,y[i+1]);                 
                     z[i+1]=y[i]+l;
                     x[i+1]=x[i]+h;
               }
   printf("\n\nCOMPUTATIONAL TABLE OF MILNE'S METHOD \n");
        printf("\nx  yp[i]  f(x[i],y[i])  yc[i]\n");
		for(i=3;i<n;i++)
		{
			x[i+1]=x[i]+h;
			y[i+1]=y[i-3]+(4*h/3)*(2*f(x[i],y[i])-f(x[i-1],y[i-1])+2*f(x[i-2],y[i-2]));
			printf("\n%.2lf  %lf   ",x[i+1],y[i+1]);
	        do
	        {
	        	temp=y[i+1];
	        	printf("%lf  ",f(x[i+1],y[i+1]));
	            y[i+1]=y[i-1]+(h/3)*(f(x[i-1],y[i-1])+4*f(x[i],y[i])+f(x[i+1],y[i+1]));
	            printf("%lf\n\t\t  ",y[i+1]);
			}
	        while(fabs(y[i+1]-temp)>0.0000001);		    
		}               
}

