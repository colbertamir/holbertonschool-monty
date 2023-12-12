#include "monty.h"

/**
 * add - adds the top two elements of the stack.
 * @stackTop: pointer to the stack top
 * @lineNumber: line number
 * Return: no return
 */
void add(stack_t **stackTop, unsigned int lineNumber)
{
    stack_t *current;
    int count = 0, sum;

    current = *stackTop;

    while (current)
    {
        current = current->next;
        count++;
    }

    if (count < 2)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", lineNumber);
        free_stack(*stackTop);
        exit(EXIT_FAILURE);
    }

    current = *stackTop;
    sum = current->n + current->next->n;
    current->next->n = sum;
    *stackTop = current->next;
    free(current);
}
