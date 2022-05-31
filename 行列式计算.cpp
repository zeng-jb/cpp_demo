#include <math.h>
#include <stdio.h>
 
#define  CONST 1e-6
#define  SIZE 20
 
void InputMatrix (double a[][SIZE], int n);
double DeterminantValue(double a[][SIZE], int n);
void SubMatrix(double a[][SIZE], double b[][SIZE], int n, int row, int col);
void PrintMatrix(double a[][SIZE], int n);
int main(void)
{                        
    double  a[SIZE][SIZE];
    int     n;
    double  result;
    printf("Please enter matrix size n(1<=n<%d):", SIZE);
    scanf("%d", &n);
    printf("Please input matrix line by line:\n");
    InputMatrix(a, n);
    printf("matrix a:\n");
    PrintMatrix(a, n);
    printf("\n");
    result = DeterminantValue(a, n);
    printf("result = %f\n", result);
    //printf("%.0f\n",result); 
    return 0;
}                        
//  �������ܣ� ����һ��n��n�����Ԫ��
void InputMatrix (double a[][SIZE], int n)
{                        
    int i, j;
    for (i = 0; i < n; i++)
    {                        
        for (j = 0; j < n; j++)
        {                        
            scanf("%lf", &a[i][j]);
        }
    }
}                        
//  �������ܣ� ����n��n���������ʽ��ֵ
double DeterminantValue(double a[][SIZE], int n)
{                        
    int    i = 0, j = 0;
    double temp, result, b[SIZE][SIZE];
    if (n == 1)
    {                        
        result = a[0][0];
    }
    else if (n == 2)
    {                        
        result = a[0][0] * a[1][1] - a[0][1] * a[1][0];
    }
    else
    {                        
        result = 0.0;
        for (j = 0; j < n; j++)
        {                        
            SubMatrix(a, b, n, i, j);
            printf("Submatrix:\n");
            PrintMatrix(b, n - 1);
            temp = DeterminantValue(b, n - 1);
            result += pow(-1, i + j) * a[0][j] * temp;
            printf("DValue of the Submatrix is %6.1f\n", temp);
        }
    }
    return result;
}                        
//  �������ܣ� ����n��n����a�е�row��col��Ԫ�ص�(n-1)��(n-1)�Ӿ���b
void SubMatrix(double a[][SIZE], double b[][SIZE], int n, int row,
               int col)
{                        
    int i, j, ii = 0, jj = 0;
    for (i = 0; i < n; i++)
    {                        
        jj = 0;
        for (j = 0; j < n; j++)
        {                        
            if (i != row && j != col)
            {                        
                b[ii][jj] = a[i][j];
                jj++;
            }
        }
        if (i != row && j != col)
        {                        
            ii++;
        }
    }
}                        
//  �������ܣ� ���һ��n��n�����Ԫ��
void PrintMatrix(double a[][SIZE], int n)
{                        
    int i, j;
    for (i = 0; i < n; i++)
    {                        
        for (j = 0; j < n; j++)
        {                        
            printf("%6.1f\t", a[i][j]);
        }
        printf("\n");
    }
}                       

