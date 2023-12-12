#include "monty.h"

/**
 * strcmp - compares strings
 * @opcodeStr: a string to be compared
 * @listStr: a string to be compared
 * Return: 0
 */
int _strcmp(char *opcodeStr, char *listStr)
{
	while (*listStr != '\0')
	{
		if (*listStr == ' ')
			listStr++;
		else if (*opcodeStr == *listStr)
		{
			opcodeStr++;
			listStr++;
			if (*opcodeStr == '\0' && (*listStr == ' ' || *listStr == '\n' || *listStr == '\0'))
				return (1);
		}
		else
			return (0);
	}
	return (0);
}

/**
 * nlfind - finds newline
 * @listStr: the string to find \n
 * Return: 1 || 0
 */
int nlfind(char *listStr)
{
	char *newlineStr = "\n";

	while (*listStr != '\0')
	{
		if (*newlineStr == *listStr)
		{
			newlineStr++;
			listStr++;
			if (*newlineStr == '\0')
				return (1);
		}
		else
			listStr++;
	}
	return (0);
}

/**
 * pushint - int for push opcode
 * @listStr: the content of the file
 * @lineNum: line number
 * Return: the number
 */
int pushint(char *listStr, int lineNum)
{
	char *pushOpcode = "push";

	while (*listStr != '\0')
	{
		if (*pushOpcode == *listStr)
		{
			pushOpcode++;
			listStr++;
			if (*pushOpcode == '\0')
				while (*listStr)
				{
					if ((*listStr >= '0' && *listStr <= '9') || *listStr == '-')
					{
						checkcombo(listStr, lineNum);
						return (atoi(listStr));
					}
					else if (*listStr == ' ')
						listStr++;
					else
					{
						fprintf(stderr, "L%d: usage: push integer\n", lineNum);
						exit(EXIT_FAILURE);
					}
				}
		}
		else
			listStr++;
	}
	return (0);
}

/**
 * checkcombo - finds nonnumbers and number combinations
 * @listStr: the string
 * @lineNum: line number
 * Return: 1
 */
int checkcombo(char *listStr, int lineNum)
{
	int i = 1;

	while (listStr[i])
	{
		if (listStr[i] == '\0' || listStr[i] == '\n')
			break;
		if ((listStr[i] >= '0' && listStr[i] <= '9') || listStr[i] == ' ')
			i++;
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", lineNum);
			exit(EXIT_FAILURE);
		}
	}
	return (1);
}
