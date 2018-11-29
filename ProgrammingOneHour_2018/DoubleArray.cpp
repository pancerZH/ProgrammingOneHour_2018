#include "stdafx.h"
#include "DoubleArray.h"

int capacity;
int currentSize;
int* array;

void Double_array()
{
	init();
	for (int i = 1; i <= NUM; i++)
	{
		Add_element(i);
	}
	Show_array();
}

bool init()
{
	capacity = 10;
	currentSize = 0;
	array = (int*)malloc(capacity * sizeof(int));
	if (array == NULL)
	{
		fprintf(stderr, "Failed to malloc long enough array\n");
		exit(1);
	}
	return true;
}

bool Add_element(const int elem)
{
	if (currentSize == capacity)  // need more space!
	{
		capacity *= RATE;
		int* newArr = (int*)malloc(capacity * sizeof(int));  // create a new array with a doubled size
		if (newArr == NULL)
		{
			fprintf(stderr, "Failed to malloc long enough array\n");
			exit(1);
		}

		for (int i = 0; i < currentSize; i++)
			*(newArr + i) = *(array + i);

		free(array);
		array = newArr;
		Show_array();
	}

	// then we can add the new element into our array
	*(array + currentSize) = elem;
	currentSize++;

	return true;
}

void Show_array()
{
	fprintf(stdout, "\n");
	fprintf(stdout, "Array capacity:\t\t%d\n", capacity);
	fprintf(stdout, "Current array length:\t%d\n", currentSize);
	fprintf(stdout, "Head of array:\t\t%d\n", *(array));
	fprintf(stdout, "Tail of array:\t\t%d\n", *(array + currentSize - 1));
	fprintf(stdout, "\n");
}