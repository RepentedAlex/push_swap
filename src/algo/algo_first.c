/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_first.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:00:38 by apetitco          #+#    #+#             */
/*   Updated: 2024/05/23 14:02:16 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "stack_funcs.h"
#include "push_swap.h"

static int	is_sorted(t_stack **stack)
{
	int		i;
	int		len;
	t_stack	*nav;

	len = get_stack_len(stack);
	nav = *stack;
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

static void	sort_three(t_stack **to_sort, t_stack **other)
{
	t_stack	*tmp;
	int		min;
	int		max;

		min = get_min(to_sort);
		max = get_max(to_sort);
	while (is_sorted(to_sort) != 1)
	{
		tmp = *to_sort;
		if (tmp->value == min)
		{
			if (tmp->next->value == max)
				reverse_rotate(to_sort, other, rra);
		}
		else if (tmp->value == max)
			rotate(to_sort, other, ra);
		else
		{
			if (tmp->next->value == min)
				swap(to_sort, other, sa);
			else if (tmp->next->value == max)
				reverse_rotate(to_sort, other, rra);
		}	
	}
}

static int	inner(t_stack **stack, int q1, int q3)
{
	int		i;
	int		len;
	t_stack	*tmp;

	if (*stack == NULL)
		return (0);
	tmp = *stack;
	len = get_stack_len(stack);
	i = 0;
	while (i++ < len)
	{
		if (q1 <= tmp->value && tmp->value <= q3)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	optimize_b(t_stack **stack_a, t_stack **stack_b, t_mq *mq)
{
	while (inner(stack_a, mq->q1, mq->q3))
	{
		if (mq->q1 <= (*stack_a)->value && (*stack_a)->value <= mq->med)
		{
			push_stack(stack_a, stack_b, pb);
			rotate(stack_a, stack_b, rb);
		}
		else if (mq->med <= (*stack_a)->value && (*stack_a)->value <= mq->q3)
			push_stack(stack_a, stack_b, pb);
		else
			rotate(stack_a, stack_b, ra);
	}
	while (get_stack_len(stack_a) > 3)
	{
		push_stack(stack_a, stack_b, pb);
		if ((*stack_b)->value < mq->med)
			rotate(stack_a, stack_b, rb);
	}
	if (!is_sorted(stack_a))
		sort_three(stack_a, stack_b);
	optimize_a(stack_a, stack_b, mq);
}
