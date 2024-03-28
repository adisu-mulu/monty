#include "monty.h"
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	if(temp != NULL)
	{
		*stack = temp->prev;
		*(temp)->next = NULL;
		free(temp);
	}
	else
	{
		fprintf(stderr, "L<%d>: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
}
