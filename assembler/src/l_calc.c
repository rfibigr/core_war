/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_calc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <dshults@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 15:42:30 by dshults           #+#    #+#             */
/*   Updated: 2018/12/02 15:54:38 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static int    count(int pos, t_labels *l)
{
	int    i;
	int    bytes;

	bytes = 0;
	i = 0;
	while (i < pos)
	{
		bytes += l->bytes;
		i++;
		l = l->next;
	}
	return (bytes);
}

static int    rew_count(t_labels *f, int cp, int lp)
{
	int    bytes;

	bytes = 0;
	while (f && f->position < lp)
		f = f->next;
	while (f && f->position < cp)
	{
		bytes -= f->bytes;
		f = f->next;
	}
	return (bytes);
}

//printf("param %i\n", (int)d->op[5].params_types[0]);
//printf("\nuntil label (in hex): %x\n",\
//calc_bytes_till_label(d->first_label, d->first_label, 1));

int    calc_bytes_till_label(t_labels *first_label, t_labels *current_l, int a)
{
	t_labels *l;
	int    i;

	l = first_label;
	i = 0;
	while (l)
	{
		if (ft_strequ(l->name, current_l->args[a] + 2))
		{
			if (l->position > current_l->position)
				i += count(l->position - current_l->position, current_l);
			else
				i += (unsigned int)rew_count(first_label,
						current_l->position, l->position);
		}
		l = l->next;
	}
	return (i);
}
