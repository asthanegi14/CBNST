#include<math.h>
#include <stdio.h>
#include<unistd.h>
#include<conio.h>
#define f(x) cos(x)-x*exp(x)
void main()
{
    printf("Astha Negi\t20012596\t16,J\n");
    int itr=1;
    float err;
    float a,b,mid,f0,f1,f2;
    
    up:
    printf("enter initial guess a\n");
    scanf("%f",&a);
    printf("enter initial guess b\n");
    scanf("%f",&b);
    printf("enter torelable error\n");
    scanf("%f",&err);
    
    f0=f(a);
    f1=f(b);
    
    if(f0*f1>0.0){
        printf("wrong initial guess!! \nPlease try again.\n");
        goto up;
    }
    else{
        printf("Step\t      a      \tb           \tmid       \tf(mid)\n");
        do{
            mid = (a+b)/2;
            f2=f(mid);
            
            printf("%d\t%f\t%f\t%f\t%f\n",itr,a,b,mid,f2);
            if(f0*f2<0.0){
                b=mid;
                f1=f2;
            }
            else{
                a=mid;
                f0=f2;
            }
            itr++;
        }while(fabs(f2)>err);
        printf("Root is = %f",mid);
        getch();
    }
}
