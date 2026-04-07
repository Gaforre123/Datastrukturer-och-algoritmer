#include <stdio.h>

int main() {    
    int A[] = {4, 3, 1, 7, 2};
    int temp;
    int j;
    int n = 0;
    
    printf("skriv hur många tal för arrayen: ");
    scanf("%d",&n);

    for (int i = 0; i < n; i++){
        printf("A[%d] = ", i);
        scanf("%d", &A[i]);
    }
    
    

    for (int i = 1; i < n; i++) {
        temp = A[i]; //3
        j = i - 1; // j = 0 och har värde 4
        //om 0 >= 0 och 4 > 3
        while (j >= 0 && A[j] > temp)
        {
        // A[1] = A[0] alltså man flyttar 
        // så 3 hamnar på rutan för nummer 4
            A[j + 1] = A[j];
        // minskar vi j så den blir -1 = 0 -1
            j = j - 1;
        //den bryts för j = -1
        }

        A[j + 1] = temp;
        
    }


    for (int i = 0; i < n; i++)
    {
        printf("A[%d] = %d\n", i, A[i]);
    }
    
}