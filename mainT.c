#include "monty.h"
/**
 * main - function
 * @argc: arguement
 * @argv: arguement
 * Return: success
 */
int data;
int main(int argc, char *argv[])
{
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
	}
	else
	{
		process_file(file);
	}

	fclose(file);
	return (0);
}

/**
 * process_file - function
 * @file: file pointer
 * Return: void
 */
void process_file(FILE *file)
{
	char buffer[50],  *token;
	int opcodeValid, line_number, count;
	stack_t *stack;
	char opcode[10],  data_part[100];
	size_t len;

	line_number = 0;
	stack = NULL;
	while (fgets(buffer, sizeof(buffer), file) != NULL)
	{
		if (strlen(buffer) - 1 == 0)
		{
			line_number++;
			continue;
		}
		memset(opcode, '\0', sizeof(opcode));
		memset(data_part, '\0', sizeof(data_part));
		opcodeValid = 0;

		if (isOpcodeOnly(buffer))
		{
			strcpy(opcode, buffer);
			len = strlen(opcode);

			if (len > 0 && opcode[len - 1] == '\n')
				opcode[len - 1] = '\0';
		}
		else
		{
			token = strtok(buffer, " ");
			if (token != NULL)
				strcpy(opcode, token);
			token = strtok(NULL, " ");
			if (token != NULL)
				strcpy(data_part, token);
		}
		execute_operation(opcode, data_part, opcodeValid, ++line_number, &stack);
	}
	freeStack(&stack, 1);
}
/**
 * execute_operation - function
 * @opcode: opcode
 * @data_part: data part
 * @opcodeValid: checks if opcode is valid
 * @line_number: tracks line number
 * @stack: pointer to the stack
 */
void execute_operation(char opcode[10], char data_part[10], int opcodeValid,
		       int line_number, stack_t **stack)
{
	unsigned long int i;

	instruction_t instructions[] = {{"push", push_function}, {"pall", pall},
		{"pint", pint}, {"pop", pop}, {"nop", nop}, {"swap", swap},
		{"add", add}, {"sub", sub}, {"div", _div},
		{"mul", _mul}, {"mod", _mod}, {"pchar", pchar},};

	for (i = 0; i < sizeof(instructions) / sizeof(instructions[0]); i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{

			if (strcmp(opcode, "push") == 0)
				if (strcmp(data_part, "") == 0 || !is_digit(data_part))
				{
					fprintf(stderr, "L%d: usage: push integer\n", line_number);
					freeStack(stack, line_number);
					exit(EXIT_FAILURE);
				}

			data = atoi(data_part);
			instructions[i].f(stack, line_number);
			opcodeValid = 1;
		}
	}
	if (opcodeValid == 0)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		freeStack(stack, line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 * is_digit - function
 * @s: char
 * Return: 0 or 1
 */
int is_digit(char *s)
{
	int i = 0;

	if (s[i] == '-')
	{
		++i;
		if (s[i] == '\0' || s[i] == '\n')
			return (0);
	}

	while (s[i] != '\0' && s[i] != '\n')
	{
		char c = s[i];

		if (!isdigit(c))
			return (0);
		++i;
	}
	return (1);
}
