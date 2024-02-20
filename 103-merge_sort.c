#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
* copy - func that copi data from buffer
* @src: source buffer
* @dst: destination buffer
* @size: size of buffers
*/

void copy(int *src, int *dst, int size)
{
int a;
for (a = 0; a < size; a++)
dst[a] = src[a];
}

/**
* merge - func merges two sets of data
* but they must already be sorted
* @array: first set of daatas
* @buff: second set of data
* @minL: lower range of 1st
* @maxL: upper range of 1st
* @minR: lower range of sec set of data
* @maxR: upper range of sec
*/

void merge(int *array, int *buff, int minL, int maxL, int minR, int maxR)
{
int i = minL, j = minR, k = minL;
while (i <= maxL || j <= maxR)
if (i <= maxL && j <= maxR)
if (buff[i] <= buff[j])
array[k] = buff[i], k++, i++;
else
array[k] = buff[j], k++, j++;
else if (i > maxL && j <= maxR)
array[k] = buff[j], k++, j++;
else
array[k] = buff[i], k++, i++;
}

/**
* printcheck - func that prints an array
* @array: array of data to be print
* @r1: start of range
* @r2: final of range
*/

void printcheck(int *array, int r1, int r2)
{
int a;
for (a = r1; a <= r2; a++)
{
if (a > r1)
printf(", ");
printf("%d", array[a]);
}
printf("\n");
}

/**
* split - func that split data
* @array: array of data to be split
* @buff: auxiliary array for mrg
* @min: min range of data in array
* @max: max range of data in array
* @size: size of total data
*/

void split(int *array, int *buff, int min, int max, int size)
{
int mid, tmax, minL, maxL, minR, maxR;
if ((max - min) <= 0)
return;
mid = (max + min + 1) / 2;
tmax = max;
max = mid - 1;
minL = min;
maxL = max;
split(array, buff, min, max, size);
min = mid;
max = tmax;
minR = min;
maxR = max;
split(array, buff, min, max, size);
printf("Merging...\n");
printf("[left]: ");
printcheck(array, minL, maxL);
printf("[right]: ");
printcheck(array, minR, maxR);
merge(array, buff, minL, maxL, minR, maxR);
copy(array, buff, size);
printf("[Done]: ");
printcheck(array, minL, maxR);
}

/**
* merge_sort - func that sorts an array of integers ascending order
* @array: array of data to be sorted
* @size: size of data
*/

void merge_sort(int *array, size_t size)
{
int *buff;
if (size < 2)
return;
buff = malloc(sizeof(int) * size);
if (buff == NULL)
return;
copy(array, buff, size);
split(array, buff, 0, size - 1, size);
free(buff);
}
