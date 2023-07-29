// Program to calculate sum of 5 subject and their percentage //

#include<stdio.h>               //including library file 
int main()                      //calling main function 
{                              //starting bloxk
	float n1,n2,n3,n4,n5,s,p,t1,t2,t3,t4,t5,t;                    //declaring variables 

	printf("Enter the obtained marks of 1st subject :");                         
	scanf("%f",&n1);
	printf("Enter the total marks of 1st subject :");
	scanf("%f",&t1);
	
	printf("Enter the obtained marks of 2nd subject :");
	scanf("%f",&n2);
	printf("Enter the total marks of 2nd subject :");
	scanf("%f",&t2);
	
	printf("Enter the obtained marks of 3rd subject :");
	scanf("%f",&n3);
	printf("Enter the total marks of 3rd subject :");                                // giving the input of 5 subjects
	scanf("%f",&t3);
	
	printf("Enter the obtained marks of 4th subject :");
	scanf("%f",&n4);
	printf("Enter the total marks of 4th subject :");
	scanf("%f",&t4);
	
	printf("Enter the obtained marks of 5th subject :");
	scanf("%f",&n5);
	printf("Enter the total marks of 5th subject :");
	scanf("%f",&t5);
	
	s=n1+n2+n3+n4+n5;
	printf("The value of sum of obtained marks of 5 subjects is %f \n",s);                         //getting the out of sum
	
	t=t1+t2+t3+t4+t5;
	printf("The value of sum of total marks of 5 subjects is %f \n",t);
	 
	p=(s/t)*100;
	printf("The percentage of obtained marks over the total marks is %f",p);                         //getting the output of percentage 
	
	return 0;          //return value 
	

}