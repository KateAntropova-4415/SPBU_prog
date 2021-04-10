// Task 7 задача №6
#include <stdio.h>
#include <stdlib.h>

void Making_Array_C(int* A, int* B, int n, int m);

int main()
{
    int n, m;
    printf("Enter N: ");
    scanf("%i", &n);
    printf("Enter M: ");
    scanf("%i", &m);

    int* A = (int*)malloc(n * sizeof(int));
    int* B = (int*)malloc(m * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        printf("Enter A[%i]: ", i);
        scanf("%i", &A[i]);
    }
    for (int i = 0; i < m; i++) {
        printf("Enter B[%i]: ", i);
        scanf("%i", &B[i]);
    }

    Making_Array_C(A, B, n, m);

    free(A);
    free(B);

    return 0;
}

void Making_Array_C(int* A, int* B, int n, int m) {
    int i = 0, j = 0;
    int* C = (int*)malloc((m + n) * sizeof(int));

    while (i < n || j < m) {
        if (i == n) {
            C[i + j] = B[j];
            j++;
        }
        else if (j == m) {
            C[i + j] = A[i];
            i++;
        }
        else if (A[i] < B[j]) {
            C[i + j] = A[i];
            i++;
        }
        else {
            C[i + j] = B[j];
            j++;
        }
    }

    printf("\nReceived array C: \n");
    for (int i = 0; i < n + m; i++) {
        printf("C[%i]: ", i);
        printf("%i \n", C[i]);
    }
    free(C);
}