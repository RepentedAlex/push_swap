/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 19:59:44 by apetitco          #+#    #+#             */
/*   Updated: 2024/03/20 21:04:25 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/include/libft.h"
#include "../include/stacks.h"
#include "../include/push_swap_utils.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	// t_stack	*a_stack;
	// t_stack	*b_stack;
	// t_stack	**a_head;
	// t_stack	**b_head;
	int	*array;

	if (argc < 3)
		return (1);
	//*a_head = init_a_stack(a_stack, ft_atoiv(argv[1], argc - 1), argc);
	array = ft_atoiv(&argv[1], argc - 1);
	for (int i = 0; i < 6; i++)
	{
		printf("[%i]: %i\n", i, array[i]);
	}
}
