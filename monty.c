#include "monty.h"

int argument = 0;

/**
 * main - 
 * 
 * 
 * 
 * 
 */
int main(int argc, char **argv)
{
    FILE *file;
    size_t size = 0;
    int linenumber = 0;
    char *buffer, **args;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    while (getline(&buffer, &size, file))
    {
        linenumber++;
        args = split_line(buffer, " '\n'");
        if (args)
        {
            get_op_func(args, linenumber);
            free(args);
        }
    }
    fclose(file);
    return (EXIT_SUCCESS);
}
/**
 * split_line -  
 * 
 * 
 */
char **split_line(char *line, char *delimiter)
{
    size_t buffer_size = 3;
    char **alltokens, *token = NULL;
    int i;

    alltokens = malloc(sizeof(char *) * buffer_size);
    if (alltokens == NULL)
    {
        printf("Error: malloc failed");
        exit(EXIT_FAILURE);
    }
    token = strtok(line, delimiter);
    for (i = 0; token && i < 2; i++)
    {
        alltokens[i] = token;
        token = strtok(NULL, delimiter);
    }
    alltokens[i] = NULL;
    return (alltokens);
}
