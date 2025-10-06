#include <stdio.h>

void main()
{
    int matrix[10][10];
    int sparseMatrix[20][3];
    int i, j, m, n;
    int k = 1;

    printf("Enter the number of rows: ");
    scanf("%d", &m);
    printf("Enter the number of columns: ");
    scanf("%d", &n);

    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (matrix[i][j] != 0)
            {
                sparseMatrix[k][0] = i;
                sparseMatrix[k][1] = j;
                sparseMatrix[k][2] = matrix[i][j];
                k++;
            }
        }
    }

    sparseMatrix[0][0] = m;
    sparseMatrix[0][1] = n;
    sparseMatrix[0][2] = k - 1;

    printf("\nSparse Matrix Representation (Triplet Form):\n");
    printf("Row  Col  Val\n");
    for (i = 0; i < k; i++)
    {
        printf(" %d    %d    %d\n", sparseMatrix[i][0], sparseMatrix[i][1], sparseMatrix[i][2]);
    }
}
