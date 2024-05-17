/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:08:51 by apetitco          #+#    #+#             */
/*   Updated: 2024/05/17 12:14:02 by apetitco         ###   ########.fr       */
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
	get_mq(args_support(argc, argv), &mq, &error);
	if (error || mq->len == 0 || !mq)
	{
		ft_putstr_fd("Error\n", 2);
		if (mq)
			free(mq);
		return (1);
	}
	if (init_stack(&stack_a, args_support(argc, argv), &stack_b) == 1)
	{
		debug_stacks(stack_a, stack_b);
		// launch_algo(stack_a, stack_b, mq);
		rotate(&stack_a, &stack_b,  ra);
		// reverse_rotate(&stack_a, &stack_b,  rrr);
		debug_stacks(stack_a, stack_b);
	}
	return (0);
}
