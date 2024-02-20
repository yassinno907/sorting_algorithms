#include "sort.h"
#include <stdio.h>

/**
* _swap - swap two vars.
* @array: the array for swap him values.
* @i: First index
* @j: Second index
*/

void _swap(int *array, int i, int j)
{
int cmp;
if (array[i] != array[j])
{
cmp = array[i];
array[i] = array[j];
array[j] = cmp;
}
}

/**
* shell_sort - func that sort the list and print the changes
* @array: The array to sort.
* @size: Size of the array
*/

void shell_sort(int *array, size_t size)
{
size_t e = 0,  a, b;
if (size < 2)
return;
while (e <= size / 3)
e = e * 3 + 1;
while (e >= 1)
{
for (a = e; a < size; a++)
for (b = a; b >= e && array[b] < array[b - e]; b -= e)
_swap(array, b, b - e);
e /= 3;
print_array(array, size);
}
}
