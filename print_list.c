#include <stdio.h>
#include "sort.h"

/**
 * print_list - func that Prints a list of integs
 * @list: The list to be printed in func
 */
void print_list(const listint_t *list)
{
int i;
i = 0;
while (list)
{
if (i > 0)
printf(", ");
printf("%d", list->n);
++i;
list = list->next;
}
printf("\n");
}
