#include <stdio.h>
int main()
{
    int n;
    printf("Enter n = ");
    scanf("%d", &n);

    float x[100], y[100];
    for (int i = 1; i <= n; i++)
    {
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);

        printf("y[%d] = ", i);
        scanf("%f", &y[i]);
    }
    float xp, yp;
    printf("Enter interpolation point ");
    scanf("%f", &xp);

    float p;
    for (int i = 1; i < n; i++)
    {
        p = 1;
        for (int j = 1; j <= n; j++)
        {
            if (i != j)
            {
                p *= (xp - x[j]) / (x[i] - x[j]);
            }
        }
        yp += p * y[i];
    }

    printf("Value of y at %.3f is %.3f", xp, yp);
}
