// Task 4 задача №6

#include <stdio.h>
#include <stdlib.h>

void cancel(int a, int b, int* p, int* q);

int main()
{
    int a, b, c, d, p, q;

    printf("Enter A and B (with SPACE): ");
    scanf("%d%d", &a, &b);

    printf("Enter C and D (with SPACE): ");
    scanf("%d%d", &c, &d);

    cancel(a * d + b * c, b * d, &p, &q);
    printf("Answer: ");
    printf("%d/%d", p, q);
    return 0;
}

void cancel(int a, int b, int* p, int* q) {
    int a1 = a, b1 = b;
    while (a1 != b1) {
        if (a1 > b1)
            a1 = (a1 - 1) % b1 + 1;
        else b1 = (b1 - 1) % a1 + 1;
    }
    *p = a / a1;
    *q = b / b1;
}