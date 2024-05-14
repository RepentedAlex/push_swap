/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:53:48 by apetitco          #+#    #+#             */
/*   Updated: 2024/05/14 17:12:42 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"
#include "push_swap.h"

void	sort_three(t_stack **to_sort, t_stack **other)
{
	t_stack	*tmp;
	int		min;
	int		max;

		min = get_min(*to_sort);
		max = get_max(*to_sort);
	while (is_sorted(*to_sort) != 1)
	{
		tmp = *to_sort;
		if (tmp->value == min)
		{
			if (tmp->next->value == max)
				rotate(to_sort, other, ra);
		}
		else if (tmp->value == max)
			reverse_rotate(to_sort, other, rra);
		else
		{
			if (tmp->next->value == min)
				swap(*to_sort, *other, sa);
			else if (tmp->next->value == max)
				rotate(to_sort, other, ra);
		}	
	}
}
