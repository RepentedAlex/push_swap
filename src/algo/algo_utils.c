/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:05:29 by apetitco          #+#    #+#             */
/*   Updated: 2024/05/17 15:02:27 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

int	get_max(t_stack *stack)
{
	int		i;
	int		len;
	int		max;
	t_stack	*nav;

	len = get_stack_len(stack);
	nav = stack;
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

int	get_min(t_stack *stack)
{
	int		i;
	int		len;
	int		min;
	t_stack	*nav;

	len = get_stack_len(stack);
	nav = stack;
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