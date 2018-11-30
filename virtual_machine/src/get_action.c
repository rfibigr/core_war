/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeheret <sbeheret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 16:09:30 by sbeheret          #+#    #+#             */
/*   Updated: 2018/11/30 14:54:33 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "op.c"

void	get_action(t_vm *vm, t_processus *pcs)
{
	// ft_printf("here !\n");
	initialize_action(pcs);
	pcs->action.op_code = vm->ram[circular(pcs->PC)];
	if (pcs->action.op_code < 1 || pcs->action.op_code > 16)
	{
		pcs->PC++;
		pcs->action.op_code = 0;
		pcs->cycles_wait = 1;
		return ;
	}
	pcs->cycles_wait = op_tab[pcs->action.op_code - 1].cycle;
	pcs->action.size_read++;
	pcs->action.nb_arg = op_tab[pcs->action.op_code - 1].param_number;
	args_action(vm->ram, pcs->PC, &pcs->action);
	pcs->PC += pcs->action.size_read;
//	if (pcs->action.op_code == 12)
//		JUMP JUMP JUMP JUMP
}

void	args_action(unsigned char *ram, int PC, t_action *action)
{
	int		i;
	int		i_ram;
	int		size;
	int		enc_byte;

	if ((enc_byte = op_tab[action->op_code - 1].encoding_byte))
		action->size_read++;
	size = 0;
	i = 0;
	trad_encoding_byte(action, enc_byte, ram[circular(PC + 1)]);
	i_ram = circular(PC + enc_byte + 1);
	while (i < action->nb_arg)
	{

		if (action->type[i] == 3 || (action->type[i] == 2 &&
			op_tab[action->op_code - 1].direct_octect))
			size = 2;
		else if (action->type[i] == 2)
			size = 4;
		else
			size = 1;
		action->args[i] = size == 1 ? ram[i_ram] : ft_octet_to_int2(ram, size,
				i_ram);
		if (action->type[i] == 3)
			action->args[i] += circular(PC);
		i_ram += size;
		action->size_read += size;
		i++;
	}
}

void	trad_encoding_byte(t_action *action, int enc_byte, int value)
{
	if (!enc_byte)
	{
		action->type[0] = 2;
		action->type[1] = 0;
		action->type[2] = 0;
		action->type[3] = 0;
	}
	else
	{
		action->type[0] = (value & 0b11000000) >> 6;
		action->type[1] = (value & 0b00110000) >> 4;
		action->type[2] = (value & 0b00001100) >> 2;
		action->type[3] = 0;
	}
}
