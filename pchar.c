#include "monty.h"
/**
 * pchar - function
 * @stack: pointer
 * @line_number: integer
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp != NULL)
	{
		if (temp->n >= 0 && temp->n <= 127)
			printf("%c\n", (char)temp->n);
		else
		{
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
			freeStack(stack, line_number);
			exit(EXIT_FAILURE);
		}
			
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		freeStack(stack, line_number);
		exit(EXIT_FAILURE);
	}
}
