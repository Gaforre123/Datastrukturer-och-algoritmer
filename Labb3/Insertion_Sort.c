#include <stdlib.h>
#include <stdio.h>
#include "load_file/load_file.h"

void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // i = 1, j = 0 
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main() {
   /*
    int L1[] = {3, 1, 5, 10, 8, 7};
    int L2[] = {5, 2, 9, 6, 1, 2};
    int pn[] = {1, 9, 6, 3, 1, 2, 1, 1, 1, 6, 5, 8};

    insertion_sort(L1, 6);
    for (int i = 0; i < 6; i++) {
        printf("%d, ", L1[i]);
    }

    puts("\n");
    insertion_sort(L2, 6);
    for (int i = 0; i < 6; i++) {
        printf("%d, ", L2[i]);
    }
    
    puts("\n");
    insertion_sort(pn, 12);
    for (int i = 0; i < 12; i++) {
        printf("%d, ", pn[i]);
    }
    */
   int *data = load_file("sorting_problems/test-10-problem");
    int n = data[0];

    // Viktigt: data + 1
    insertion_sort(data + 1, n);

    printf("Sorterad lista:\n");
    for (int i = 1; i <= n; i++) {
        printf("%d ", data[i]);
    }

    printf("\n");

    free(data);
    return 0;
}