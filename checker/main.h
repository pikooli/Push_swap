#ifndef MAIN_H
# define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0

typedef struct  s_maille
{
    int val;
    struct s_maille *prev;
    struct s_maille *next;
}               t_maille;

typedef struct s_list
{
    t_maille    *begin;
    int         numb;
}               t_list;

typedef struct s_option
{
    int val1;
    int val2;
    int color;
    int print;
}               t_option;


// principal function

void	ft_principal(int num, char **av, t_option option);
int 	ft_one_argu(char *str, t_option *option);


// check function 
int ft_only_number(char *str);
int ft_check_entry(int num, char **tab, t_option *option);
int ft_check_instruction(char buf[4], t_list *a, t_list *b);
int ft_check_double(int num, char **tab);
int ft_check_final(t_list *a, t_list *b);
int ft_set_option(int num, char **tab, t_option *option);

// malloc function
t_maille *ft_copy_av(int num, char *av[]);
char *ft_substr(char *str);
t_maille *ft_new_elem(int val);
t_list *ft_list();

// free function
t_maille *ft_free_list(t_maille *begin);
int	ft_free_tab(char **tab);
int ft_strfree(char *str);
char	**ft_free_tab_num(int size, char **tab);

// print function
void ft_putstr(char *str);
void ft_print_list(t_maille *begin);
int    ft_print_error();
void ft_putnbr(int numb);
int    ft_print_ok();
int    ft_print_ko();
void    ft_print_result(t_list *a, t_list *b);
void    ft_print_tab(char **tab);


// instruction
int    ft_instruction(t_list *a, t_list *b);
int    ft_sa(t_list *a);
int    ft_sb(t_list *b);
int    ft_ss(t_list *a, t_list *b);
int    ft_pa(t_list *a, t_list *b);
int    ft_pb(t_list *a, t_list *b);
int    ft_ra(t_list *a);
int    ft_rb(t_list *b);
int    ft_rr(t_list *a, t_list *b);
int    ft_rra(t_list *a);
int    ft_rrb(t_list *b);
int    ft_rrr(t_list *a, t_list *b);



// utility
long ft_atoi(char *str);
int ft_strcmp(char *str1, char *str2);
int ft_tab_length(char **tab);
char *ft_append(char *str1, char *str2);
int ft_strlen(char *str);

//split
char **ft_split(char *str, char cara);

#endif