/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 12:33:51 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/27 16:12:37 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Initilization of VM
** -Check if arguments are valable
** -Create ram and initialize all element
*/

int	main(int argc, char **argv)
{
	t_vm	vm;

	initialize_vm(&vm);
	check_parameters(argc, argv, &vm);
	load_champs(&vm);
	print_struct_vm(vm);
	print_ram(vm.ram);
	//fonction to free all vm
	ft_memdel((void **)&(vm.ram));
	return (1);
}
