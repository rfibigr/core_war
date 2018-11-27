/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:19:03 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/27 15:36:12 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_champion	*new_champion(void)
{
	t_champion	*new_elem;

	if (!(new_elem = (t_champion *)malloc(sizeof(t_champion))))
		ft_exit_malloc();
	initialize_champion(&new_elem);
	return (new_elem);
}

void		ft_push_back_chmp(t_champion **begin, t_champion *to_add)
{
	t_champion *tmp;

	tmp = *begin;
	if (*begin == NULL)
		*begin = to_add;
	else
	{
		if (tmp)
		{
			while (tmp->next)
				tmp = tmp->next;
		}
		tmp->next = to_add;
	}
}

int			ft_atoi_exit(char *s, char *parameter, char *file)
{
	unsigned long long	nbr;
	int					i;

	i = 0;
	nbr = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '\v' ||
			s[i] == '\r' || s[i] == '\f')
		i++;
	if (!(s[i] >= '0' && s[i] <= '9'))
		ft_exit_parameter(parameter, file);
	while (s[i] >= '0' && s[i] <= '9')
	{
		nbr = nbr * 10;
		nbr = nbr + s[i] - '0';
		if (nbr > 0xFFFFFFFF)
			ft_exit_parameter(parameter, file);
		i++;
	}
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '\v' ||
			s[i] == '\r' || s[i] == '\f')
		i++;
	if (s[i] != '\0')
		ft_exit_parameter(parameter, file);
	return (nbr);
}
