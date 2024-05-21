/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:21:35 by apetitco          #+#    #+#             */
/*   Updated: 2024/05/21 16:36:25 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"
#include "stack_funcs.h"

static void	rotate_internal(t_stack **stack)
{
	if (!stack || !*stack)
		return ;
	*stack = (*stack)->next;
	return ;
}

void	rotate(t_stack **stack_a, t_stack **stack_b, t_op op)
{
	ft_printf("r%c\n", (op == ra) * 'a' + (op == rb) * 'b' + (op == rr) * 'r');
	if ((get_stack_len(stack_a) < 2 && op == ra) \
	|| (get_stack_len(stack_b) < 2 && op == rb))
		return ;
	if (op == ra || op == rr)
		rotate_internal(stack_a);
	if (op == rb || op == rr)
		rotate_internal(stack_b);
	// debug_stacks(*stack_a, *stack_b);
	return ;
}

static void	reverse_rotate_internal(t_stack **stack)
{
	if (!stack || !*stack)
		return ;
	*stack = (*stack)->prev;
	return ;
}

void	reverse_rotate(t_stack **stack_a, t_stack **stack_b, \
t_op op)
{
	ft_printf("rr%c\n", (op == rra) * 'a' + \
	(op == rrb) * 'b' + (op == rrr) * 'r');
	if ((get_stack_len(stack_a) < 2 && op == rra) \
	|| (get_stack_len(stack_b) < 2 && op == rrb))
		return ;
	if (op == rra || op == rrr)
		reverse_rotate_internal(stack_a);
	if (op == rrb || op == rrr)
		reverse_rotate_internal(stack_b);
	// debug_stacks(*stack_a, *stack_b);
	return ;
}

t_stack	*ft_lstlast(t_stack *stack)
{
	t_stack	*nav;

	nav = stack;
	if (!nav)
		return (NULL);
	while (nav->next != stack && nav != NULL)
		nav = nav->next;
	return (nav);
}
