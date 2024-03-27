#include "monty.h"
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	while (temp != NULL)
	{
		printf("\n%d", temp->n);
		temp = temp->next;
	}
	printf("\n");
}
