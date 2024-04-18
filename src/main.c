/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:57:02 by apetitco          #+#    #+#             */
/*   Updated: 2024/04/18 19:48:03 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "parsing.h"
#include "stacks.h"
#include "utilities.h"
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		exit(EXIT_FAILURE);
	if (valid_command(argc - 1, argv) == false)
		exit_handler(1);
	stack_a = init_stack_a(argc - 1, argv);
	stack_b = NULL;
	// push_swap(&stack_a, &stack_b);
	(void)stack_a;
	(void)stack_b;
}
