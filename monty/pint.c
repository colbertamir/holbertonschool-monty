#include "monty.h"

/**
 * printTopValue - Prints the top value of the stack
 * @stackTop: pointer to the head of the stack
 * @lineNumber: file's line number
 * Return: void
 */
void printTopValue(stack_t **stackTop, unsigned int lineNumber)
{
	if (*stackTop == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", lineNumber);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stackTop)->n);
}
