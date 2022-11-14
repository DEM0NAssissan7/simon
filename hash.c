#include <stdio.h>

#define STRING_LENGTH 256

int hash(char string[], int length)
{
    int result = 0;
    for(int i = 0; i < length; i++)
        result += string[i] * (i + 1);
    return result;
}

int main()
{
    char input[STRING_LENGTH];
    for(int i = 0; i < STRING_LENGTH; i++)//Clean array
        input[i] = 0;
    printf("\nEnter a phrase: ");
    scanf("%s", input);
    printf("Your hash is: %d\n", hash(input, STRING_LENGTH));

    return 0;
}