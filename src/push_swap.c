/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:08:51 by apetitco          #+#    #+#             */
/*   Updated: 2024/05/16 14:49:39 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		error;
	t_mq	*mq;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		exit(1);
	mq = malloc(sizeof(t_mq));
	if (!mq)
		exit(1);
	error = 0;
	get_mq(ft_split(argv[1], ' '), &mq, &error);
	if (error || mq->len == 0 || !mq)
	{
		ft_putstr_fd("Error\n", 2);
		if (mq)
			free(mq);
		return (1);
	}	
	//TODO: Fix `init_stack` function
	if (init_stack(&stack_a, ft_split(argv[1], ' ')) == 1)
	{
		//! PRINTF ICI !//
		ft_printf("\033[0;93mInitialisation de la stack effectuée ! o7\n\033[0;39m");
		//! PRINTF ICI !//
		launch_algo(stack_a, stack_b, mq);
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
	free(mq);
	return (0);
}
