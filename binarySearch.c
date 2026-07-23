#include <stdio.h>
/* 
* Binary Search - Find a number in a given set of values .
* Prerequisite - THe given set of variables should be SORTED (ASSENDING / DECENDING)
* {22, 24, 30, 35, 40, 45} - Find 37 ?
* Find a search space => L-M-R (L <= R); Mid(M) = L  + (R-L)/2;
*/
 
int binarySearch(int arr[], int size , int key){
    int left, right, mid;
    left = 0;
    right = size - 1;
    while (left <= right)
    {
        mid = left + (right - left)/2;
        if (arr[mid] == key)
        {
            return mid; // Found at 'mid location 
        }
        else if (arr[mid] < key)
        {
            left = mid + 1; //right
        }ss
        else
        {
            right = mid - 1;  //left
        }
    }
    return -1;  // Not Found
}

int main(){
    int arr[6] = {22, 24, 30, 35, 40, 45};
    int key = 37;
    int size = 6;
    int idx = binarySearch(arr, size, key);
    printf("Value at %d",idx);
    return 0;
}