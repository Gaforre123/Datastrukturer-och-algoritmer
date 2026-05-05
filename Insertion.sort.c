#include <stdio.h>

int main() {
    int array[] = {31, 41, 59, 26, 41, 58};
    int n = sizeof(array) / sizeof(array[0]);

    for (int i = 1; i < n; i++) {
        int key = array[i];
        int j = i - 1;
        // < bestämmer om det är minsta/största värde är till vänster
        while (j >= 0 && array[j] < key) {
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