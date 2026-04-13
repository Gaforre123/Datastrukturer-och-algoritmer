#include <stdio.h>

int main() {
    int array[] = {5, 10, 2, 1, 6, 9, 8, 7, 3, 4};
    int n = sizeof(array) / sizeof(array[0]);

    for (int i = 1; i < n; i++) {
        int key = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }

        array[j + 1] = key;
    }

    printf("array = (");
    for (int i = 0; i < n; i++) {
        printf("%d", array[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf(")\n");

    return 0;
}