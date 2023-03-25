#include <stdio.h>

int main()
{
    unsigned steps = 100;
    int *ptr = 0;

    while (steps--)
    {
        if (*ptr)
        {
            printf("%p: %d\n", ptr, *ptr);
        }
    }
    
    return 0;
}
