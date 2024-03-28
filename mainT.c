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

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	FILE *file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(sterr, "Error: Can't open file %s\n", argv[1);
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
	char buffer[50];
	char *token;
	int opcodeValid, line_number;

	line_number = 0;
	stack_t *stack = NULL;

	while (fgets(buffer, sizeof(buffer), file) != NULL)
	{
		char opcode[10] = "";
		char data_part[5] = "";

		opcodeValid = 0;

		if (!isOpcodeOnly(buffer))
		{
			strcpy(opcode, buffer);
			size_t len = strlen(opcode);

			if (len > 0 && opcode[len - 1] == '\n')
				opcode[len - 1] = '\0';
		}
		else
		{
			token = strtok(buffer, " ");
			if (token != NULL)
			{
				strcpy(opcode, token);
			}
			token = strtok(NULL, " ");
			if (token != NULL)
				strcpy(data_part, token);
		}

		execute_operation(opcode, data_part, opcodeValid, ++line_number, &stack);
	}
}
/**
 * execute_operation - function
 * @opcode: opcode
 * @data_part: data part
 * @opcodeValid: checks if opcode is valid
 * @line_number: tracks line number
 * @stack: pointer to the stack
 */
void execute_operation(char opcode[10], char data_part[5], int opcodeValid,
		       int line_number, stack_t **stack)
{
	int i;

	instruction_t instructions[] = {
		{"push", push_function},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"nop", nop},
	};

	for (i = 0; i < sizeof(instructions) / sizeof(instructions[0]); i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{

			if (strcmp(opcode, "push") == 0)
				if (strcmp(data_part, "") == 0)
				{
					printf("L<%d>: usage: push integer\n", line_number);
					exit(EXIT_FAILURE);
				}

			data = atoi(data_part);
			instructions[i].f(stack, line_number);
			opcodeValid = 1;
		}
	}
	if (opcodeValid == 0)
	{
		fprintf(stderr, "L<%d>: unknown instruction <%s>\n",line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
