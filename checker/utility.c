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
    int moins;

    if (ft_strcmp(str, "-2147483648"))
        return -2147483648;
    i = str[0] != '-' ? 0 : 1;
    moins = str[0] != '-' ? 1 : -1;
    nb = 0;
    while(str[i])
    {        
        nb *= 10;
        nb += str[i++] - 48; 
    }
    return moins * nb;
}