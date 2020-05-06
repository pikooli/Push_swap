#include "main.h"

t_instructions *ft_prepare_algo(t_list *a, t_list *b, t_option *option, char *(*algo)(t_list *, t_list *, t_option *))
{
    t_list *copy_a;
    t_list *copy_b;
    t_instructions *instruct;

    if (!(instruct = ft_create_instructions()))
        return NULL;
    if (!(copy_a = ft_list()))
    {   
        free(instruct); 
        return NULL;
    }
    if (!(copy_b = ft_list()))
        return ft_free_listall(copy_a);
    if (!(copy_a->begin = ft_copy_list(a->begin)))
    {
        ft_free_listall(copy_a);
        ft_free_listall(copy_b);
        return NULL;
    }
    copy_a->numb = a->numb;
    instruct->a = copy_a;
    instruct->b = copy_b;
    ft_test_algo(instruct, option, (*algo));
    return instruct;
}

void    *ft_test_algo(t_instructions *instruct ,t_option *option, char *(*algo)(t_list *, t_list *, t_option *))
{ 
    char *choice;
    t_instruction *tmp;

    if (ft_check_final(instruct->a, instruct->b))
        return NULL;
    instruct->numb += 1;
    choice = (*algo)(instruct->a, instruct->b, option);
    if (!(tmp = ft_create_instruction(choice)))
        return NULL;
    if (!instruct->first)
    {
        instruct->first = tmp;
        instruct->last = tmp;
    }
    else
    {
        instruct->last->next = tmp;
        instruct->last = tmp;
    }
    ft_test_algo(instruct, option, (*algo));
    return NULL;
}

