//2. Given an array of integers, implement binary search to find the position of a given key.

#include <stdio.h>
int main(){
int low, high,key,a[100],n,mid,flag =0;

printf("Enter the number of elements");
scanf("%d",&n);

printf("Enter Array elements");

for(int i = 0; i<n ;i++){
    scanf("%d",a + i);
}

//sort it
int temp;
for(int i = 0;i<n;i++){
    for(int j = i;j<n;j++){
    if(*(a + i)>*(a + j))
        {
            temp = *(a + i);
            *(a + i)= *(a + j);
            *(a + j) = temp;
        }
        
        
    }
    
}

printf("Enter Number to be found");
scanf("%d",&key);

low = 0;
high = n-1;


while((low<=high)){
    mid = low +(high - low)/2;

    if(*(a + mid)==key){
        printf("Found at Position %d ",mid+1);
        break;
    }
    else if(*(a + mid)< key){
        low = mid+1;

    }
    else{
        high = mid-1;
    }


}




}