#include <stdio.h>
#include<math.h>

int main()
{
    int n;
    printf("Enter n = ");
    scanf("%d",&n);
    
    float a[n][n+1];
    
    printf("\nEnter values for x\n");
    for(int i=0;i<n;i++){
        printf("x[%d] = ",i);
        scanf("%f",&a[i][0]);
    }
    printf("Enter values for y\n");
    for(int i=0;i<n;i++){
        printf("y[%d] = ",i);
        scanf("%f",&a[i][1]);
    }
    
    float x;
    printf("Enter value of x to find the value of y: ");
    scanf("%f",&x);
    
    for(int i=2;i<=n;i++){
        for(int j=0;j<n-i+1;j++){
            a[j][i] = a[j+1][i-1]-a[j][i-1];
        }
    }
    
    
    //table
    for(int i=0;i<n;i++){
        for(int j=0;j<=n-i;j++){
            printf("%f\t",a[i][j]);
        }
        printf("\n");
    }
    
    //Formula = y0 + r*y0' + ( r*(r-1)*y0'')/2! + ( r*(r-2)*(r-1)*y0''')/3!........
   
    float r = (x-a[0][0])/(a[1][0]-a[0][0]);  //r , p , h
    
    float y0 = a[0][1];
    float h = r;
    float fact = 1;
    
    for(int i=2;i<=n;i++){
        y0 = y0 + (h*a[0][i])/fact;
        fact = fact * i;
        h = h*(r-(i-1));
    }
    
    printf("\nValue At x = %f is = %f",x,y0);
    return 0;
}
