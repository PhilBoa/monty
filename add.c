#include "monty.h"

void f_add(stack_t **head, unsigned int counter)
{
	if (*head == NULL || (*head)->next == NULL)
	{
	fprintf(stderr, "L%d: can't add, stack too short\n", counter);
	fclose(bus.file);
	free(bus.content);
	free_stack(*head);
	exit(EXIT_FAILURE);
	}

	stack_t *first = *head;
	stack_t *second = (*head)->next;
	int sum = first->n + second->n;

	second->n = sum;
	*head = second;
	free(first);
}

