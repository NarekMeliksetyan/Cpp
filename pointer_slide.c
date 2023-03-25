#include <stdio.h>

int main()
{
    unsigned steps = 100;

    int start = 100;
    int *ptr = &start;

    while (steps--)
    {
        printf("%p: ", ptr);
        if (*ptr)
        {
            printf("%d\n", *ptr);
        }
        else
        {
            printf("empty\n");
        }
        ptr++;
    }
    
    return 0;
}
