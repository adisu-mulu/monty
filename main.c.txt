#include "monty.h"
int data;
int main(int argc, char *argv[])
{
	char buffer[50];
	char *token;
	int line_number, i, opcodeValid;
	instruction_t instructions[] = {
		{"push", push_function},
		{"add", add_function},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"nop", nop},
	};
	stack_t *stack = NULL;
	
	if (argc != 2)
	{
		printf("Usage: monty file\n");
		exit(EXIT_FAILURE);

	}

	FILE *file = fopen(argv[1], "r");
	if (file == NULL) {
		printf("Failed to open the file.\n");
		return 1;
	}
	line_number = 0;
	while (fgets(buffer, sizeof(buffer), file) != NULL)
        {
		char opcode[10]="";
		char data_part[5] = "";
		opcodeValid = 0;

		if(!isOpcodeOnly(buffer))
			{
				strcpy(opcode, buffer);
				size_t len = strlen(opcode);
				if (len > 0 && opcode[len - 1] == '\n') 
					opcode[len - 1] = '\0';
			}
		else {
			token = strtok(buffer, " ");
			if (token != NULL){
				strcpy(opcode, token);
			}
			token = strtok(NULL, " ");
			if (token != NULL)
				strcpy(data_part, token);
		}
		line_number++;
		for (i = 0; i <sizeof(instructions)/sizeof(instructions[0]); i++)
		{
			if (strcmp(opcode, instructions[i].opcode) == 0)
			{
				
				if(strcmp(opcode, "push") == 0)
					if (strcmp(data_part, "") == 0)
					{
						printf("L<%d>: usage: push integer\n", line_number);
						exit(EXIT_FAILURE);
					}
				
				data = atoi(data_part);
				instructions[i].f(&stack, line_number);
				opcodeValid = 1;
			}

		}
		if (opcodeValid == 0)
			printf("%s not found \n", opcode);
	
	}

	fclose(file);
	return (0);
}
