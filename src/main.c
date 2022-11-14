#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "simon.h"

int main (int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Too few arguments.\n");
        return 1;
    }
    char *file_input = argv[1];
    if (access(file_input, F_OK) != 0)
    {
        printf("The specified file '%s' does not exist.\n", file_input);
        return 1;
    }

    //Random number
    char *random_number = malloc(4);
    generate_random_number(random_number, 4);
    //File name
    char *file_name = malloc(7);
    strcpy(file_name, "prg");
    strcat(file_name, random_number);
    //File path
    char *file_path = malloc(12);
    strcpy(file_path, "/tmp/");
    strcat(file_path, file_name);
    //Compiling
    build_program(file_path, file_input);
    //Execution
    cleanup_thread(file_path);
    if (argc == 2)
        execlp(file_path, file_name, NULL);
    else
    {
        char *arguments[argc - 1];
        for (int i = 0; i < argc - 1; i++)//Set arguments
            arguments[i] = argv[i + 1];
        arguments[argc - 1] = NULL;
        execv(file_path, arguments);
    }
}