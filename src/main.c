/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:57:02 by apetitco          #+#    #+#             */
/*   Updated: 2024/04/12 18:43:51 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/parsing.h"
#include "../include/stacks.h"
#include "../include/utilities.h"
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	if (argc == 1)
		exit(EXIT_FAILURE);
	if (valid_command(argc - 1, argv) == no)
		exit_handler(1);
	stack_a = init_stack_a(argc - 1, argv);
	stack_b = init_stack_b(argc - 1);
	(void)stack_a;
	(void)stack_b;
}
