#include <stdio.h>

void merge(int tab[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;
    int temp[right - left + 1]; 

    while (i <= mid && j <= right) {
        if (tab[i] < tab[j]) {
            temp[k - left] = tab[i]; 
            k++;
            i++;
        } else {
            temp[k - left] = tab[j]; 
            k++;
            j++;
        }
    }

    while (i <= mid) {
        temp[k - left] = tab[i]; 
        k++;
        i++;
    }

    while (j <= right) {
        temp[k - left] = tab[j]; 
        k++;
        j++;
    }

  
    for (int m = left; m <= right; m++) {
        tab[m] = temp[m - left]; 
    }
}

int main() {
    int i;
    int tab[] = {6, 8, 9, 2, 10, 11};
    
    
    merge(tab, 0, 2, 5); 
    

    for (i = 0; i <= 5; i++) {
        printf("array[%d]: %d\n", i, tab[i]);
    }

    return 0;
}
