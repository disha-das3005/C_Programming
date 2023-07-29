        #include<stdio.h>
        #include<math.h>
        double f(double x,double y,double a);
        int main() 
        {
	       int i,n,r;
               double x[10],y[10],z[10],h;
               double a,l,k,k1,k2,k3,k4,k5,k6,err;
               printf("Enter roll(r),step length(h),initial value(x[0]),initial value(y[0]),number of step(n) = ");
			   scanf("%d%lf%lf%lf%d",&r,&h,&x[0],&y[0],&n); 
               a=1+(r/10.0);
               z[0]=y[0];
               printf("\nThe initialnodes by Runge Felberg method are:\n");
               printf("\n x[i]   y[i]  z[i]  f(x[i],y[i])  err  k1  k2  k3  k4  k5  k6 y[i+1]");
               for(i=0;i<3;i++)
               {
                     k1=h*f(x[i], y[i], a);
                     k2=h*f(x[i]+h/4, y[i]+k1/4, a);     
                     k3=h*f(x[i]+3*h/8, y[i]+3*k1/32+9*k2/32, a);
                     k4=h*f(x[i]+12*h/13, y[i]+1932*k1/2197-7200*k2/2197+7296*k3/2197, a);
                     k5=h*f(x[i]+h, y[i]+439*k1/216-8*k2+3680*k3/513-845*k4/4104, a);
                     k=25*k1/216+1408*k3/2565+2197*k4/4104-k5/5;
                     k6=h*f(x[i]+h/2, y[i]-8*k1/27+2*k2-3544*k3/2565+1859*k4/4104-11*k5/40, a);
                     l=16*k1/135+6656*k3/12825+28561*k4/56430-9*k5/50+2*k6/55;
					 err=fabs(z[i]-y[i]);
					 y[i+1]=y[i]+k; 
					 printf("\n\n %.2lf  %.8lf  %.8lf  %.8lf  %.8lf  %.8lf  %.8lf  %.8lf  %.8lf  %.8lf  %.8lf  %.8lf",x[i],y[i],z[i],f(x[i],y[i],a),err,k1,k2,k3,k4,k5,k6,y[i+1]);                 
                     z[i+1]=y[i]+l;
                     x[i+1]=x[i]+h;
               }
               printf("\n\nThe table for Adam's Bashforth method\n");
               printf("\n x[i]   y[i]  f(x[i],y[i])");
               for(i=3;i<=n-1;i++)
               {
               	     y[i+1]=y[i]+(h*(-9*f(x[i-3],y[i-3],a)+37*f(x[i-2],y[i-2],a)-59*f(x[i-1],y[i-1],a)+55*f(x[i],y[i],a))/24);
               	     x[i+1]=x[i]+h;
                     printf("\n\n%.1f  %.8lf  %.8lf",x[i+1],y[i+1],f(x[i+1],y[i+1],a));
               }
       }
       double f(double x,double y,double a)
       {
	       return (1+sin(1+y+a*x))/(1+exp(x*y*a));
       }

