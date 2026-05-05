#include <stdio.h>


int main () {
    int array[] = {10, 21, 2, 7, 3, 44, 32};
    int n = sizeof(array) / sizeof(array[0]);

    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++) {
            if (array[j] < array[i]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }   
        }   
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}