#include <stdio.h>
#include<math.h>
#define f(x) (x*x)-(4*x)-7
#define g(x) (2*x)-4

int main()
{
    printf("Newton Raphson Method\n");
    
    int i=1,n;
    float ans;
    
    printf("\nEnter Initial guess = ");
    scanf("%f",&ans);
    
    printf("\nEnter number of iteration = ");
    scanf("%d",&n);
    
    printf("Step\tf(x)\t\tf'(x)\t\tf(x)/f'(x)\tf(ans)\n");
    
    while(i<=n){
        float x=ans;
        float divi = f(ans)/g(ans);
        ans = ans-divi;
        printf("%d\t%.4f\t\t%.4f\t\t%.4f\t\t%.4f\n",i,f(x),g(x),divi,ans);
        i++;
    }
    
    printf("\nRoot is = %f\n",ans);
    return 0;
}
