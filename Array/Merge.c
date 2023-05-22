#include <stdio.h>

int main() {
    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[5] = {6, 7, 8, 9, 10};
    int n1 = 5, n2 = 5; // sizes of the arrays
    int i, j, k;
    int arr3[10]; // new array for merged elements
    
    // merge the arrays
    i = j = k = 0;
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            arr3[k++] = arr1[i++];
        } else {
            arr3[k++] = arr2[j++];
        }
    }

    // copy the remaining elements of arr1, if any
    while (i < n1) {
        arr3[k++] = arr1[i++];
    }

    // copy the remaining elements of arr2, if any
    while (j < n2) {
        arr3[k++] = arr2[j++];
    }

    // print the merged elements
    printf("Merged array elements: ");
    for(i = 0; i < n1 + n2; i++) {
        printf("%d ", arr3[i]);
    }

    return 0;
}
