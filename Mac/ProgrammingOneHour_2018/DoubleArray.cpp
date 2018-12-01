#include "stdafx.hpp"
#include "DoubleArray.hpp"

int capacity;
int currentSize;
int* array;

void Double_array()
{
    init();
    for (int i = 1; i <= NUM; i++)  // test: add elements in the number of NUM
    {
        Add_element(i);
    }
    Show_array();
    
    free(array);  // we hd better release the space of array after finishing
}

bool init()
{
    capacity = 10;
    currentSize = 0;
    array = (int*)malloc(capacity * sizeof(int));
    if (array == NULL)  // check if malloc succeeded
    {
        fprintf(stderr, "Failed to malloc space big enough\n");
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
        if (newArr == NULL)  // check if malloc succeeded
        {
            fprintf(stderr, "Failed to malloc space big enough\n");
            exit(1);
        }
        
        for (int i = 0; i < currentSize; i++)  // copy data from the old array to the new one
            *(newArr + i) = *(array + i);
        
        free(array);  // release the space of old array
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
