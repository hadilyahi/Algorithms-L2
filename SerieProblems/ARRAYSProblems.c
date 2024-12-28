// ARRAYS
#include <stdio.h>

int main(){

    // problem 1 : Write a program to store 5 integers in an array and print them.
    int arr[5] ;
    for(int i=0 ; i<5 ; i++ ){
        printf("Enter number : ");
        scanf("%d",&arr[i]);
        
    }
     printf("The array : ");
    for(int i =0 ; i<5 ; i++){
        printf("%d",arr[i]);
        printf(" , ");
    }
    //////////////////////////////////////////////////////////
    // problem 2 : Write a program to find the largest and smallest elements in an array.
    int i ,min , max;
         min = arr [0];
    for( i = 0 ; i<5 ; i++){
            if(arr[i]<min){
                min = arr[i];
            }
            if(arr[i]>max){
                max = arr[i];
            }  
    }
        printf("The smallest is : %d \n",min);
        printf("The Largest is : %d",max);
    //////////////////////////////////////////////
    // problem 3 : Write a program to calculate the sum and average of elements in an array. 
    int sum = 0 ;
    for(int i = 0 ; i<5 ; i++){
        sum = sum + arr[i];
    }
    printf("The sum is : %d \n",sum);
    printf("The average is : %d \n",sum/2);
    //////////////////////////////////////////////////////
    // problem 4 : Write a program to reverse an array.
    int temp ;
    for(int i = 0 ; i<5/2 ; i++){
        temp = arr[i];
        arr[i] = arr[5-i-1];
        arr[5-i-1] = temp; }
    for(int i = 0 ; i<5 ; i++){
        printf("%d",arr[i]);
        printf(" , ");
    }
    //////////////////////////////////////////////////////
    // problem 5 : Write a program to merge two arrays into a single array.
     int arr1[5] , arr2[5] , arr3[10];
        for(int i = 0 ; i<5 ; i++){
            printf("Enter number in array 1 : ");
            scanf("%d",&arr1[i]);
            }
        for(int i = 0 ; i<5 ; i++){
            printf("Enter number in array 2 : ");
            scanf("%d",&arr2[i]);
            }
        for(int i = 0 ; i<5 ; i++){
            arr3[i] = arr1[i];
            arr3[i+5] = arr2[i];
        }
        printf("The array Finall : ");
        for(int i = 0 ; i<10 ; i++){
            printf("%d",arr3[i]);
            printf(" , ");
        }
        
      return 0;
}