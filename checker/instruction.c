#include "main.h"

int    ft_instruction(t_list *a, t_list *b)
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
        if (!(ft_check_instruction(tab[ret++], a, b)))
                return ft_free_tab(tab);
    ft_free_tab(tab);
    return ft_check_final(a, b);
}

int    ft_sa(t_list *a)
{
    t_maille *tmp;

    if (a->numb > 1)
    {
        tmp = a->begin;
        a->begin = a->begin->next;
        tmp->next = a->begin->next;
        a->begin->next = tmp;
    }
    return TRUE;
}

int    ft_sb(t_list *b)
{
    return ft_sa(b);
}

int    ft_ss(t_list *a, t_list *b)
{
    ft_sa(a);
    return ft_sb(b);
}

int    ft_pa(t_list *a, t_list *b)
{
    t_maille *tmp;

    if (b->numb == 0)
        return TRUE;
    tmp = b->begin;
    b->begin = b->begin->next;
    b->numb -= 1;
    tmp->next = a->begin;
    a->begin = tmp;
    a->numb += 1;
    return TRUE; 
}

int    ft_pb(t_list *a, t_list *b)
{
    return ft_pa(b, a);
}

int    ft_ra(t_list *a)
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
    return TRUE;
}

int    ft_rb(t_list *b)
{
    return ft_ra(b);
}

int    ft_rr(t_list *a, t_list *b)
{
    ft_ra(a);
    return ft_rb(b);
}

int    ft_rra(t_list *a)
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
    return TRUE;
}

int    ft_rrb(t_list *b)
{
    return ft_rra(b);
}

int    ft_rrr(t_list *a, t_list *b)
{
    ft_rra(a);
    return ft_rrb(b);
}
