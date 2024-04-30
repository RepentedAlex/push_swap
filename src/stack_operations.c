/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessandropetitcollin <alessandropetitc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:35:00 by apetitco          #+#    #+#             */
/*   Updated: 2024/04/30 22:55:47 by alessandrop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"
#include "stacks.h"

static void	rotate_internal(t_stack **stack)
{
	t_stack	*nav;
	int		tmp;

	tmp = stack->value;
	nav = stack->next;
	stack->value = nav->value;
	nav->value = tmp;
}

void	swap(t_stack *stack_a, t_stack *stack_b, t_operations operation)
{
	if (ft_lstsize(stack_a) < 2 || ft_lstsize(stack_b) < 2)
		return ;
	ft_printf("s%c\n", (operation == sa) * 'a' + (operation == sb) * 'b' + (operation == ss) * 's');
	if (operation == sa || operation == ss)
		rotate_internal(stack_a);
	if (operation == sb || operation == ss)
		rotate_internal(stack_b);
	return ;
}

static void	push_internal(t_stack **stack_a, t_stack **stack_b)
{
}

void	push(t_stack *stack_a, t_stack *stack_b, t_operations operation)
{
	ft_printf("p%c\n", (operation == pa) * 'a' + (operation == pb) * 'b');
	if (operation == pa)
		push_internal(stack_a, stack_b);
	if (operation == pb)
		push_internal(stack_a, stack_b);
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
