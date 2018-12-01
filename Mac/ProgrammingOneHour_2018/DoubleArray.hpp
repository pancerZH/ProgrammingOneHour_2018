#ifndef _DOUBLE_ARRAY_H_
#define _DOUBLE_ARRAY_H_

#include <stdio.h>
#include <stdlib.h>

#define RATE 2
#define NUM 10000

extern int capacity;
extern int currentSize;
extern int* array;

void Double_array();
bool init();
bool Add_element(const int elem);
void Show_array();

#endif
