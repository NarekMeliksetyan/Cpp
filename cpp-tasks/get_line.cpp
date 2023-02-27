#include <iostream>

char *resize(const char *str, size_t size, size_t new_size)
{
    char *new_str = new char[new_size];

    for (size_t i = 0; i < size && i < new_size; i++)
        new_str[i] = str[i];

    delete[] str;
    return new_str;
}

char *getline()
{
    const size_t BUFF_SIZE = 64;
    size_t i = 0, size = BUFF_SIZE;

    char c;
    char *str = new char[size];
    while (std::cin.get(c) && c != '\n')
    {
        if (i == size)
        {
            size += BUFF_SIZE;
            str = resize(str, i, size);
        }
        str[i++] = c;
    }
    str[i] = '\0';

    return str;
}