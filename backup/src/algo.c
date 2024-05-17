/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:03:41 by apetitco          #+#    #+#             */
/*   Updated: 2024/05/17 11:00:06 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"

int	check_for_opti(t_stack **stack_a, t_stack **stack_b, int pos_a, int pos_b)
{
	int	i;
	int	len_a;
	int	len_b;

	i = 0;
	len_a = ft_lstsize(*stack_a);
	len_b = ft_lstsize(*stack_b);
	if ((pos_a <= (len_a / 2)) && (pos_b <= (len_b / 2)))
	{
		while (i <= (pos_a - 1) && i <= (pos_b - 1))
		{
			rotate(stack_a, stack_b, rr);
			i++;
		}
	}
	if ((pos_a > (len_a / 2)) && (pos_b > (len_b / 2)))
	{
		while (i < (len_a - pos_a) && i < (len_b - pos_b))
		{
			reverse_rotate(stack_a, stack_b, rrr);
			i++;
		}
	}
	return (i);
}

void	insertion_sort(t_stack **stack_a, t_stack **stack_b, int best_move)
{
	int	pos_a;
	int	pos_b;
	int	i;

	pos_a = get_pos_to_place((*stack_a), best_move);
	pos_b = get_index((*stack_b), best_move);
	i = check_for_opti(stack_a, stack_b, pos_a, pos_b);
	while ((*stack_b)->value != best_move)
	{
		if (pos_b <= (ft_lstsize(*stack_b) / 2))
			rotate(stack_a, stack_b, rb);
		else
			reverse_rotate(stack_a, stack_b, rrb);
	}
	*stack_a = ra_rra(*stack_a, pos_a, i);
	push_stack(stack_a, stack_b, pa);
}

void	optimize_a(t_stack *stack_a, t_stack *stack_b, t_quartiles *quartiles)
{
	quartiles->len -= 3;
	while (quartiles->len)
	{
		insertion_sort(&stack_a, &stack_b, get_best_move(stack_a, stack_b));
		quartiles->len--;
	}
	replace_pile(&stack_a);
	stack_b = NULL;
	free_everything(&stack_a, &stack_b, &quartiles);
	exit(1);
}

void	optimize_b(t_stack *stack_a, t_stack *stack_b, t_quartiles *quartiles)
{
	while (inner(stack_a, quartiles->q1, quartiles->q3))
	{
		if (stack_a->value >= quartiles->q1 && stack_a->value <= quartiles->med)
		{
			push_stack(&stack_a, &stack_b, pb);
			rotate(&stack_a, &stack_b, rb);
			continue ;
		}
		if (stack_a->value <= quartiles->q3 && stack_a->value >= quartiles->med)
		{
			push_stack(&stack_a, &stack_b, pb);
			continue ;
		}
		else
			rotate(&stack_a, &stack_b, ra);
	}
	while (ft_lstsize(stack_a) > 3)
	{
		push_stack(&stack_a, &stack_b, pb);
		if (stack_b->value < quartiles->med)
			rotate(&stack_a, &stack_b, rb);
	}
	if (!(is_sorted(stack_a)))
		sort_three(&stack_a, &stack_b);
	optimize_a(stack_a, stack_b, quartiles);
}

t_stack	*ra_rra(t_stack *stack_a, int pos_a, int i)
{
	if (pos_a <= (ft_lstsize(stack_a) / 2))
	{
		while (i <= pos_a - 1)
		{
			rotate(&stack_a, NULL, ra);
			++i;
		}
	}
	else
	{
		while (i < (ft_lstsize(stack_a) - pos_a))
		{
			reverse_rotate(&stack_a, NULL, rra);
			++i;
		}
	}
	return (stack_a);
}
