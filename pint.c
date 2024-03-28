#include "monty.h"
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if(temp != NULL)
		printf("%d\n", temp->n);
	else
	{
		fprintf(stderr, "L<%d>: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}
