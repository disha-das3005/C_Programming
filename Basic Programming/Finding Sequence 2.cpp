// program for finding sequence //
 
#include <stdio.h >                                   //including library files  
int main()                                           //calling main function 
{  
    int n,m=1;                                      //declaring variable 
    printf("Enter the number of rows : ");  
    scanf("%d",&n);                                //giving input 
    for(int i=n;i>=1;i--)                         //for loop with decrement 
    {  
        for(int j=1;j<=i-1;j++)                 // for loop under for loop 
        {  
          printf(" ");                         //printing blank space 
        }  
        for(int k=1;k<=m;k++)                 //for loop for *
        {  
            printf("*");                     //printing *
        }  
        printf("\n");                       //printing line change 
        m++;                               //increment 
    }  
    return 0;                              //return
}    