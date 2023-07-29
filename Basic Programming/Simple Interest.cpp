// Program to find the simple interest //

#include<stdio.h>   //includinf library files
int main()                //calling main function 

{
	float p,r,i;                //declare principal,rate & interest variable 
	int t;           //declaring time as year
	printf("Enter the value of principal :");
	scanf("%f",&p);                                        //giving input of p
	
    printf("Enter the value of rate :");
	scanf("%f",&r);                     //giving input of r
	
	printf("Enter the value of time(year)) :");
	scanf("%d",&t);                                 //giving input of t 
	
	i=(p*r*t)/100;               //formula of simple interest
	printf("the simple interest is %f",i);                       //getting out of simple interest
	 
	return 0;             //getting return value 
	
}