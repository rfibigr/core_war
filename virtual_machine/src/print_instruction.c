/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:43:38 by rfibigr           #+#    #+#             */
/*   Updated: 2018/12/14 15:47:32 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_print_live(int processus, unsigned int champion)
{
	ft_printf("P    %d | live %d\n", processus, champion);
}

void	ft_print_ld(t_processus *processus, int arg1, int arg2)
{
	ft_printf("P    %d | ld %d r%d\n", processus->processus_number
	, arg1, arg2);
}

void	ft_print_st(t_processus *processus, int arg1, int arg2)
{
	ft_printf("P    %d | st r%d ", processus->processus_number, arg1);
	if ((*processus).action.type[ARG2] == REG)
		ft_printf("r");
	ft_printf("%hd\n", arg2);
}

void	ft_print_add(t_processus *processus, int arg1, int arg2, int arg3)
{
	ft_printf("P    %d | add r%d r%d r%d | r3 = r1 + r2 (%d = %d + %d)\n",
	processus->processus_number, arg1, arg2, arg3,
	(*processus).reg[arg3], (*processus).reg[arg1], (*processus).reg[arg2]);
}

void	ft_print_sub(t_processus *processus, int arg1, int arg2, int arg3)
{
	ft_printf("P    %d | sub r%d r%d r%d | r3 = r1 - r2 (%d = %d - %d)\n",
	processus->processus_number, arg1, arg2, arg3,
	(*processus).reg[arg3], (*processus).reg[arg1], (*processus).reg[arg2]);
}