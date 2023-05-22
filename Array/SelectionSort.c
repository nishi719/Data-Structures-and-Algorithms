#include <stdio.h>

int main() {
    int arr[5] = {5, 4, 3, 2, 1};
    int n = 5; // size of the array
    int i, j, min_idx, temp;

    // perform selection sort
    for(i = 0; i < n - 1; i++) {
        min_idx = i;
        for(j = i+1; j < n; j++) {
            if(arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }

    // print the sorted array
    printf("Sorted array: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
