#include <stdio.h>

int main() {
    int arr[5] = {5, 4, 3, 2, 1};
    int n = 5; // size of the array
    int i, j, key;

    // perform insertion sort
    for(i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    }

    // print the sorted array
    printf("Sorted array: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
