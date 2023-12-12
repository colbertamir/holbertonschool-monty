#include "monty.h"

/**
 * pop - Removes the top element of the stack
 * @stackTop: pointer to head of stack
 * @lineNumber: file's line number
 * Return: void
 */

void pop(stack_t **stackTop, unsigned int lineNumber)
{
	stack_t *topNode = *stackTop;

	if (!(*stackTop))
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", lineNumber);
		exit(EXIT_FAILURE);
	}

	if (topNode)
	{
		*stackTop = (topNode)->next;
		free(topNode);
	}
}
