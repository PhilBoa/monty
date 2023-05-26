#include "monty.h"

void free_stack(stack_t *head)
{
	while (head != NULL)
	{
	stack_t *temp = head;
	head = head->next;
	free(temp);
	}
}
