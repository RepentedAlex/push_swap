/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:54:45 by apetitco          #+#    #+#             */
/*   Updated: 2024/05/16 14:50:01 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"
#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"

int	count_moves(t_stack *stack_a, t_stack *stack_b, int element)
{
	int	count;
	int	index;

	index = get_index(stack_b, element);
	count = 1;
	if (index > 1 && index > (ft_lstsize(stack_b) / 2))
		count += ft_lstsize(stack_b) - index - 1;
	else if (index > 1 && index <= (ft_lstsize(stack_b) / 2))
		count += index - 1;
	index = get_pos_to_place(stack_a, element);
	if (index > 1 && index > (ft_lstsize(stack_a) / 2))
		count += ft_lstsize(stack_a) - index - 1;
	else if (index > 1 && index <= (ft_lstsize(stack_a) / 2))
		count += index - 1;
	return (count);
}

int	get_best_move(t_stack *stack_a, t_stack *stack_b)
{
	int		best_element;
	int		best_move;
	int		move_count;
	t_stack	*nav;

	best_element = stack_b->value;
	best_move = count_moves(stack_a, stack_b, best_element);
	nav = stack_b->next;
	while (nav != stack_b && nav != NULL)
	{
		move_count = count_moves(stack_a, stack_b, nav->value);
		if (move_count < best_move)
		{
			best_move = move_count;
			best_element = nav->value;
		}
		nav = nav->next;
	}
	return (best_move);
}

int	inner(t_stack *stack, int q1, int q3)
{
	t_stack	*tmp;
	int		len;
	int		i;

	len = ft_lstsize(stack);
	i = 0;
	tmp = stack;
	while (i < len)
	{
		if (q1 <= tmp->value && tmp->value <= q3)
			return (1);
		tmp = tmp->next;
		++i;
	}
	return (0);
}

void	replace_pile(t_stack **stack)
{
	int		min;
	int		index;
	t_stack	*stack_a;

	stack_a = *stack;
	min = get_min(stack_a);
	if (stack_a->value != min)
	{
		index = get_index(stack_a, min);
		if (index <= ft_lstsize(stack_a) / 2)
			while (stack_a->value != min)
				rotate(&stack_a, NULL, ra);
		else
			while (stack_a->value != min)
				reverse_rotate(&stack_a, NULL, rra);
	}
	*stack = stack_a;
}
