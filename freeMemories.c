#include "monty.h"
void freeStack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	stack_t *currentNode = *stack;
	while (currentNode != NULL)
	{
		temp = currentNode;
		currentNode = currentNode->next;
		free(temp);
	}
	if (line_number > 0)
	{}
}
