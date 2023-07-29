// Program to find the gross salary //

#include<stdio.h>           //including library functions
int main()                 //calling main function
{
	float b,d,h,dr,hr,g;                  //declaring variable              
	
	printf("Enter the value of basic salary :");                    
	scanf("%f",&b);                    //input for basic salayr
	printf("Enter the value of DA rate :");
	scanf("%f",&dr);                    //input for rate of DA
	printf("Enter the value of HRA rate :");
	scanf("%f",&hr);                   //input of rate for HRA
	
	d=(b*dr)/100;                    // Da calculation
	h=(b*hr)/100;         //HRA calculation
	 
	printf("The value of DA is %f \n",d);                //output for DA
	printf("The value of HRA is %f \n",h);               //output for HRA
	
	g=b+h+d;            //gross salary calculation
	printf("The value of gross salary is %f",g);             //output
	
	return 0;         //return value
}    