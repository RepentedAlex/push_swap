/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:03:41 by apetitco          #+#    #+#             */
/*   Updated: 2024/05/14 16:51:50 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"
#include "push_swap.h"

void	launch_algo(t_stack *stack_a, t_stack *stack_b, t_quartiles *quartiles)
{
	if (quartiles->len == 2 && stack_a->value > stack_a->next->value)
		write(1, "sa\n", 3);
	if (quartiles->len > 2 && !is_sorted(stack_a))
		optimize_b(stack_a, stack_b, quartiles);
	free_everything(&stack_a, &stack_b, &quartiles);
	exit(1);
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
