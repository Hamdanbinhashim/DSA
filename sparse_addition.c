#include <stdio.h>

void main() 
{
    int m, n;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &m, &n);

    int mat1[m][n], mat2[m][n];
    int sparse1[m+n][3], sparse2[m+n][3], result[m+n][3];
    int i, j, k, k1 = 1, k2 = 1;

    printf("Enter elements of the first matrix:\n");
    for (i = 0; i < m; i++) 
    {
        for (j = 0; j < n; j++) 
        {
            scanf("%d", &mat1[i][j]);
            if (mat1[i][j] != 0) 
            {
                sparse1[k1][0] = i;
                sparse1[k1][1] = j;
                sparse1[k1++][2] = mat1[i][j];
            }
        }
    }
    sparse1[0][0] = m;
    sparse1[0][1] = n; 
    sparse1[0][2] = k1 - 1;

    printf("Enter elements of the second matrix:\n");
    for (i = 0; i < m; i++) 
    {
        for (j = 0; j < n; j++) 
        {
            scanf("%d", &mat2[i][j]);
            if (mat2[i][j] != 0) 
            {
                sparse2[k2][0] = i;
                sparse2[k2][1] = j;
                sparse2[k2++][2] = mat2[i][j];
            }
        }
    }
    sparse2[0][0] = m; 
    sparse2[0][1] = n; 
    sparse2[0][2] = k2 - 1;

    i = 1, j = 1, k = 1;
    while (i < k1 && j < k2) 
    {
        if (sparse1[i][0] < sparse2[j][0]) 
        {
            result[k][0] = sparse1[i][0];
            result[k][1] = sparse1[i][1];
            result[k++][2] = sparse1[i++][2];
        } else if (sparse2[j][0] < sparse1[i][0]) 
        {
            result[k][0] = sparse2[j][0];
            result[k][1] = sparse2[j][1];
            result[k++][2] = sparse2[j++][2];
        } 
        else 
        {
            if (sparse1[i][1] < sparse2[j][1]) 
            {
                result[k][0] = sparse1[i][0];
                result[k][1] = sparse1[i][1];
                result[k++][2] = sparse1[i++][2];
            } 
            else if (sparse2[j][1] < sparse1[i][1]) 
            {
                result[k][0] = sparse2[j][0];
                result[k][1] = sparse2[j][1];
                result[k++][2] = sparse2[j++][2];
            } 
            else 
            {
                int sum = sparse1[i][2] + sparse2[j][2];
                if (sum != 0) 
                {
                    result[k][0] = sparse1[i][0];
                    result[k][1] = sparse1[i][1];
                    result[k++][2] = sum;
                }
                i++; j++;
            }
        }
    }
    while (i < k1) 
    {
        result[k][0] = sparse1[i][0];
        result[k][1] = sparse1[i][1];
        result[k++][2] = sparse1[i++][2];
    }
    while (j < k2) 
    {
        result[k][0] = sparse2[j][0];
        result[k][1] = sparse2[j][1];
        result[k++][2] = sparse2[j++][2];
    }
    result[0][0] = m; result[0][1] = n; result[0][2] = k - 1;
    printf("\nResultant Sparse Matrix (Triplet Form):\n");
    printf("Row  Col  Val\n");
    for (i = 0; i < k; i++) 
    {
        printf(" %d    %d    %d\n", result[i][0], result[i][1], result[i][2]);
    }
}
