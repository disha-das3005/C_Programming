#include <stdio.h>
#include <stdlib.h>
//LU decomposition method to solve linear equations
//copyright @ Mryang

double sumU(double L[2][2] ,double U[2][2], int i, int j ){
    double sU = 0.0;
    for (int k = 1; k <= i-1 ; k++)
    {
        sU += L[i-1][k-1] * U[k-1][j-1];
    }

    return sU;
}//Calculate the sum 1

double sumL(double L[2][2] ,double U[2][2], int i, int j ){
    double sL = 0.0;
    for (int k = 0; k <= j-1; k++)
    {
        sL += L[i-1][k-1] * U[k-1][j-1];
    }

    return sL;

}//Calculate the sum 2

double sumY(double L[2][2] ,double y[2],int i){
    double sY=0.0;
    for (int k = 1; k <= i - 1; k++)
    {
        sY += L[i-1][k-1] * y[k-1];
    }
    return sY;
}//Calculate the sum 3

double sumX(double U[2][2] ,double x[2],int i ,int m){
    double sX = 0.0;
    for (int k = i+1; k <= m; k++)
    {
        sX += U[i-1][k-1] * x[k-1];
    }
    return sX;
}//Calculate the sum 4
int main(){

    double a[2][2] = { {8,6,},
                    {5,4,},
                    };//Store the coefficients in a two-dimensional array
    double L[2][2] = {0};
    double U[2][2] = {0};//Initialization part
    double b[2] = {2,-1};
    int n = 2;//n order
    //Output [Ab]
    printf("[A]:\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%f\t", a[i-1][j-1]);
        }
        printf("\n");
    }

    //Calculate L, U
    for (int i = 1; i <= n; i++)
    {
        L[i-1][i-1] = 1;//The diagonal element is 1
        for (int j = i; j <= n; j++)
        {
            //Since the array subscript starts from 0, i-1, j-1
            U[i-1][j-1] = a[i-1][j-1] - sumU(L,U,i,j);

            if(j+1 <= n) L[j][i-1] = (a[j][i-1] - sumL(L,U,j+1,i))/U[i-1][i-1];//i becomes j+1, j becomes i 
        }

    }





    //Output U
    printf("U:\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%f\t",U[i-1][j-1]);
        }
        printf("\n");
    }
    //Output L
    printf("L:\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%f\t",L[i-1][j-1]);
        }
        printf("\n");
    }

    //Find y from Ly=b
    double y[2] = {0.0};
    y[0] = b[0];//y(1) = b(1);

    for (int i = 2; i <= n; i++)
    {
        y[i-1] = b[i-1] - sumY(L,y,i);
    }

    //Find x from Ux=y
    double x[2] = {0.0};

    for (int i = n; i >= 1; i--)
    {
        x[i-1] =( y[i-1] - sumX(U,x,i,n))/ U[i-1][i-1];
    }



    //Output y
    printf("y:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%f\n",y[i]);
    }
    printf("\n");
    //Output x
    printf("x:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%f\n",x[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}
