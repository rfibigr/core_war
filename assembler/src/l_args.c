#include "../includes/asm.h"

static int    label_error(t_labels *l, char *to_check)
{
    int    i;

    i = 0;
    if (to_check[i] == DIRECT_CHAR)
        i++;
    if (to_check[i] == LABEL_CHAR)
        i++;
    while (l)
    {
        if (l->name && !ft_strcmp(l->name, to_check + i))
                return (0);
        l = l->next;
    }
    return (1);
}

/*
**  arguments are digits-only
**  register is between 1 and REG_NUMBER(16)
*/

static int   args_error(char **s)
{
    int    y;
    int    x;

    y = 0;
    while (s[y])
    {
        x = 0;
        if (s[y][x] == 'r' && (ft_atoi(s[y] + 1) > REG_NUMBER || s[y][1] == '0'))
            error_args(s[y]);
        if (s[y][x] == DIRECT_CHAR || s[y][x] == 'r')
            x++;
        if (s[y][x] == LABEL_CHAR)
            return (y);
        while (s[y][x])
        {
            if (!ft_isdigit(s[y][x]))
                    error_args(s[y]);
            x++;
        }
        y++;
    }
    return (-1);
}

static void    args_nb_check(t_labels *l, t_op *op)
{
    int    i;

    while (l)
    {
        i = 0;
        while (l->args[i])
            i++;
        if (i != op[l->op_nb - 1].params_nb)
            error_param_nb(l->op_code, op[l->op_nb - 1].params_nb, i);
        l = l->next;
    }
}

void    general_check(t_data *d)
{
    int         a;
    t_labels    *l;

    l = d->first_label;
    args_nb_check(d->first_label, d->op);
    while (l)
    {
        a = args_error(l->args);
        if (a >= 0)
        {
            if (label_error(d->first_label, l->args[a]))
                error_label(l->args[a]);
        }
        l = l->next;
    }
}