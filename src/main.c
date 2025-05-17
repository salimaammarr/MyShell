#include <string.h>
#include <stdio.h>

int binarySearch(char *arr[], int size, char *target)
{
    int left = 0;
    int right = size - 1;
    while (left <= right)
    {
        int mid = (left + (right - left)) / 2;
        int cmp = strcmp(arr[mid], target);

        if (cmp == 0)
        {
            return mid;
        }
        else if (cmp < 0)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
}
int main()
{
    setbuf(stdout, NULL);
    while (1)
    {
        char *commands[] = {"echo", "exit", "type"};

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

            // type command
            else if (strcmp(ptr, "type") == 0)
            {
                ptr = strtok(NULL, " ");
                if (ptr != NULL)
                {
                    int index = binarySearch(commands, sizeof(commands) / sizeof(commands[0]), ptr);
                    if (index != -1)
                    {
                        printf("%s is a shell built-in command\n", ptr);
                        break;
                    }
                    else
                    {
                        printf("%s: command not found\n", ptr);
                        break;
                    }
                }
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