// program for finding sequence //

#include <stdio.h>                                             //including library function  
int main()                                                    //calling main function 
{                                                            //starting main block
    int n;                                                  //declaring variable
    printf("Enter the number of rows :");                  // input
    scanf("%d",&n);                                       //giving input
    for(int i=1;i<=n;i++)                                //for loop for row with increment 
    {                                                   //starting a sub block
        for(int j=1;j<=i;j++)                          //under row again a for loop for column
        {                                             //starting sub block
            printf("*");                             //printing *
        }                                           //ending block                    
        printf("\n");                              //printing line change 
    }                                             //ending block
    return 0;                                    //return value 
}                                               //ending block 