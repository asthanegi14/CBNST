#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define f(x) 1 / (1 + pow(x, 2))
void trap(float y[], int n, float h)
{
    float ans;
    float div = (y[0] + y[n]) / 2;
    float sum;
    for (int i = 1; i < n; i++)
    {
        sum += y[i];
    }
    float overallSum = div + sum;
    ans = h * overallSum;
    printf("\nAnswer = %.4f", ans);
}
void simp13(float y[], int n, float h)
{
    float ans;
    float sum1 = 0, sum2 = 0;
    for (int i = 1; i < n; i++)
    {
        if (i % 2 != 0)
        {
            sum1 += y[i]; // odd sum
        }
        else
        {
            sum2 += y[i]; // even sum
        }
    }
    float overallSum = y[0] + y[n] + (4 * sum1) + (2 * sum2);
    ans = (h / 3) * overallSum;
    printf("\nAnswer = %.4f", ans);
}
void simp38(float y[], int n, float h)
{
    float ans;
    float sum1 = 0, sum2 = 0;
    for (int i = 1; i < n; i++)
    {
        if (i % 3 != 0)
        {
            sum1 += y[i];
        }
        else
        {
            sum2 += y[i];
        }
    }
    float overallSum = y[0] + y[n] + 2 * sum2 + 3 * sum1;

    ans = ((3 * h) / 8) * overallSum;
    printf("\nAnswer = %.4f", ans);
}
int main()
{
    float a, b, h;
    int n;
    printf("Asth Negi\n");
    printf("enter upper limit b = ");
    scanf("%f", &b);

    printf("enter lower limit a = ");
    scanf("%f", &a);

    printf("enter intervals n = ");
    scanf("%d", &n);

    float x[n + 1], y[n + 1];

    h = (b - a) / n;

    x[0] = a;
    for (int i = 1; i <= n; i++)
    {
        x[i] = x[i - 1] + h;
    }
    for (int i = 0; i <= n; i++)
    {
        y[i] = f(x[i]);
    }
    printf("x\t\ty");
    for (int i = 0; i <= n; i++)
    {
        printf("\n%f\t%f", x[i], y[i]);
    }
    while (1)
    {
        printf("\nenter by which method you want to solve this equation\n1. Trapazoidal\n2. Simption 1/3\n3. Simption 3/8\n4. to exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            trap(y, n, h);
            break;
        case 2:
            simp13(y, n, h);
            break;
        case 3:
            simp38(y, n, h);
            break;
        case 4:
            exit(0);
        default:
            printf("\nInvalid choice\n");
        }
    }
}
