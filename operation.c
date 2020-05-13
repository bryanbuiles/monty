#include "monty.h"
#include <errno.h>

void (*get_op_func(byteline_t line))(stack_t **, unsigned int)
{

    unsigned int i = 0;
    char *end;

    errno = 0;
    instruction_t ops[] = {
        {"push", push},
        {"pall", pall},
        //{"pint", pint},
        //{"pop", pop},
        //{"swap", swap},
        //{"add", add},
        //{"nop", nop},
        {NULL, NULL}};

    while (ops[i].opcode != NULL)
    {
        if (strcmp(ops[i].opcode, line.contenido[0]) == 0)
        {
            if (strcmp(ops[i].opcode, "push") == 0)
            {     
                if (line.contenido[1] != end)
                {
                    argument = strtol(line.contenido[1], &end, 10);
                }
                if (errno != 0)
                {
                    fprintf(stderr, "L%d: usage: push integer\n", line.number);
                    exit(EXIT_FAILURE);
                }
            }
            free(line.contenido);
            return (ops[i].f);
        }
        i++;
    }

    printf("L%d: unknown instruction %s\n", line.number, line.contenido[0]);
    free(line.contenido);
    exit(EXIT_FAILURE);
}
