#include <stdio.h>

int main(int argc, char **argv)
{
    unsigned steps = 100;
    int start = 1;
    int *ptr = &start;

    while (steps--)
    {
        printf("%p: ", ptr);
        if (*ptr)
            printf("%d\n", *ptr);
        else
            printf("empty\n");
        ptr++;
    }
    
    return 0;
}
