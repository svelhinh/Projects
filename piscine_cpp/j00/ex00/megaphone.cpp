#include <iostream>

int islower(char c)
{
    if (c >= 'a' && c <= 'z')
        return 1;
    return 0;
}

char toupper(char c)
{
    if (islower(c))
        return c - 32;
    return c;
}

void put_upper(const char *s)
{
    int i = 0;

    while (s[i] == ' ')
        i++;
    while (s[i])
    {
        int j = i;
        while (s[j] == ' ')
            j++;
        if (s[j] != ' ' && s[j])
            std::cout << toupper(s[i]);
        i++;
    }
}

int main(int ac, char const **av)
{
    int i = 1;

    if (ac > 1)
    {
        while (i < ac)
        {
            put_upper(av[i]);
            i++;
            if (i != ac)
                std::cout << " ";
        }
        std::cout << std::endl;
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return 0;
}
