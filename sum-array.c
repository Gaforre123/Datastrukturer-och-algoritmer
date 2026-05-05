#include <stdio.h>


int main() {
    int sum = 0;
    int A[] = {10, 10};
    int n = sizeof(A) / sizeof(A[0]);

    for (int i = 0; i < n; i++) {
        sum = sum + A[i];
    }
    printf("%d", sum);
}