// program for finding * sequence //

#include <stdio.h>                                       //including library files
int main()                                              //calling main function 
{                                                      //starting main block
    int n,m;                                          //declaring variable 
    printf("Enter the number of rows :");            //input 
    scanf("%d",&n);                                 //input value 
    m=n;                                           //initial 
    for(int i=1;i<=n;i++)                         //for loop for rows 
   {                                             //starting block under for loop
       for(int j=1;j<=m-1;j++)                  //for loop for columns 
       {                                       //starting block under 2nd for loop
           printf(" ");                       //printing blank 
       }                                     //ending 2nd for loop
       for(int k=1;k<=2*i-1;k++)            //for loop for printing *
       {                                   //starting another for loop block
         printf("*");                     //printing *
       }                                 //ending block
       m--;                             //decrement 
       printf("\n");                   //printing line changing 
    }                                 //ending block
    return 0;                        //return value 
}                                   //ending main block