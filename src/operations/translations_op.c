/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translations_op.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:29:08 by apetitco          #+#    #+#             */
/*   Updated: 2024/05/21 17:45:11 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"
#include "stack_funcs.h"

static void	swap_internal(t_stack **stack)
{
	t_stack	*nav;
	int		tmp;

	tmp = (*stack)->value;
	nav = (*stack)->next;
	(*stack)->value = nav->value;
	nav->value = tmp;
}

void	swap(t_stack **stack_a, t_stack **stack_b, t_op op)
{
	if ((get_stack_len(stack_a) < 2 && op == sa) \
	|| (get_stack_len(stack_b) < 2 && op == sb))
		return ;
	ft_printf("s%c\n", (op == sa) * 'a' + \
	(op == sb) * 'b' + (op == ss) * 's');
	if (op == sa || op == ss)
		swap_internal(stack_a);
	if (op == sb || op == ss)
		swap_internal(stack_b);
	return ;
}

static void	push_internal(t_stack **receiver, t_stack **sender)
{
	t_stack	*tmp;
	int		len;

	tmp = *sender;
	len = get_stack_len(sender);
	if (!tmp)
		return ;
	if (add_to_list(receiver, tmp->value) == -1)
	{
		free_everything(receiver, sender, NULL);
		exit(1);
	}
	if (len == 1)
	{
		free(*sender);
		*sender = NULL;
	}
	else
	{
		(*sender)->prev->next = tmp->next;
		(*sender)->next->prev = tmp->prev;
		(*sender) = tmp->next;
		free(tmp);
	}
}

void	push_stack(t_stack **stack_a, t_stack **stack_b, t_op op)
{
	ft_printf("p%c\n", (op == pa) * 'a' + (op == pb) * 'b');
	if (op == pa)
		push_internal(stack_a, stack_b);
	if (op == pb)
		push_internal(stack_b, stack_a);
	return ;
}
