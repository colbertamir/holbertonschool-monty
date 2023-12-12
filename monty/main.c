#include "monty.h"

int main(int argc, char *argv[])
{
	stack_t *my_stack = NULL;
	static char *instructions[1000] = {NULL};
	int line_number = 0;
	FILE *file_ptr;
	size_t bufsize = 1000;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file_ptr = fopen(argv[1], "r");
	if (file_ptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	for (line_number = 0; getline(&(instructions[line_number]), &bufsize, file_ptr) > 0; line_number++)
		;
	execute(instructions, my_stack);
	free_list(instructions);
	fclose(file_ptr);
	return (0);
}

void execute(char *instructions[], stack_t *my_stack)
{
	int line_number, index, i;

	instruction_t instruction_set[] = {
		{"pall", pall},
		{"pint", pint},
		{"add", add},
		{"swap", swap},
		{"pop", pop},
		{"null", NULL}
	};

	for (line_number = 1, index = 0; instructions[index + 1]; index++, line_number++)
	{
		if (_strcmp("push", instructions[index]))
			push(&my_stack, line_number, pushint(instructions[index], line_number));
		else if (_strcmp("nop", instructions[index]))
			;
		else
		{
			i = 0;
			while (!_strcmp(instruction_set[i].opcode, "null"))
			{
				if (_strcmp(instruction_set[i].opcode, instructions[index]))
				{
					instruction_set[i].f(&my_stack, line_number);
					break;
				}
				i++;
			}
			if (_strcmp(instruction_set[i].opcode, "null") && !_strcmp(instructions[index], "\n"))
			{
				fprintf(stderr, "L%u: unknown instruction %s", line_number, instructions[index]);
				if (!nlfind(instructions[index]))
					fprintf(stderr, "\n");
				exit(EXIT_FAILURE);
			}
		}
	}
	free_stack(my_stack);
}
