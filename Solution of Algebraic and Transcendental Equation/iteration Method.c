#include <stdio.h>
#include<math.h>
#define f(x) x*x*x+x*x-1
#define g(x) 1/(sqrt(x+1))
int main()
{
    printf("Astha Negi\t20012596\t16,J\nIteration Method\n");
    float a,b,x1,f0,f1,f2,n;
    up:
    printf("Enter initial guess a = ");
    scanf("%f",&a);

    printf("Enter initial guess b = ");
    scanf("%f",&b);
    
    printf("Enter total number of iterations = ");
    scanf("%f",&n);
    
    f0=f(a);
    f1=f(b);
    
    if((f0*f1)>0.0){
        printf("Invalid guesses\n");
        goto up;
    }
    int stp=1;
    x1=(a+b)/2;
    printf("\nStep\tx1    \t\tf(x1)\n");
    do{
    
        f2=g(x1);
        printf("%d\t%f\t%f\n",stp,x1,f2);
        x1=f2;
        stp++;
    }while(stp<=n);
    printf("\nRoot is = %f",f2);
    return 0;
}
