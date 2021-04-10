// Task 9 задача №3 (первая картинка), матрица 9х9 заполняется рандомными числами
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	int Array[9][9];
	int i, j, sum = 0;
	printf("Source martix:\n");
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			Array[i][j] = rand() % 90 + 10;
			printf("%i ", Array[i][j]);
		}
		printf("\n");
	}
	for (i = 0; i < 9; i++)
	{
		if (i < 5)
		{
			for (j = i; j < 9 - i; j++)
			{
				sum += Array[i][j];
			}
		}
		else
		{
			for (j = 8 - i; j <= i; j++)
			{
				sum += Array[i][j];
			}
		}
	}
	printf("\nFinal Summ: %i", sum);

	return 0;
}