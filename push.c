#include "monty.h"
/**
 * push_function - function
 * @stack: pointer
 * @line_number: integer
 * Return: void
 */
void push_function(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		freeStack(stack, line_number);
		exit(EXIT_FAILURE);
	}
	new_node->n = data;

	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;

	if (line_number > 0)
	{}
}
