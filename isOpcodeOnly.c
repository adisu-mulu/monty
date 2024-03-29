#include "monty.h"
/**
 * isOpcodeOnly - function
 * @str: character
 * Return: 0 or 1
 */
int isOpcodeOnly(const char *str)
{
	while (*str)
	{
		if (*str == ' ')
			return (0);
		str++;
	}
	return (1);
}
