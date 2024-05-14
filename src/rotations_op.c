/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:11:16 by apetitco          #+#    #+#             */
/*   Updated: 2024/05/14 17:40:37 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"
#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"

static void	rotate_internal(t_stack **stack)
{
	t_stack	*last;
	t_stack	*antepenultieme;

	antepenultieme = *stack;
	while (antepenultieme->next->next != NULL)
		antepenultieme = antepenultieme->next;
	last = antepenultieme->next;
	last->next = *stack;
	antepenultieme->next = NULL;
	*stack = last;
}

void	rotate(t_stack **stack_a, t_stack **stack_b, t_operations operation)
{	
	ft_printf("r%c\n", (operation == ra) * 'a' + \
	(operation == rb) * 'b' + (operation == rr) * 'r');
	if ((ft_lstsize(*stack_a) < 2 && operation == ra) \
	|| (ft_lstsize(*stack_b) < 2 && operation == rb))
		return ;
	if (operation == ra || operation == rr)
		rotate_internal(stack_a);
	if (operation == rb || operation == rr)
		rotate_internal(stack_b);
	return ;
}

static void	reverse_rotate_internal(t_stack **stack)
{
	t_stack	*first;
	t_stack	*nav;

	if (!stack || !*stack)
		return ;
	first = *stack;
	nav = ft_lstlast(*stack);
	nav->next = first;
	*stack = first->next;
	first->next = NULL;
	return ;
}

void	reverse_rotate(t_stack **stack_a, t_stack **stack_b, \
t_operations operation)
{
	ft_printf("rr%c\n", (operation == rra) * 'a' + \
	(operation == rrb) * 'b' + (operation == rrr) * 'r');
	if ((ft_lstsize(*stack_a) < 2 && operation == rra) \
	|| (ft_lstsize(*stack_b) < 2 && operation == rrb))
		return ;
	if (operation == rra || operation == rrr)
		reverse_rotate_internal(stack_a);
	if (operation == rrb || operation == rrr)
		reverse_rotate_internal(stack_b);
	return ;
}

t_stack	*ft_lstlast(t_stack *stack)
{
	t_stack	*nav;

	nav = stack;
	if (!nav)
		return NULL;
	while (nav->next != stack && nav != NULL)
		nav = nav->next;
	return (nav);
}