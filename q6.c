#include <stdio.h>
#include <stdlib.h>

void readmatrix(int **a, int n, int m){
    printf("Enter Elements");

    for(int i = 0;i<n;i++){
        *(a + i) = (int *)malloc(m*sizeof(int));
        for(int j = 0;j<m;j++){
            scanf("%d",(*(a + i)+j));
        }
    }
}

void multiply(int**c,int**a, int**b,int n, int m,int c1){
    for(int i = 0;i<n;i++){
        *(c + i) = (int *)malloc(c1 * sizeof(int));
        for(int j = 0;j<c1;j++){
            *(*(c+i)+j) = 0;
            for(int k = 0;k<m;k++){
                *(*(c+i)+j) += *(*(a + i)+k) **(*(b + k)+j);

            }

        }
    }
}

int main(){
    int n,m;
    printf("Enter row coloum matrix a");
    scanf("%d",&n);
    scanf("%d",&m);

    int **a = (int**)malloc(n * sizeof(int*));

    readmatrix(a,n,m);
        int **b = (int**)malloc(m * sizeof(int*));

    readmatrix(b,m,m);

        int **c = (int**)malloc(n * sizeof(int*));

        multiply(c,a,b,n,m,m);



    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            printf("%d",*(*(c + i)+j));
        }
    }

    



    



}