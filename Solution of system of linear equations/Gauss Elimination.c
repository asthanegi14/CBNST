#include<stdio.h>
int main(){
   printf("Gauss Elimination\n");
   int i,j,k,n;
   float a[n][n+1];
   int b[n];
   int x[n];
   
   printf("Enter number of equations\n");
   scanf("%d",&n);
   
   printf("Enter coefficients of the equations\n");
 
   for( i=0;i<n;i++){
       for( j=0;j<n;j++){
           printf("a[%d][%d] = ",i,j);
           scanf("%f",&a[i][j]);
       }
       printf("b[%d] = ",i);
       scanf("%f",&a[i][n]);
   }
  
  int divi;
   //convert it into upper triangular Matrix
   for( i=0;i<n;i++){
       for( j=i+1;j<n;j++){
               divi = a[j][i]/a[i][i];
               for( k=i;k<=n;k++){
                   a[j][k]=a[j][k]-(divi*a[i][k]);
                      printf("a[%d][%d] = %f\n",j,k,a[j][k]);
               }
            //   for(int x1=0;x1<n;x1++){
            //       for(int y1=0;y1<n+1;y1++){
            //           printf("%.2f ",a[x1][y1]);
            //       }
            //       printf("\n");
            //   }
       }
   }
   
   x[n-1]=a[n-1][n]/a[n-1][n-1];
   
   for( i=n-2;i>=0;i--){
       float s = 0;
       for( j=i+1;j<n;j++){
           s+=a[i][j]*x[j];
           x[i]=(a[i][n]-s)/a[i][i];
       }
   }
   
   //result
   printf("\nResults......\n");
   for( i=0;i<n;i++){
       printf("x[%d] = %d\n",i+1,x[i]);
   }
   return 0;
}

