#ifndef _FIBONACCI_H_
#define _FIBONACCI_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3

unsigned long long Fib_normal(const int index); // Calculate Fibonacci number in recursive method
unsigned long long Fib_sliding(const int index);  // Calculate Fibonacci number in sliding-array method
void Fibonacci();

#endif
