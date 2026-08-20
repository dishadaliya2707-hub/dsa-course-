#include<stdio.h>
/*
* Quick Sort: What is sorting? - Arrange in ASC/DSC order . - time o(n) and space o(logn)
* 0, 3, 7, 6, 1, 9, 2 - Unsorted
* t                 H
* 1. Pick a pivot - any arbitary value. Ex: 2
* 2. Place '2' at its 'appropriate' position .
* 3. 0, 1, '2', 6, 3, 9, 7
* 4. Pivot: 7
* 5. 1, 0, '2', 3, 6, '7', 9
* 6. Pivot: 1
* 7. 0, '1', '2', 3, 6, '7', 9
* 8. SORTED 
*/

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];

    int i = low - 1;
    int j;
    for(i=low; i<=high-1; i++){
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return i+1; // Pivot
}

void quickSort(int arr[], int low, int high){
    if (low < high) {
        int pivot = partition(arr, low, high);

        quickSort(arr, low, pivot-1);
        quickSort(arr, pivot+1, high);
    }
}

int main() {
    int arr[] = {0, 3, 7, 6, 1, 9, 2};

    int size = sizeof(arr)/sizeof(int);
    int i;
    quickSort(arr, 0, size-1);

    for (i=0; i<size; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");
    return 0;
}