#include "stdafx.h"
#include "Fibonacci.h"

void Fibonacci()
{
	const int index = 35;
	clock_t start, finish;

	start = clock();
	for (int i = index; i <= index + 5; i++)
	{
		fprintf(stdout, "Result of normal way of the %dth number: %llu\n", i, Fib_normal(i));
	}
	finish = clock();
	float totalTime = (float)(finish - start) / CLOCKS_PER_SEC;
	fprintf(stdout, "%f seconds used to for normal way to finish calculation\n", totalTime);

	fprintf(stdout, "\n");
	fprintf(stdout, "\n");

	start = clock();
	for (int i = index; i <= index + 5; i++)
	{
		fprintf(stdout, "Resuslt of sliding way of the %dth number: %llu\n", i, Fib_sliding(i));
	}
	finish = clock();
	totalTime = (float)(finish - start) / CLOCKS_PER_SEC;
	fprintf(stdout, "%f seconds used to for sliding way to finish calculation\n", totalTime);
}

unsigned long long Fib_normal(const int index)
{
	if (index <= 0)
	{
		fprintf(stderr, "Wrong number %d entered!\n", index);
		exit(1);
	}

	if (index == 1 || index == 2)
		return 1;
	else
		return Fib_normal(index - 1) + Fib_normal(index - 2);
}

unsigned long long Fib_sliding(const int index)
{
	if (index <= 0)
	{
		fprintf(stderr, "Wrong number %d entered!\n", index);
		exit(1);
	}

	if (index == 1 || index == 2)
		return 1;
	else
	{
		int temp[3] = { 1, 1, 2 };
		for (int current_index = 2; current_index <= index; current_index++)
			temp[current_index%SIZE] = temp[(current_index - 1) % SIZE] + temp[(current_index - 2) % SIZE];
		return temp[(index - 1) % SIZE];
	}
}