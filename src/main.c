#include <string.h>
#include <stdio.h>

int main()
{
    setbuf(stdout, NULL);
    while (1)
    {
        printf("$ ");
        char input[100];

        if (fgets(input, 100, stdin) == NULL)
        {
            break;
        }

        input[strlen(input) - 1] = '\0';

        char *ptr = strtok(input, " ");

        while (ptr != NULL)
        {
            // exit command
            if (strcmp(ptr, "exit") == 0)
            {
                return 0;
            }

            // echo command
            else if (strcmp(ptr, "echo") == 0)
            {
                ptr = strtok(NULL, " ");
                while (ptr != NULL)
                {
                    printf("%s", ptr);
                    ptr = strtok(NULL, " ");
                }
                printf("\n");
            }
            else
            {
                printf("%s: command not found\n", input);
                break;
            }
        }
    }
    return 0;
}