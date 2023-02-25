#include <iostream>

char *resize(const char *str, unsigned size, unsigned new_size)
{
    char *new_str = new char[new_size];

    for (int i = 0; i < size && i < new_size; i++)
        new_str[i] = str[i];

    delete[] str;
    return new_str;
}

char *getline()
{
    const unsigned BUFFER = 64;
    unsigned i = 0, size = BUFFER;

    char c;
    char *str = new char[size];
    while (std::cin.get(c) && c != '\n')
    {
        if (i == size)
        {
            size += BUFFER;
            str = resize(str, i, size);
        }
        str[i++] = c;
    }
    str[i] = '\0';

    return str;
}
