unsigned strlen(const char *str)
{
    unsigned len = 0;
    while (*str++)
        len++;
    return len;
}

void strcat(char *to, const char *from)
{
    while (*to)
        to++;
    while (*from)
        *(to++) = *(from++);
    *to = '\0';
}

int strstr(const char *text, const char *pattern)
{
    for (int i = 0; *text != '\0' || *pattern == '\0'; i++, text++)
        for (int j = 0; *(text + j) == *(pattern + j) || *pattern == '\0'; j++)
            if (*(pattern + j + 1) == '\0' || *pattern == '\0')
                return i;
    return -1;
}
