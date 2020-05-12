#include "monty.h"

bool argument_check(char *token)
{
    unsigned int i;

    for (i = 0; token && token[i]; i++)
    {
        if (token[0] == '-')
            continue;
        if (token[i] <= '0' || token[i] >= '9')
            return (false);
    }

    return (true);
}
bool comment_check(char **args)
{
    if (args[0] == '#')
    {
        free(args);
        return (true);
    }
    return (false);
}
