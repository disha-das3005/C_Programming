// Program to find are & circumference of circle //

#include<stdio.h>                      //including library file
int main()                                //calling mail function
{
	float pie,r,A,S;                            // declaring variable 
	pie=3.14;                  //puting the value of pie
	printf("Enter the radius of the circle :");             //printing the value of radius
	scanf("%f",&r);                //taking input of radius
	A=pie*r*r;                     //formula of area
	S=2*pie*r;                       //formula of circumference
	printf("The area of circle is %f \n",A);          //printing area
	printf("The circumference of circle is %f",S);      //printing circumference
	return 0;                   //getting return value
}
