#include<stdio.h>     //header file & standard input-output   //single comment 
#include<conio.h>     //console input-output
#include<string.h>

int main()                       //main function
{
	printf("Hello worl, I'm going to start my C programming\n");     /*printing something*/  //multiple comment
	
   int a;
   float b;
   char s;          //a,b,c are variable
   a=50;                //50,60.253 are constants 
   b=60.52;
   s='p';
   printf("\n The value of a is %d",a);
   printf("\n The value of b is %f",b);
   printf("\n The character name is  is %c",s);
   
   int num=a+b;
   printf("\n Implicit conversion is %d",num);  //implicit conversion btw data type
   
   int c=int(b);
   printf("\n explicit conversion of b is %d",c);   //explicit conversion btw data type
   
//Use of scanf() function
  int d;
  printf("\n Enter d: ");
  scanf("%d",&d);     //& denotes address operator 
  printf("\n the value of d using scanf function is %d",d);
  
  
   int e=10;
   int f = 20;
   int g=10;
   
   int sum=e+f;
   printf("\n the sum of e & f is %d",sum);   //add,substract,multiply,divison
   
   printf("\n e<f %d",e<f);                       //relational operator
   printf("\n e>f %d",e>f);
   printf("\n e=g %d",e=g);
  
   bool h=true;                        //boolean operators
   bool k=false;
   printf("\n h&&k = %d", h&&k);
   printf("\n h!!k = %d", h||k);
   printf("\n h!= %d",!h);
   
   printf("\n plus=%d", e+10);                 //assignment operator
   printf("\n minus=%d", e-10);
   int w = e*10;
   printf("\n multi=%d", w);
  
  
}


