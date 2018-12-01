#include "stdafx.hpp"
#include "Fibonacci.hpp"

void Fibonacci()
{
    const int index = 35;
    clock_t start, finish;
    
    start = clock();  // time starts
    for (int i = index; i <= index + 5; i++)  // check Fibonacci numbers from the 35th to 40th
    {
        fprintf(stdout, "Result of normal way of the %dth number: %llu\n", i, Fib_normal(i));
    }
    finish = clock();  // time ends
    float totalTime = (float)(finish - start) / CLOCKS_PER_SEC;  // calculate time used in seconds
    fprintf(stdout, "%f seconds used to for normal way to finish calculation\n", totalTime);
    
    fprintf(stdout, "\n");
    fprintf(stdout, "\n");
    
    start = clock();  // time starts
    for (int i = index; i <= index + 5; i++)  // check Fibonacci numbers from the 35th to 40th
    {
        fprintf(stdout, "Resuslt of sliding way of the %dth number: %llu\n", i, Fib_sliding(i));
    }
    finish = clock();  // time ends
    totalTime = (float)(finish - start) / CLOCKS_PER_SEC;  // calculate time used in seconds
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
        /*
         * SIZE == 3 here
         * | (current_index - 2) % SIZE | (current_index - 1) % SIZE | current_index % SIZE |
         * | current_index % SIZE | (current_index - 2) % SIZE | (current_index - 1) % SIZE |
         * | (current_index - 1) % SIZE | current_index % SIZE | (current_index - 2) % SIZE |
         */
        int temp[SIZE] = { 1, 1, 2 };
        for (int current_index = 2; current_index <= index; current_index++)
            temp[current_index % SIZE] = temp[(current_index - 1) % SIZE] + temp[(current_index - 2) % SIZE];
        return temp[(index - 1) % SIZE];
    }
}
