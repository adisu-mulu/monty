#include "monty.h"
/**
 * pall - function
 * @stack: pointer to stack
 * @line_number: line number
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	if (line_number > 0)
	{}
}
