/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:35:00 by apetitco          #+#    #+#             */
/*   Updated: 2024/04/30 18:42:49 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"
#include "stacks.h"
#include <stdio.h>

void	swap(t_stack *stack_a, t_stack *stack_b, t_operations operation)
{
	t_stack	*nav;
	int		tmp;

	if (ft_lstsize(stack_a) < 2 || ft_lstsize(stack_b) < 2)
		return ;
	ft_printf("s%c\n", (operation == sa) * 'a' + (operation == sb) * 'b' + (operation == ss) * 's');
	if (operation == sa || operation == ss)
	{
		tmp = stack_a->value;
		nav = stack_a->next;
		stack_a->value = nav->value;
		nav->value = tmp;
	}
	if (operation == sb || operation == ss)
	{		
		tmp = stack_b->value;
		nav = stack_b->next;
		stack_b->value = nav->value;
		nav->value = tmp;
	}
	return ;
}

void	push(t_stack *stack_a, t_stack *stack_b, t_operations operation)
{
	(void) stack_a;
	(void) stack_b;	
	(void) operation;
	return ;
}
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
	ft_printf("r%c\n", (operation == ra) * 'a' + (operation == rb) * 'b' + (operation == rr) * 'r');
	if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2)
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
	return;
}

void	reverse_rotate(t_stack **stack_a, t_stack **stack_b, t_operations operation)
{
	ft_printf("rr%c\n", (operation == rra) * 'a' + (operation == rrb) * 'b' + (operation == rrr) * 'r');
	if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2)
		return ;
	if (operation == rra || operation == rrr)
		reverse_rotate_internal(stack_a);
	if (operation == rrb || operation == rrr)
		reverse_rotate_internal(stack_b);
	return ;
}
