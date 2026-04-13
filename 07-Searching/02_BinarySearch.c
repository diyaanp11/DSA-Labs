#include <stdio.h>

int main() {
    int arr[] = {1,2,3,4,5};
    int key = 3;
    int low = 0, high = 4;

    while(low <= high) {
        int mid = (low + high)/2;

        if(arr[mid] == key) {
            printf("Found");
            return 0;
        }
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    printf("Not Found");
}