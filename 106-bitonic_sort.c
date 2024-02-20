#include "sort.h"

/**
 * swap - change two values in ascending or not
 * @arr: array
 * @item1: item one
 * @item2: item two
 * @order: 1: ascending 0 descending order
 */
void swap(int arr[], int item1, int item2, int order)
{
int temp;
if (order == (arr[item1] > arr[item2]))
{
temp = arr[item1];
arr[item1] = arr[item2];
arr[item2] = temp;
}
}
/**
 * merge - func that sorts bitonic sequences
 * @arr: array
 * @low: first element
 * @nelemnt: elements number
 * @order: 1: ascending order, 0 descending order
 */
void merge(int arr[], int low, int nelemnt, int order)
{
int mid, i;
if (nelemnt > 1)
{
mid = nelemnt / 2;
for (i = low; i < low + mid; i++)
swap(arr, i, i + mid, order);
merge(arr, low, mid, order);
merge(arr, low + mid, mid, order);
}
}
/**
 * bitonicsort - func bitonic sort algorithm
 * @arr: array
 * @low: first element
 * @nelemnt: number of elements
 * @order: 1: ascending order, 0 descending order
 * @size: array lenght
 */
void bitonicsort(int arr[], int low, int nelemnt, int order, int size)
{
int mid;
if (nelemnt > 1)
{
if (order >= 1)
{
printf("Merging [%i/%i] (UP):\n", nelemnt, size);
print_array(&arr[low], nelemnt);
}
else
{
printf("Merging [%i/%i] (DOWN):\n", nelemnt, size);
print_array(&arr[low], nelemnt);
}
mid = nelemnt / 2;
bitonicsort(arr, low, mid, 1, size);
bitonicsort(arr, low + mid, mid, 0, size);
merge(arr, low, nelemnt, order);
if (order <= 0)
{
printf("Result [%i/%i] (DOWN):\n", nelemnt, size);
print_array(&arr[low], nelemnt);
}
if (order >= 1)
{
printf("Result [%i/%i] (UP):\n", nelemnt, size);
print_array(&arr[low], nelemnt);
}
}

