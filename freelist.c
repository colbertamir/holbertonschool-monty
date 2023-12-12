#include "monty.h"

/**
 * free_stack - frees the singly linked list
 * @head_ref: pointer to list
 * Return: Nothing
 */
void free_stack(stack_t *head_ref)
{
	stack_t *current_node = head_ref;

	if (head_ref == NULL)
		return;

	while (head_ref != NULL)
	{
		current_node = head_ref;
		head_ref = head_ref->next;
		free(current_node);
	}
}

/**
 * free_list - frees getline list
 * @lines: pointer to array of strings
 * Return: Nothing
 */
void free_list(char *lines[])
{
	int index = 0;

	while (lines[index] != NULL)
	{
		free(lines[index]);
		index++;
	}
}
