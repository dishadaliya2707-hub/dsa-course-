#include <stdio.h>

/*
 * Binary Search - Find a number in a given set of values.
 * Prerequisite - The given set of values should be SORTED (ASC/DSC).
 * {22, 24, 30, 35, 40, 45} - Find 37
 * Find a search space -> L=R (L <= R); Mid(M) = L + (R-L)/2;
 */

int binarySearch(int arr[], int size, int key) {
    int left, right, mid;
    left = 0, right = size - 1;

    while (left <= right) {
        mid = left + (right - left) / 2;

        if (key > arr[mid]) {
            left = mid + 1; //right
        } else if (key < arr[mid]) {
            right = mid - 1; //left
        } else {
            return mid; //Found at 'mid' location
        }
    }

    return -1; //Not found
}

int main() {

    int arr[] = {22, 24, 30, 35, 40, 45};
    int key = 20;
    int size = 6;
    int idx = binarySearch(arr, size, key);

    printf("Value at %d", idx);

    return 0;
}