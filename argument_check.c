#include "monty.h"

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
