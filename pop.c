#include"monty.h"

/**
 * pop - delete function
 * Description: Function that delete the top element from the stack
 * @topptr: pointer to the top node in the stack
 * @err_flag: a flag that it's value is 0 and will be updated
 *				if the stack is empty
*/

void pop(stack_t **topptr, int *err_flag)
{
	stack_t *temp;

	temp = *topptr;
	if (temp == NULL)
	{
	*err_flag = 1;
	return;
	}
	*topptr = temp->prev;
	if (*topptr != NULL)
	(*topptr)->next = NULL;
	free(temp);
}
