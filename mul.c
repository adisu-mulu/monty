#include "monty.h"
/**
 * _mul - function
 * @stack: pointer
 * @line_number: integer
 * Return: void
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	stack_t *temp2 = *stack;
	int count = 0;
	int value;

	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		freeStack(stack, line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		while (temp != NULL)
		{
			temp = temp->next;
			count++;
		}
		if (count < 2)
		{
			fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
			freeStack(stack, line_number);
			exit(EXIT_FAILURE);

		}
		else
		{
			value = temp2->n;
			temp2->next->n = temp2->next->n * value;
			*stack = temp2->next;
			free(temp2);
		}
	}
}
