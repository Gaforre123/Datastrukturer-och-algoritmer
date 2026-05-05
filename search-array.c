#include <stdio.h>
#include <stdbool.h>

int main() {
    int x;
    int n;
    bool a = false;
    printf("Write how many elements for the array ");
    scanf("%d", &n);
    int array[n];
    printf("write the vaule on each element \n");
    for (int i = 0; i < n; i++) {
        printf("array[%d] =  ",i);
        scanf("%d", &array[i]);
    }
    
    printf("skriv siffra du söker efter");
    scanf("%d", &x);
    
    for (int i = 0; i < n; i++){
        if (x == array[i])
        {
          printf("%d",i);  
          return 0;
        }

    }
    printf("-1");
    return 1;

}