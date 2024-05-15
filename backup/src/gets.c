/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:59:37 by apetitco          #+#    #+#             */
/*   Updated: 2024/05/14 17:36:30 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"
#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"

int	get_index(t_stack *stack, int element)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = stack;
	while (tmp->next != stack)
	{
		if (tmp->value == element)
			return (i);
		tmp = tmp->next;
		++i;
	}
	return (i);
}

int	get_max(t_stack *stack)
{
	int		max;
	t_stack	*nav;

	nav = stack;
	max = nav->value;
	while (nav->next != stack && nav != NULL)
	{
		if (nav->value > max)
			max = nav->value;
		nav = nav->next;
	}
	return (max);
}

int	get_min(t_stack *stack)
{
	int		min;
	t_stack	*nav;

	nav = stack;
	min = nav->value;
	while (nav->next != stack && nav != NULL)
	{
		if (nav->value < min)
			min = nav->value;
		nav = nav->next;
	}
	return (min);
}

int	get_pos_to_place(t_stack *stack, int element)
{
	int		len;
	int		min;
	int		i;
	t_stack	*node;

	min = get_min(stack);
	if (element > get_max(stack) || element < min)
		return (get_index(stack, min));
	len = ft_lstsize(stack);
	i = -1;
	node = stack;
	while (++i < len)
	{
		if (node->prev->value < element && element < node->value)
			return (i);
		node = node->next;
	}
	return (0);
}
