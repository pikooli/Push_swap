#include "main.h"


int ft_strcmp(char *str1, char *str2)
{
    int i;
    
    if (str1 == NULL || str2 == NULL)
        return 0;
    i = 0;
    while ((str1[i] == str2[i]) && str1[i] && str2[i])
        i++;
    return ((str1[i] == '\0') && (str2[i] == '\0'));
}

int ft_atoi(char *str)
{
    int nb;
    int i;

    nb = 0;
    i = 0;
    while(str[i])
    {        
        if (i > 9)
            if (str[i] > 7 || str[i + 1] != '\0')
                return -1;
        nb *= 10;
        nb += str[i++] - 48; 
    }
    return nb;
}

int ft_tab_length(char **tab)
{
    int i;

    i = 0;
    while(tab[i])
        i++;
    return i;
}