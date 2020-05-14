#include "monty.h"
/**
 * is_intiger - execute function if available
 * @token: Line content in position [1]
 * Return: void
 */
bool is_intiger(char *token)
{
	unsigned int i;

	for (i = 0; token && token[i]; i++)
	{
		if (token[0] == '-')
			continue;
		if (token[i] <= 47 || token[i] >= 58)
			return (false);
	}
	return (true);
}

