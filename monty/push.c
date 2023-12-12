#include "monty.h"

/**
 * push - Pushes an element to the stack
 * @stack: pointer to head of the stack
 * @line_num: file's line number
 * @n_str: string containing the input value
 * Return: address of new element
 */

void push(stack_t **stack, unsigned int line_num, const char *n_str);
{
    if (n_str == NULL || n_str[0] == '\0') {
        fprintf(stderr, "L%d: usage: push integer\n", line_num);
        exit(EXIT_FAILURE);
    }

    int n = atoi(n_str);
    if (n == 0 && n_str[0] != '0') {
        fprintf(stderr, "L%d: usage: push integer\n", line_num);
        exit(EXIT_FAILURE);
    }

    stack_t *new = malloc(sizeof(stack_t));
    if (new == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    new->prev = NULL;
    new->n = n;
    new->next = *stack;

    if (*stack != NULL) {
        (*stack)->prev = new;
    }

    *stack = new;
}
