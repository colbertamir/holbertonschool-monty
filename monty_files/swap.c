#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack
 * @stackTop: pointer to head of stack
 * @lineNumber: file's line number
 * Return: Void
 */
void swap(stack_t **stackTop, unsigned int lineNumber)
{
	stack_t *topNode = *stackTop, *pointer;

	if ((*stackTop) == NULL || (*stackTop)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", lineNumber);
		exit(EXIT_FAILURE);
	}

	if (topNode && topNode->next)
	{
		pointer = topNode->next;
		if (pointer->next)
			pointer->next->prev = topNode;
		topNode->next = pointer->next;
		pointer->prev = NULL;
		pointer->next = topNode;
		topNode->prev = pointer;
		*stackTop = pointer;
	}
}
