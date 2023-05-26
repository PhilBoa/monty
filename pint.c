#include"monty.h"

/**
 * pint - print function
 * Description: prints the element at the top of the stack
 * @topptr: points to the top node in the stack
 * @err_flag: a flag which it's value is 0 and will be updated
 * if the stack is empty
*/

void pint(stack_t **topptr, int *err_flag)
{
	if (topptr == NULL)
	{
	*err_flag = 1;
	return;
	}
	printf("%d\n", temp->n);
}
