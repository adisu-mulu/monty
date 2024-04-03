#include "monty.h"
/**
 * pstr - function
 * @stack: pointer
 * @line_number: integer
 * Return: void
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp == NULL)
		printf("\n");
	else
	{

		while (temp != NULL)
		{
			if (temp->n > 0 && temp->n <= 127)
			{
				printf("%c", (char)temp->n);
				temp = temp->next;
			}
			else
				break;
		}
		printf("\n");
	}
	if (line_number > 0)
	{}
}
