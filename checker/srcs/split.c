
#include "main.h"

char	**ft_free_tab_num(int size, char **tab)
{
	int i;

	i = 0;
	while (i < size)
		free(tab[i++]);
	free(tab);
    return NULL;
}

int ft_count_split(char *str, char cara)
{
    int i;
    int nb;

    i = -1;
    nb = 0;
    while (str[++i])
    {
        if (i == 0 && str[i] != cara)
            nb++;
        else if (str[i] != cara && str[i - 1] == cara)
                nb++;
    }
    return nb;
}

char *ft_copy_to_cara(int *i, char *str, char cara)
{
    int j;
    char *ret;

    j = 0;
    while(str[*i + j] && str[*i +j] != cara)
        j++;
    if (!(ret = malloc(sizeof(char) * (j + 1))))
        return NULL;
    j = 0;
    while(str[*i + j] && str[*i +j] != cara)
    {    
        ret[j] = str[*i + j];
        j++;
    }
    ret[j] = '\0';
    *i += j;
    return ret;
}

char **ft_split(char *str, char cara)
{
    char **ret;
    int i;
    int j;

    i = ft_count_split(str, cara);
    if (!(ret = malloc(sizeof(char*) * (i + 1))))
        return NULL;
    i = 0;
    j = 0;
    while (str[i])
    {
        if (!(ret[j] = ft_copy_to_cara(&i, str, cara)))
            return ft_free_tab_num(j, ret);
        else if (ret[j][0] != '\0')
            j++;
        else
        {
            free(ret[j]);
            i++;
        }
    }
    ret[j] = NULL;
    return ret;   
}