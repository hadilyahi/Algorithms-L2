#include <stdio.h>

void bubble_sort_basic(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j + 1]) {
               
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main() {
    int n;
    printf("Enter the number of array: "); 
    scanf("%d", &n);

    int arr[n];
    printf("Complete the array\n");  
    for (int i = 0; i < n; i++) {
        printf("The element%d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    bubble_sort_basic(arr, n);  

    printf("The array final : ");  
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);  
    }
    printf("\n");

    return 0;
}