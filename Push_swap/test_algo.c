#include "main.h"
char *ft_algo_1_1(t_list *a, t_list *b, t_option *option);


void   *ft_algo_1(t_list *a, t_list *b, t_option *option, t_instructions *instruct);

t_instructions *ft_test_algo(t_list *a, t_list *b, t_option *option)
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
    ft_algo_1(copy_a, copy_b, option, instruct);
    ft_print_instruction(instruct);
    // ft_print_result(copy_a, copy_b, *option);
    ft_free_listall(copy_a);
    ft_free_listall(copy_b);
    return instruct;
}

void    *ft_algo_1(t_list *a, t_list *b, t_option *option, t_instructions *instruct)
{ 
    char *choice;
    t_instruction *tmp;

    if (ft_check_final(a, b))
        return NULL;
    choice = ft_algo_1_1(a, b, option);
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
    ft_algo_1(a, b, option, instruct);
    return NULL;
}

char *ft_algo_1_1(t_list *a, t_list *b, t_option *option)
{
    ft_ra(a, option);
    return "ra";
}
