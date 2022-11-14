#include <stdlib.h>
#include <string.h>
#include <signal.h>

void generate_random_number (char *pointer, int length)
{
    char characters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    int character_count = strlen(characters);

    FILE *file = fopen("/dev/urandom", "r");
    int random_num;
    fread(&random_num, 2, 1, file);
    srand(random_num);

    for (int i = 0; i < length; i++)
        pointer[i] = characters[rand() % character_count];
}

void build_program (char *file_path, char *file_input)
{
    char *build_command = malloc(sizeof file_input + sizeof file_path + 14);
    strcpy(build_command, "gcc -Wall -o ");
    strcat(build_command, file_path);
    strcat(build_command, " ");
    strcat(build_command, file_input);
    system(build_command);
}

void cleanup_thread (char *file_path)
{
    void sigint_handler (int sig)
    {
        if(access(file_path, F_OK) != 0)
            exit(0);
        else
        {
            printf("Finishing thread...\n");
            remove(file_path);
            exit(0);
        }
    }
    signal(SIGINT, sigint_handler);
    pid_t pid = fork();
    if(pid == 0)
    {
        sleep(1);
        remove(file_path);
        exit(0);
    }
}