/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:05:29 by apetitco          #+#    #+#             */
/*   Updated: 2024/05/23 14:03:51 by apetitco         ###   ########.fr       */
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
		return (get_index(stack, min));
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
