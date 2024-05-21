/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:05:29 by apetitco          #+#    #+#             */
/*   Updated: 2024/05/21 14:46:47 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack_funcs.h"
#include "ft_printf.h"
#include "push_swap.h"

int	get_pos_to_place(t_stack **stack, int elem)
{
	int		i;
	int		len;
	int		min;
	t_stack	*nav;

	min = get_min(stack);
	if (elem > get_max(stack) || elem < min)
		get_index(stack, min);
	len = get_stack_len(stack);
	i = -1;
	nav = *stack;
	while (++i < len)
	{
		if (nav->prev->value < elem && elem < nav->value)
			return (i);
		nav = nav->next;
	}
	return (0);	
}

int	get_index(t_stack **stack, int elem)
{
	int		i;
	t_stack	*nav;
	
	i = 0;
	nav = *stack;
	while (nav->next != *stack)
	{
		if (nav->value == elem)
			return (i);
		nav = nav->next;
		i++;
	}
	return (i);
}

static int	count_move(t_stack **stack_a, t_stack **stack_b, int elem)
{
	int	count;
	int	index;

	index = get_index(stack_b, elem);
	count = 1;
	if (index > 1 && index > (get_stack_len(stack_b) / 2))
		count += get_stack_len(stack_b) - index - 1;
	else if (index > 1 && index <= (get_stack_len(stack_b) / 2))
		count += index - 1;
	index = get_pos_to_place(stack_a, elem);
	if (index > 1 && index > (get_stack_len(stack_a) / 2))
		count += get_stack_len(stack_a) - index - 1;
	else if (index > 1 && index <= (get_stack_len(stack_a) / 2))
		count += index - 1;
	return (count);
}

int	get_best_move(t_stack **stack_a, t_stack **stack_b)
{
	int		best_element;
	int		best_move_count;
	int		cur_move_count;
	t_stack	*nav;

	best_element = (*stack_b)->value;
	best_move_count = count_move(stack_a, stack_b, best_element);
	nav = (*stack_b)->next;
	while (nav != *stack_b && nav != NULL)
	{
		cur_move_count = count_move(stack_a, stack_a, nav->value);
		if (cur_move_count < best_move_count)
		{
			best_move_count = cur_move_count;
			best_element = nav->value;
		}
		nav = nav->next;
	}
	return (best_element);
}

int	get_max(t_stack **stack)
{
	int		i;
	int		len;
	int		max;
	t_stack	*nav;

	len = get_stack_len(stack);
	nav = *stack;
	max = nav->value;
	i = 0;
	while (nav != NULL && i++ < len)
	{
		if (nav->value > max)
			max = nav->value;
		nav = nav->next;
	}
	return (max);
}

int	get_min(t_stack **stack)
{
	int		i;
	int		len;
	int		min;
	t_stack	*nav;

	len = get_stack_len(stack);
	nav = *stack;
	min = nav->value;
	i = 0;
	while (nav != NULL && i++ < len)
	{
		if (nav->value < min)
			min = nav->value;
		nav = nav->next;
	}
	return (min);
}
