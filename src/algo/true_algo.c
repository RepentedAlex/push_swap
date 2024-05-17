/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   true_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:02:06 by apetitco          #+#    #+#             */
/*   Updated: 2024/05/17 17:28:41 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

static int	is_sorted(t_stack *stack)
{
	int	i;
	int	len;
	t_stack	*nav;

	nav = stack;
	len = get_stack_len(nav);
	if (len > 0)
	{
		i = 1;
		while (i++ < len)
		{
			if (nav->value > nav->next->value)
				return (0);
			nav = nav->next;
		}
		return (1);
	}
	return (0);
}

void	launch_algo(t_stack *stack_a, t_stack *stack_b, t_mq *mq)
{
	if (mq->len == 2 && stack_a->value > stack_a->next->value)
		swap(stack_a, stack_b, sa);
	if (mq->len > 2 && !is_sorted(stack_a))
	{
		optimize_b(stack_a, stack_b, mq);
	}
}
