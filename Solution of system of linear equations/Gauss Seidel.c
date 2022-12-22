#include <stdio.h>
#include <math.h>

float x1(float a, float b, float c){
    return (46-(2*b)+(3*c))/13;
}
float yone(float a, float b, float c){
    return (33-(2*a)-c)/15;
}
float z1(float a, float b, float c){
    return (25-a+b)/10;
}
int main()
{
    float err,e1,e2,e3;
    float f1,f2,f3,x0=0,y0=0,z0=0;
    int itr = 1;
    
    printf("Gauss Seidel\n");
    printf("Enter error\n");
    scanf("%f",&err);
    
    printf("Step\tx1\ty1\tz1\n");
    
    do{
        f1 = x1(x0,y0,z0);
        f2 = yone(x0,y0,z0);
        f3 = z1(x0,y0,z0);
        
        printf("%d\t%.4f\t%.4f\t%.4f\n",itr,f1,f2,f3);
        
        e1 = fabs(x0-f1);
        e2 = fabs(y0-f2);
        e3 = fabs(z0-f3);
        
        itr++;
        
        x0=f1;
        y0=f2;
        z0=f3;
        
    }while(e1>err && e2>err && e3>err);
    
    printf("x = %.4f\ty = %.4f\tz = %.4f\n",f1,f2,f3);
    return 0;
}
