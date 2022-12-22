#include <stdio.h>

int main()
{
    int n;
    printf("Enter n = ");
    scanf("%d", &n);

    float a[n][n + 1];

    printf("\nEnter values for x\n");
    for (int i = 0; i < n; i++)
    {
        printf("x[%d] = ", i);
        scanf("%f", &a[i][0]);
    }
    printf("Enter values for y\n");
    for (int i = 0; i < n; i++)
    {
        printf("y[%d] = ", i);
        scanf("%f", &a[i][1]);
    }

    float x;
    printf("Enter value of x to find the value of y: ");
    scanf("%f", &x);

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < n - i + 1; j++)
        {
            a[j][i] = a[j + 1][i - 1] - a[j][i - 1];
        }
    }
    // table
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i + 1; j++)
        {
            printf("%f\t", a[i][j]);
        }
        printf("\n");
    }

    float r = (x - a[n - 1][0]) / (a[1][0] - a[0][0]);
    float yn = a[n - 1][1];

    float h = r;
    float fact = 1;
    int j = 2;
    for (int i = n - 2; i >= 0; i--)
    {
        yn = yn + (h * a[i][j]) / fact;

        fact *= 1;
        h = h * (r + (j - 1));
        j++;
    }

    printf("At x = %.4f y = %.4f\n", x, yn);
    return 0;
}
