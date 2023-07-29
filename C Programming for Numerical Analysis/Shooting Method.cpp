#include<stdio.h>
#include<math.h>
double f(double x)
{
return(x);
}
double g(double t,double x, double y, double R)
{
return (-(t+R)*x+2.*y+(1-t*t*t)*exp(-t));
}
double f1(double x)
{
return(x);
}
double g1(double t,double x, double y, double R)
{
return (-(t+R)*x+2.*y);
}
int main()
{
   int i,r,n;
    double y[100],t[100],h,u[100],v[100],w[100],z[100],R,a,b,alpha,beta,k1[100],k2[100],k3[100],k4[100],l1[100],l2[100],l3[100],l4[100],_k1[100],_k2[100],_k3[100],_k4[100],_l1[100],_l2[100],_l3[100],_l4[100];
    printf("enter roll,a,alpha,b,beta,h,number of steps(n):");
    scanf("%d%lf%lf%lf%lf%lf%d",&r,&a,&alpha,&b,&beta,&h,&n);
    R=1+0.1*r;
    n=(b-a)/h;
    printf("\ntable for the first ode\n");
	u[0]=alpha;
    w[0]=0;
	t[0]=a;	
	for(i=0;i<n;i++)
    {
        k1[i]=h*f(w[i]);
        l1[i]=h*g(t[i],w[i],u[i],R);
        k2[i]=h*f(w[i]+(l1[i]/2));
        l2[i]=h*g(t[i]+(h/2),w[i]+(l1[i]/2),u[i]+(k1[i]/2),R);
        k3[i]=h*f(w[i]+(l2[i]/2));
        l3[i]=h*g(t[i]+(h/2),w[i]+(l2[i]/2),u[i]+(k2[i]/2),R);
        k4[i]=h*f(w[i]+k3[i]);
        l4[i]=h*g(t[i]+h,w[i]+l3[i],u[i]+k3[i],R);
        u[i+1]=u[i]+((k1[i]+2*k2[i]+2*k3[i]+k4[i])/6);
        w[i+1]=w[i]+((l1[i]+2*l2[i]+2*l3[i]+l4[i])/6);
        printf("t=%.2lf w=%.8lf u=%.8lf k1=%.8lf l1=%.8lf k2=%.8lf l2=%.8lf k3=%.8lf l3=%.8lf k4=%.8lf l4=%.8lf u(i+1)=%.8lf \n",t[i],w[i],u[i],k1[i],l1[i],k2[i],l2[i],k3[i],l3[i],k4[i],l4[i],u[i+1]);
        t[i+1]=t[i]+h;
		}
		 printf("\ntable for the second ode\n");
		 v[0]=0;
    z[0]=1;	
	for(i=0;i<n;i++)
    {
        _k1[i]=h*f1(z[i]);
        _l1[i]=h*g1(t[i],z[i],v[i],R);
        _k2[i]=h*f1(z[i]+(_l1[i]/2));
        _l2[i]=h*g1(t[i]+(h/2),z[i]+(_l1[i]/2),v[i]+(_k1[i]/2),R);
        _k3[i]=h*f1(z[i]+(_l2[i]/2));
        _l3[i]=h*g1(t[i]+(h/2),z[i]+(_l2[i]/2),v[i]+(_k2[i]/2),R);
        _k4[i]=h*f1(z[i]+_k3[i]);
        _l4[i]=h*g1(t[i]+h,z[i]+_l3[i],v[i]+_k3[i],R);
        v[i+1]=v[i]+((_k1[i]+2*_k2[i]+2*_k3[i]+_k4[i])/6);
        z[i+1]=z[i]+((_l1[i]+2*_l2[i]+2*_l3[i]+_l4[i])/6);
        printf("t=%.2lf z=%.8lf v=%.8lf k1=%.8lf l1=%.8lf k2=%.8lf l2=%.8lf k3=%.8lf l3=%.8lf k4=%.8lf l4=%.8lf v(i+1)=%.8lf \n",t[i],z[i],v[i],_k1[i],_l1[i],_k2[i],_l2[i],_k3[i],_l3[i],_k4[i],_l4[i],v[i+1]);
        t[i+1]=t[i]+h;
		}
	 printf("\n required solution is given by\n");
	 for(i=0;i<=n;i++)
	 {
	 	y[i]=u[i]+(beta-u[n])*(v[i]/v[n]);
	 	printf("t=%lf y=%.8lf \n",t[i],y[i]);
		 }	
    }

