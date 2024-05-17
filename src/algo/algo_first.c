/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_first.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:00:38 by apetitco          #+#    #+#             */
/*   Updated: 2024/05/17 11:49:52 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

int	inner(t_stack *stack, int q1, int q3)
{
	int		i;
	int		len;
	t_stack	*tmp;

	if (!stack)
		return ;
	tmp = stack;
	len = get_stack_len(stack);
	i = 0;
	while (i++ < len)
	{
		if (q1 <= tmp->value && tmp->value <= q3)
			return (1);
		tmp  = tmp->next;
	}
	return (0);
}

void	optimize_b(t_stack *stack_a, t_stack *stack_b, t_mq *mq)
{
	while (inner(stack_a, mq->q1, mq->q3))
	{
		if (mq->q1 <= stack_a->value && stack_a->value <= mq->med)
		{
			push_stack(&stack_a, &stack_b, pb);
			rotate(&stack_a, &stack_b, rb);
		}
		else if (mq->med <= stack_a->value && stack_a->value <= mq->q3)
			push_stack(&stack_a, &stack_b, pb);
		else
			rotate(&stack_a, &stack_b, ra);
	}
	while (get_stack_len(stack_a) > 3)
	{
		push_stack(&stack_a, &stack_b, pb);
		if (stack_b->value < mq->med)
			rotate(&stack_a, &stack_b, rb);
	}
	if (!is_sorted(stack_a))
		sort_three(&stack_a);
	optimize_a(stack_a, stack_b, mq);
}
