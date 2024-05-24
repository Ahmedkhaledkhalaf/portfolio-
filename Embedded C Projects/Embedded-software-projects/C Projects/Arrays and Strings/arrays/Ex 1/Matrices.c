#include <stdio.h>
void MatrixPrint(float Mat[2][2]);
void Matrixsetting(float array[2][2]);
void MatricesAdding(float arr1[2][2], float arr2[2][2], float arr3[2][2]);
int main()
{
    float MAtrix_A[2][2];
    float MAtrix_B[2][2];
    float Matrix_Sum[2][2];


    printf("\nPlease set your first Matrix A Elements\n");
    Matrixsetting(MAtrix_A);
    printf("\nPlease set your second Matrix B Elements\n");
    Matrixsetting(MAtrix_B);

    MatricesAdding(MAtrix_A, MAtrix_B, Matrix_Sum);


        printf("\n");
        printf("The result of your matrices summition is:\n");

    MatrixPrint(Matrix_Sum);

    printf("\n Thank you! \n");

    return 0;
}

void MatrixPrint(float Mat[2][2])
{
    for (int i = 0; i<2; i++)
    {

        for (int j = 0; j < 2; j++)
        {
            printf("%.2f\t", Mat[i][j]);
        }
        printf("\n");
    }

            printf("\n");

}
void Matrixsetting(float array[2][2])
{

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            scanf("%f", &array[i][j]);
        }
    }

    MatrixPrint(array);

}

void MatricesAdding(float arr1[2][2], float arr2[2][2], float arr3[2][2])
{
    for (int i = 0; i<2; i++)
    {

        for (int j = 0; j < 2; j++)
        {
            arr3[i][j] = arr1[i][j] + arr2[i][j];
        }

    }



}
