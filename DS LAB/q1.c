//1. Given an array of n integers and a key element, write a C program to search the element
//using linear search.

#include<stdio.h>

int main(){
int n,a[50],ele;
printf("Enter Size of Array");
scanf("%d",&n);



printf("Enter Elements");

for(int i = 0;i<n;i++){
    scanf("%d",a + i);
}

printf("Enter search element");
scanf("%d",&ele);

for(int i = 0;i<n;i++){
    if(*(a+i)==ele){
        printf("Element found at pos %d ",(i+1));
    }
}






}