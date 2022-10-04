#include <stdio.h>
#include<math.h>
#define f(x) cos(x) - x*exp(x)
float findx2(float x0, float x1){
    return x0-((x1-x0)/(f(x1)-f(x0)));
}
int main()
{
    printf("Regular Falsi\n");
    float a,b,x2,f0,f1,f2;
    int n,step=1;
    
    up:
    printf("Enter initial guess a = ");
    scanf("%f",&a);
    
    printf("Enter initial guess b = ");
    scanf("%f",&b);
    
    printf("Enter total iterations = ");
    scanf("%d",&n);
    
    f0=f(a);
    f1=f(b);
    
    if(f0*f1>0.0){
        printf("f0 = %f, f1 = %f\nWrong initial guess!!! Try again\n",f0,f1);
        goto up;
    }
    printf("Step\ta\t\tb\t\tx2\t\tf(a)\t\tf(b)\t\tf(x2)\n");
    do{
        x2 = findx2(a,b);
        f2=f(x2);
        printf("%d\t%f\t%f\t%f\t%f\t%f\t%f\n",step,a,b,x2,f0,f1,f2);
        if(f2>0){
            b=x2;
            f1=f2;
        }
        else{
            a=x2;
            f0=f2;
        }
        step++;
    }while(step!=n);
    
    printf("\nRoot is = %f",x2);
    
    return 0;
}
