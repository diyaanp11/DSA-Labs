#include <stdio.h>

void quick(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[low];
        int i = low + 1, j = high;

        while (i <= j) {
            while (arr[i] <= pivot) i++;
            while (arr[j] > pivot) j--;
            if (i < j) {
                int t = arr[i]; arr[i] = arr[j]; arr[j] = t;
            }
        }
        arr[low] = arr[j];
        arr[j] = pivot;

        quick(arr, low, j-1);
        quick(arr, j+1, high);
    }
}

int main() {
    int arr[] = {5,2,9,1,3};
    int n = 5;

    quick(arr, 0, n-1);

    for(int i=0;i<n;i++)
        printf("%d ", arr[i]);

    return 0;
}