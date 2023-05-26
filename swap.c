#include"monty.h"

/**
 * swap - swap function
 * Description: Function that swaps the top two elements in the stack
 * @topptr: pointer to the top node in the stack
 * @err_flag: a flag that it's value is 0 and will be updated
 *				if the stack is empty
*/

void swap(stack_t **topptr, int *err_flag)
{
	int temp;

	if (*topptr == NULL || (*topptr)->prev == NULL)
	{
	*err_flag = 1;
	return;
	}
	temp = (*topptr)->n;
	(*topptr)->n = (*topptr)->prev->n;
	(*topptr)->prev->n = temp;
}
