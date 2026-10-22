#include <stdio.h>
#include <stdlib.h>

void recursort(int *a,int size , int start){

    if(start>=size-1){
        return;
    }
    else{
        int smallest = *(a + start);
        int temp,pos = start;
        for(int i = start+1;i<size;i++){
            if(smallest>*(a+i)){
               smallest = *(a+i);
               pos = i;
                
            }

        }

        temp = *(a+start);
        *(a+start) = smallest;
        *(a+pos) = temp;

        recursort(a,size,start+1);
    }

}

int main(){

    int size;
    printf("Enter Size of array");
    scanf("%d",&size);
    int *a = (int*)malloc(size*sizeof(int));

    printf("Enter elements");
    for(int i = 0;i<size;i++){
        printf("Element %d: ",(i+1));
        scanf("%d",(a+i));
        printf("\n");

    }
    int start = 0;
    recursort(a,size,start);
    printf("Sorted elements");
    for(int i = 0;i<size;i++){
        printf(" %d ",*(a+i));
    }




}
