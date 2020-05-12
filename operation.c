#include "monty.h"

void get_op_func(char **args, unsigned int num)
{
    argument = 0;
    unsigned int i;
    instruction_t ops[] = {
        {"push", push},
        {"pall", pall},
        //{"pint", pint},
        //{"pop", pop},
        //{"swap", swap},
        //{"add", add},
        //{"nop", nop},
        {NULL, NULL}};

    while (ops[i].opcode)
    {
        if (strcmp(ops[i].opcode, args[0]) == 0)
        {
            if (strcmp(ops[i].opcode, "push") == 0)
                argument = atoi(args[1]);
            ops[i].f;
        }

        i++;
    }

    printf("L%d: unknown instruction %s\n", num, args[0]);
    free(args);
    exit(EXIT_FAILURE);
}
