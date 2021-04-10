// Task 5 задача №1

#include <stdio.h>
#include <stdlib.h>

int sum = 0;
void Recursion(int N);

int main()
{
	int N;
	printf("Enter N: ");
	scanf("%d", &N);
	Recursion(N);
	return 0;
}

void Recursion(int N)
{
	sum += N % 10;
	N = N / 10;
	if (N > 0)
		Recursion(N);
	else printf("Answer: %d", sum);	
}