#include <stdio.h>

int main() {
    int arr[] = {10,20,30,40};
    int key = 30;

    for(int i=0;i<4;i++) {
        if(arr[i] == key) {
            printf("Found at index %d", i);
            return 0;
        }
    }
    printf("Not Found");
}