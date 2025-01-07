// SORTING

#include <stdio.h>
#include <stdlib.h>

int sotingSection(int arr[] , int N){
   for (int i =0 ; i<N ; i++){
    int min = i;
    for(int j = i+1 ; j<N ; j++){
        if(arr[j]<arr[min]){
            min = j;
        }
    }
    int temp = arr[min];
    arr[min]=arr[i];
    arr[i]=temp;
    
   }
}
int main(){
    int N;
    printf("Enter the size of the array : ");
    scanf("%d",&N);
    int arr[N];
    for(int i = 0 ; i<N ; i++){
        printf("Enter number : ");
        scanf("%d",&arr[i]);
    }
    printf("the array before sorting : ");
    for(int i = 0 ; i<N ; i++){
        printf("%d",arr[i]);
        printf(" , ");
    }
    sotingSection(arr,N);
    printf("\n the array after sorting : ");
    for(int i = 0 ; i<N ; i++){
        printf("%d",arr[i]);
        printf(" , ");
    }                                                                                                                               
    return 0;
}