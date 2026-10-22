/*3. Write a C program to sort a given list of elements using
i.) Bubble Sort
ii.) Selection Sort
iii.) Insertion Sort
*/
#include<stdio.h>
void bubble( int a[100], int n){
int temp;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n -i -1;j++){

            if(a[j]>a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }


        }
    }

}
void selection(int a[100], int n){
    
    int temp;
    int smallest;
    int pos;

    for(int i =0;i<n;i++){
        smallest = a[i];
        pos = i;
        for(int j =i;j<n;j++){
            if(smallest>a[j])
            {
            smallest = a[j];
            pos = j;
            }
                
        }
        temp = a[i];
        a[i] = a[pos];
        a[pos] = temp;

        
    }
}
void insertion(int a[100], int n){
    int k;
    int temp;
    for(int i = 0;i<n;i++){
        k = a[i];
        for(int j = 0;j<i;j++){
            if(k<a[j]){
                temp = a[j];
                a[j] = k;
                k = temp;


            }

        }
    }
}
int main(){

    int n,a[100];

    printf("Enter size of array");
    scanf("%d",&n);

    printf("Enter elements");

    for(int i =0;i<n;i++){

        scanf("%d",&a[i]);


    }

    insertion(a,n);

    printf("sorted array");

    for(int i = 0;i<n;i++){
        printf("%d ",a[i]);
    }
}