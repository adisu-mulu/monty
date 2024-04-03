#include "monty.h"
/**
 * pop - function
 * @stack: pointer
 * @line_number: integer
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp != NULL)
	{
		*stack = temp->next;
		free(temp);
	}
	else
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		freeStack(stack, line_number);
		exit(EXIT_FAILURE);
	}
}
