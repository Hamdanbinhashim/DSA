#include <stdio.h>
struct term
{
    int coeff;
    int exp;
};

void main()
{
    struct term p1[50], p2[50], res[100];
    int n1, n2, i = 0, j = 0, k = 0;
    printf("Enter number of terms in polynomial 1: ");
    scanf("%d", &n1);

    printf("Enter terms (coeff exp): ");
    for (i = 0; i < n1; i++)
        scanf("%d%d", &p1[i].coeff, &p1[i].exp);

    printf("Enter number of terms in polynomial 2: ");
    scanf("%d", &n2);

    printf("Enter terms (coeff exp): ");
    for (j = 0; j < n2; j++)
        scanf("%d%d", &p2[j].coeff, &p2[j].exp);

    i = 0;
    j = 0;

    while (i < n1 && j < n2)
    {
        if (p1[i].exp > p2[j].exp)
            res[k++] = p1[i++];
        else if (p1[i].exp < p2[j].exp)
            res[k++] = p2[j++];
        else
        {
            res[k].exp = p1[i].exp;
            res[k].coeff = p1[i].coeff + p2[j].coeff;
            i++;
            j++;
            k++;
        }
    }

    while (i < n1)
        res[k++] = p1[i++];

    while (j < n2)
        res[k++] = p2[j++];

    printf("Resultant Polynomial:\n");
    for (i = 0; i < k; i++)
    {
        printf("%dx^%d", res[i].coeff, res[i].exp);
        if (i < k - 1)
            printf(" + ");
    }
    printf("\n");
}
