#include "monty.h"

/**
 * push - Pushes an element to the stack
 * @stack: pointer to head of the stack
 * @line_num: file's line number (unused parameter)
 * @value: integer value to be pushed onto the stack
 * Return: address of new element
 */

void push(stack_t **stack, unsigned int line_num __attribute__((unused)), int value)
{
    stack_t *new = malloc(sizeof(stack_t));
    if (new == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    new->prev = NULL;
    new->n = value;
    new->next = *stack;

    if (*stack != NULL) {
        (*stack)->prev = new;
    }

    *stack = new;
}
