#include "main.h"

int    ft_instruction(t_list *a, t_list *b, t_option *option)
{
    char buf[10];
    int ret;
    char **tab;
    char *cmd;

    if (!(cmd = malloc(sizeof(char)* 1)))
        return FALSE;
    cmd[0] = '\0';
    while((ret = read(0, buf, 5)))
    {
        buf[ret] = '\0';
        if(!(cmd = ft_append(cmd, buf)))
            return FALSE;
    }
    if (!(tab = ft_split(cmd, '\n')))
        return ft_strfree(cmd);
    free(cmd);
    ret = 0;
    while (tab[ret])
        if (!(ft_check_instruction(tab[ret++], a, b, option)))
                return ft_free_tab(tab);
    ft_free_tab(tab);
    return ft_check_final(a, b);
}

int    ft_sa(t_list *a,t_option *option)
{
    t_maille *tmp;

    if (a->numb > 1)
    {
        tmp = a->begin;
        a->begin = a->begin->next;
        tmp->next = a->begin->next;
        a->begin->next = tmp;
        option->val1 = tmp->val;
    }
    return TRUE;
}

int    ft_sb(t_list *b,t_option *option)
{
    return ft_sa(b, option);
}

int    ft_ss(t_list *a, t_list *b,t_option *option)
{
    ft_sa(a, option);
    return ft_sb(b, option);
}

int    ft_pa(t_list *a, t_list *b,t_option *option)
{
    t_maille *tmp;

    if (b->numb == 0)
        return TRUE;
    option->val1 = b->begin->val;
    tmp = b->begin;
    b->begin = b->begin->next;
    b->numb -= 1;
    tmp->next = a->begin;
    a->begin = tmp;
    a->numb += 1;
    return TRUE; 
}

int    ft_pb(t_list *a, t_list *b,t_option *option)
{
    return ft_pa(b, a, option);
}

int    ft_ra(t_list *a,t_option *option)
{
    t_maille *tmp;
    t_maille *last;

    if (a->numb < 2)
        return TRUE;
    tmp = a->begin;
    a->begin = a->begin->next;
    tmp->next = NULL;
    last = a->begin;
    while(last->next)
        last = last->next;
    last->next = tmp;
    option->val1 = tmp->val;
    return TRUE;
}

int    ft_rb(t_list *b,t_option *option)
{
    return ft_ra(b, option);
}

int    ft_rr(t_list *a, t_list *b,t_option *option)
{
    ft_ra(a, option);
    return ft_rb(b, option);
}

int    ft_rra(t_list *a,t_option *option)
{
    t_maille *tmp;
    t_maille *last;

    if (a->numb < 2)
        return TRUE;
    tmp = a->begin;
    while(tmp->next->next)
        tmp = tmp->next;
    last = tmp->next;
    tmp->next = NULL;
    last->next = a->begin;
    a->begin = last;
    option->val1 =last->val;
    return TRUE;
}

int    ft_rrb(t_list *b,t_option *option)
{
    return ft_rra(b, option);
}

int    ft_rrr(t_list *a, t_list *b,t_option *option)
{
    ft_rra(a, option);
    return ft_rrb(b, option);
}
