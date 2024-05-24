/**
 * @file Matrix Transpose.c
 * @author Ahmed khaled khalaf (https://github.com/Ahmedkhaledkhalaf)
 * @brief
 * @version 0.1
 * @date 2024-03-16
 *
 * @copyright Copyright (c) 2024
 *
 */


#include <stdio.h>
void MatrixPrint(int R, int C, float Mat[R][C]);
void Matrixsetting(int R, int C, float Mat[R][C]);
void Transpose(int R, int C, float Mat[R][C], float Trans[C][R]);
void main()
{
    int row = 0, column = 0;
    printf("Please Enter the number of rows:\t");
    scanf("%d", &row);
    printf("\n");
    printf("Please Enter the number of rows:\t");
    scanf("%d", &column);

    float Mat[row][column];
    float Trans[column][row];

    Matrixsetting(row,column, Mat);
    Transpose(row, column, Mat, Trans);



}

void MatrixPrint(int R, int C, float Mat[R][C])
{
    for (int i = 0; i<R; i++)
    {

        for (int j = 0; j < C; j++)
        {
            printf("%.2f\t", Mat[i][j]);
        }
        printf("\n");
    }

            printf("\n");

}
void Matrixsetting(int R, int C, float Mat[R][C])
{

    printf("\nPlease set your Matrix Elements\n");
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            scanf("%f", &Mat[i][j]);
        }
    }

    printf("\n your original Matrix is:\n");
    MatrixPrint(R, C, Mat);

}


void Transpose(int R, int C, float Mat[R][C], float Trans[C][R])
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            Trans[j][i] = Mat[i][j];
        }
    }

    printf("\n your transposed Matrix is:\n");

    MatrixPrint(C,R,Trans);
}
