// Program to compute the sum of digits of a number //

#include<stdio.h>                                          //including library function
int main()                                                //calling main function 
 {                                                       //starting a block
     int n,sum=0,m;                                     //declaring variable
     printf("Enter a number:");                        //input of number 
     scanf("%d",&n);                                  //giving input 
     while(n>0)                                      //while loop 
          {                                         //starting a sub block
             m=n%10;                               //remainder by 10
             sum=sum+m;                           //increment
             n=n/10;                             // loop 
          }                                     //ending sub block
    printf("Sum is=%d",sum);                   //output
    return 0;                                 //return value
}                                            //ending main block