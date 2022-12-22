#include <stdio.h>
#include <math.h>
float f(float a, float b)
{
    return (-a * b * b);
}
int main()
{
    float x0, y0, a;
    int n;
    printf("enter x0 = ");
    scanf("%f", &x0);
    printf("enter y0 = ");
    scanf("%f", &y0);

    printf("enter n = ");
    scanf("%d", &n);

    float x[n], y[n];

    printf("enter x to find its value ");
    scanf("%f", &a);

    int i = 1;
    float h = (a - x0) / n;
    x[0] = x0;
    int k = 1;
    for (int i = 1; i <= n; i++)
    {
        x[i] = x[i - 1] + h * k;
    }
    y[0] = y0;
    for (int i = 1; i <= n; i++)
    {
        y[i] = y[i - 1] + h * f(x[i - 1], y[i - 1]);
    }

    printf("x\ty\n");
    for (int i = 1; i <= n; i++)
    {
        printf("%.4f\t%.4f\n", x[i], y[i]);
    }

    printf("Anser = %.4f", y[n]);
}
