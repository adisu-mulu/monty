#include "monty.h"
void pint(stack_t **stack, unsigned int line_number)
{
	if(*stack != NULL)
		printf("%d\n", temp->n);
	else
	{
		fprintf(stderr, "L<%d>: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}
