#include <stdio.h>
void main()
{
    int A[100][3], B[100][3], T[100][3], sum[100][3];
    int i, j, k = 0;

    printf("Enter rows, columns & non-zero elements in matrix A:");
    scanf("%d%d%d", &A[0][0], &A[0][1], &A[0][2]);

    printf("Enter row column value:\n");
    for (i = 1; i <= A[0][2]; i++)
        scanf("%d%d%d", &A[i][0], &A[i][1], &A[i][2]);

    T[0][0] = A[0][1];
    T[0][1] = A[0][0];
    T[0][2] = A[0][2];
    k = 1;

    for (int col = 0; col < A[0][1]; col++)
        for (i = 1; i <= A[0][2]; i++)
            if (A[i][1] == col)
            {
                T[k][0] = A[i][1];
                T[k][1] = A[i][0];
                T[k][2] = A[i][2];
                k++;
            }

    printf("Transpose matrix:\nRow  Col  Value\n");
    for (i = 0; i <= T[0][2]; i++)
        printf("%d\t%d\t%d\n", T[i][0], T[i][1], T[i][2]);

    printf("Enter rows, columns & non-zero elements in matrix B:");
    scanf("%d%d%d", &B[0][0], &B[0][1], &B[0][2]);

    printf("Enter row column value:\n");
    for (i = 1; i <= B[0][2]; i++)
        scanf("%d%d%d", &B[i][0], &B[i][1], &B[i][2]);

    if (A[0][0] != B[0][0] || A[0][1] != B[0][1])
    {
        printf("Matrix addition not possible!");
        return;
    }

    i = 1; j = 1; k = 1;
    sum[0][0] = A[0][0];
    sum[0][1] = A[0][1];

    while (i <= A[0][2] && j <= B[0][2])
    {
        if ((A[i][0] == B[j][0]) && A[i][1] == B[j][1])
        {
            sum[k][0] = A[i][0];
            sum[k][1] = A[i][1];
            sum[k][2] = A[i][2] + B[j][2];
            i++; j++; k++;
        }
        else if ((A[i][0] < B[j][0]) || (A[i][0] == B[j][0] && A[i][1] < B[j][1]))
        {
            sum[k][0] = A[i][0];
            sum[k][1] = A[i][1];
            sum[k][2] = A[i][2];
            i++; k++;
        }
        else
        {
            sum[k][0] = B[j][0];
            sum[k][1] = B[j][1];
            sum[k][2] = B[j][2];
            j++; k++;
        }
    }

    while (i <= A[0][2])
    {
        sum[k][0] = A[i][0];
        sum[k][1] = A[i][1];
        sum[k][2] = A[i][2];
        i++; k++;
    }

    while (j <= B[0][2])
    {
        sum[k][0] = B[j][0];
        sum[k][1] = B[j][1];
        sum[k][2] = B[j][2];
        j++; k++;
    }

    sum[0][2] = k - 1;

    printf("Resultant matrix:\nRow  Col  Value\n");
    for (i = 0; i <= sum[0][2]; i++)
        printf("%d\t%d\t%d\n", sum[i][0], sum[i][1], sum[i][2]);
}
