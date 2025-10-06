#include <stdio.h>

void main() 
{
    int m, n;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &m, &n);

    int matrix[m][n];
    int sparse[m][n], transpose[m+n][3];
    int i, j, k = 1;

    printf("Enter elements of the matrix:\n");
    for (i = 0; i < m; i++) 
    {
        for (j = 0; j < n; j++) 
        {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] != 0) 
            {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k++][2] = matrix[i][j];
            }
        }
    }
    sparse[0][0] = m; 
    sparse[0][1] = n; 
    sparse[0][2] = k - 1;

    if (k > 1) 
    {
        int col_counts[10]={0};
        int start_pos[10]={0};

        for (i = 1; i < k; i++) 
        {
            col_counts[sparse[i][1]]++;
        }
        
        start_pos[0] = 1;
        for (i = 1; i < n; i++) 
        {
            start_pos[i] = start_pos[i - 1] + col_counts[i - 1];
        }

        for (i = 1; i < k; i++) 
        {
            int col = sparse[i][1];
            int pos = start_pos[col];
            
            transpose[pos][0] = sparse[i][1]; 
            transpose[pos][1] = sparse[i][0];
            transpose[pos][2] = sparse[i][2];
            start_pos[col]++;
        }
    }
    
    transpose[0][0] = n;
    transpose[0][1] = m;
    transpose[0][2] = k - 1;

    printf("\nTransposed Sparse Matrix (Triplet Form):\n");
    printf("Row  Col  Val\n");
    for (i = 0; i < k; i++) 
    {
        printf(" %d    %d    %d\n", transpose[i][0], transpose[i][1], transpose[i][2]);
    }
}
