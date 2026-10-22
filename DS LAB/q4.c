#include <stdio.h>
#include <stdlib.h>

void sort(int *n, int size){

    int smallest = *(n + 0);
    for(int i = 1;i<size;i++){
        if(smallest>*(n+i)){
            smallest = *(n+i);
        }
    }

    printf("Smallest value is %d", smallest);
}
int main(){

    int n =0;
    
    printf("Enter size of array");
    scanf("%d",&n);
    int *ele = (int*)malloc(n*sizeof(int));
    printf("Enter elements");
    for( int i = 0;i<n;i++){
        printf("Element %d: ",i);
        scanf("%d",(ele +i));
    }

    sort(ele,n);
}
