/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translations_op.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:29:08 by apetitco          #+#    #+#             */
/*   Updated: 2024/05/15 12:26:24 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"

//! NOT ADAPTATED FOR DOUBLY LINKED LISTS !//
static void	swap_internal(t_stack *stack)
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
	if ((ft_lstsize(stack_a) < 2 && operation == sa) \
	|| (ft_lstsize(stack_b) < 2 && operation == sb))
		return ;
	ft_printf("s%c\n", (operation == sa) * 'a' + \
	(operation == sb) * 'b' + (operation == ss) * 's');
	if (operation == sa || operation == ss)
		swap_internal(stack_a);
	if (operation == sb || operation == ss)
		swap_internal(stack_b);
	return ;
}

//! NOT ADAPTATED FOR DOUBLY LINKED LISTS !//
static void	push_internal(t_stack **receiver, t_stack **sender)
{
	t_stack	*new_first;

	new_first = (*sender)->next;
	(*sender)->next = *receiver;
	*receiver = *sender;
	*sender = new_first;
}

void	push_stack(t_stack **stack_a, t_stack **stack_b, t_operations operation)
{
	ft_printf("p%c\n", (operation == pa) * 'a' + (operation == pb) * 'b');
	if (operation == pa)
		push_internal(stack_a, stack_b);
	if (operation == pb)
		push_internal(stack_b, stack_a);
	return ;
}
