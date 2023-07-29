#include<stdio.h>
#include<conio.h>
  int main()
{
   int c, first, last, middle, search, array[100];
   int i, j, temp;
   printf("Enter 30 integers to make the array:\n");
 
   for (c = 0; c < 30; c++)
   {
     scanf("%d",&array[c]);
   } 
   for(i=0; i<30; i++)   
   {
          for(j=i+1; j<30; j++)
         {  
   if(array[i] > array[j])
            {
                temp     = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
          }
   }
    printf("\nElements of array in sorted ascending order:\n ");
    for(i=0; i<30; i++)
    {
        printf("%d\t", array[i]);
    }

 
   printf("\n\nEnter value to find it's position::\n");
   scanf("%d", &search);
 
   first = 0;
   last = 30 - 1;
   middle = (first+last)/2;
 
   while (first <= last) {
      if (array[middle] < search)
         first = middle + 1;    
      else if (array[middle] == search) {
         printf("%d found at location %d.\n", search, middle+1);
         break;
      }
      else
         last = middle - 1;
 
      middle = (first + last)/2;
   }
   if (first > last)
      printf("Not found! %d is not present in the list.\n", search);
      getch();
 
   return 0;  
   
}
