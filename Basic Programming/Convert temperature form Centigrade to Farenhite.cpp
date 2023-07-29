// Program to convert temperature from degree centigrade to farehite //

#include<stdio.h>            //including header file
int main()            //including main function 

{
	float c,f;                   //declaring variable for centigrade and farenhite 
	printf("enter the value of temperature in degree centigrade :");   
	scanf("%f",&c);                          //giving the input of c
	f=((9/5)*c)+32;              //formula for f
	printf("The value of temperature in farenhite is %f",f);             //getting the output of f 
	return 0;         //return value
	 
}