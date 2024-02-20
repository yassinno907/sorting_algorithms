#include "sort.h"
/**
* bubble_sort - function that sorts array of integers
* order using Bubble sort alg
* @array: array of int
* @size: size of the array
*/
void bubble_sort(int *array, size_t size)
{
size_t n;
int temp, sorted;
if (!array || size == 0)
return;
do {
sorted = 1;
for (n = 0; n < size - 1; n++)
{
if (array[n] > array[n + 1])
{
sorted = 0;
temp = array[n];
array[n] = array[n + 1];
array[n + 1] = temp;
print_array(array, size);
}
}
} 
while (sorted == 0);
}
