#include <stdio.h>
#include "load_file.h"

void merge(int arr[], int l, int m, int r) {
    int temp[1000];
    int i = l, j = m + 1, k = l;

    while (i <= m && j <= r) {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= m)
        temp[k++] = arr[i++];

    while (j <= r)
        temp[k++] = arr[j++];

    for (int x = l; x <= r; x++)
        arr[x] = temp[x];
}

void merge_sort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
   
    /*
    int L1[] = {3, 1, 5, 10, 8, 7};
    int L2[] = {5, 2, 9, 6, 1, 2};
    int pn[] = {1, 9, 6, 3, 1, 2, 1, 1, 1, 6, 5, 8};

    merge_sort(L1,0,5);
    for (int i = 0; i < 6; i++) {
        printf("%d, ", L1[i]);
    }

    puts("\n");
    merge_sort(L2,0,5);
    for (int i = 0; i < 6; i++) {
        printf("%d, ", L2[i]);
    }
    puts("\n");
    merge_sort(pn,0,11);
    for (int i = 0; i < 12; i++) {
        printf("%d, ", pn[i]);
    }
     */
     
     
    int *data = load_file("sorting_problems/test-10-1-problem");
    int n = data[0];
    merge_sort(data + 1, 0, n - 1);
    for (int i = 1; i <= n; i++) {
    printf("%d ", data[i]);
    }
   
}

//Vid ändring av problem krävs det att man ändrar gcc 
//gcc gcc Merge_Sort.c load_file.c -o Merge_Sort.exe