#include "monty.h"
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	if(temp != NULL)
	{
		*stack = temp->next;
		free(temp);
	}
	else printf("L<%d>: can't pop an empty stack\n", line_number);
}
