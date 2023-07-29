//Subrata Bera
#include<stdio.h>
#include<math.h>
main()
{
	int i,j,k,n;
	double x[100],y[100],l[100],a[100][100];
	printf("\nEnter the order of the matrix : ");
	scanf("%d",&n);
	printf("\nEnter the matrix row wise : \n\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		scanf("%lf",&a[i][j]);
		printf("\n");
	}
	for(i=1;i<=n;i++)
	x[i]=1;
	l[0]=0;
	i=0;
    printf(" required table is : Yk Ck Xk \n\n");
	do
	{				
		i++	;
        printf(" %d)",i);
		for(j=1;j<=n;j++)
		{
			y[j]=0;
			for(k=1;k<=n;k++)
			y[j]=y[j]+x[k]*a[j][k];
        	printf(" %.8lf",y[j]);
		}
		l[i]=y[1];
		for(k=2;k<=n;k++)
		if(fabs(l[i])<y[k])
		{
			l[i]=y[k];
		}
       printf(" %.8lf",l[i]);								
		for(j=1;j<=n;j++)
        {
			x[j]=y[j]/l[i];
       		printf(" %.8lf",x[j]);
        }
        printf("\n\n");
	}
	while(fabs(l[i]-l[i-1])>=0.000001);
	printf("The largest eigen value is %lf\n\n",l[i]);
	printf("and the corresponding eigen vector is \n\n");
	for(i=1;i<=n;i++)
	printf("%.8lf\n",x[i]);
}
