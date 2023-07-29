// program to printing fibonacci series upto 100//

#include <stdio.h>                 //including library files 
int  main()                //including main files 
{	                  //starting a block 
    int a=0,b=1,c=0,i;              //declaring variable 
    printf("Fibonacci series upto 100 \n");            //input 
    printf("%d \n%d \n",a,b);            //giving input 
    for(i=0;i<=10;i++)                  //for loop 
       {                          //block under for loop
          c=a+b;                     //next term 
          if(c<=100)                     //if condition 
             {                               //block under if condition 
               printf("%d \n",c);            //printing next term
             }                                //cloding the block under if condition 
          a=b;                       //next term loop
          b=c;                                      //next term loop
       }                                 ///closing the block under loop
    return 0;                   //return value 
}             //closing the main block