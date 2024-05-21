/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_second.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:57:41 by apetitco          #+#    #+#             */
/*   Updated: 2024/05/21 18:47:03 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "stack_funcs.h"
#include "push_swap.h"

int	check_for_opti(t_stack **stack_a, t_stack **stack_b, int pos_a, int pos_b)
{
	int	i;
	int	len_a;
	int	len_b;

	i = 0;
	len_a = get_stack_len(stack_a);
	len_b = get_stack_len(stack_b);
	if (pos_a <= len_a / 2 && pos_b <= len_b / 2)
	{
		while (i <= pos_a - 1 && i <= pos_b - 1)
		{
			rotate(stack_a, stack_b, rr);
			i++;
		}
	}
	if (pos_a > len_a / 2 && pos_b > len_b / 2)
	{
		while (i < len_a - pos_a && i < len_b - pos_b)
		{
			reverse_rotate(stack_a, stack_b, rrr);
			i++;
		}
	}
	return (i);
}

void	rr_rra(t_stack **stack_a, t_stack **stack_b, int pos_a, int i)
{
	if (pos_a <= get_stack_len(stack_a) / 2)
	{
		while (i <= pos_a - 1)
		{
			rotate(stack_a, stack_b, ra);
			++i;
		}
	}
	else
	{
		while (i < get_stack_len(stack_a) - pos_a)
		{
			reverse_rotate(stack_a, stack_b, rra);
			++i;
		}
	}
	return ;
}

void	replace_stack(t_stack **stack_a, t_stack **stack_b)
{
	int		min;
	int		index;
	t_stack	*nav;

	nav = *stack_a;
	min = get_min(stack_a);
	while ((*stack_a)->value != min)
	{
		index = get_index(stack_a, min);
		if (index <= get_stack_len(stack_a) / 2)
			while ((*stack_a)->value != min)
				rotate(stack_a, stack_b, ra);
		else
			while ((*stack_a)->value != min)
				reverse_rotate(stack_a, stack_b, rra);			
	}
}

void	insertion_sort(t_stack **stack_a, t_stack **stack_b, int best_move)
{
	int	i;
	int	pos_a;
	int	pos_b;

	pos_a = get_pos_to_place(stack_a, best_move);
	pos_b = get_index(stack_b, best_move);
	i = check_for_opti(stack_a, stack_b, pos_a, pos_b);
	while ((*stack_b)->value != best_move)
	{
		if (pos_b <= get_stack_len(stack_b) / 2)
			rotate(stack_a, stack_b, rb);
		else
			reverse_rotate(stack_a, stack_b, rrb);
	}
	rr_rra(stack_a, stack_b, pos_a, i);
	push_stack(stack_a, stack_b, pa);
}

void	optimize_a(t_stack **stack_a, t_stack **stack_b, t_mq *mq)
{
	mq->len -= get_stack_len(stack_a);
	while (mq->len)
	{
		insertion_sort(stack_a, stack_b, get_best_move(stack_a, stack_b));
		mq->len--;
	}
	replace_stack(stack_a, stack_b);
	return ;
}