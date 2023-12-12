#include "monty.h"

/**
 * printStackValues - Prints all values on the stack
 * @stack: pointer to head of the stack
 * @line_num: file's line number (unused parameter)
 * Return: Void
 */

void printStackValues(stack_t **stack, unsigned int line_num __attribute__((unused)))
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
