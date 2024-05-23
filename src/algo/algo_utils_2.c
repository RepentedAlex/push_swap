/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:03:10 by apetitco          #+#    #+#             */
/*   Updated: 2024/05/23 14:03:57 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack_funcs.h"
#include "ft_printf.h"
#include "push_swap.h"

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
