//  C program for implementation of quick sort
#include <stdio.h>
void swap(int* a, int* b);

// Partition function to place the pivot element at its correct position
int partition(int arr[], int low, int high) {

    // Choosing the last element as pivot
    int pivot = arr[high];

    // Index of smaller element and indicates the right position of pivot found so far
    int i = (low - 1); 

    // Traverse arr[low...high] and move all saller elements to the left side 
    //Elements from low to i are smaller after every iteration
    for (int j = low; j < high - 1; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++; // Increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }

    // Move pivot after smaler elements and return its position
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// The Qicksort function implementation 
void quickSort(int arr[], int low, int high) {
    if (low < high) {

        // pi is the partition return index of pivot
        int pi = partition(arr, low, high);

        // Recursion calls for smaller elements and greater or equal elements
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main() {
    int arr[] = {10, 7, 8, 9, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}