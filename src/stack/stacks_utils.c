/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:36:04 by apetitco          #+#    #+#             */
/*   Updated: 2024/05/15 10:34:45 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"

int	add_to_list(t_stack **stack, int num)
{
	t_stack	*node;

	node = new_node(num);
	if (!node)
		return (-1);
	if (*stack == NULL)
	{
		*stack = node;
		*stack->next = *stack;
		*stack->prev = *stack;
	}
	else
	{
		node->prev = *stack->prev;
		node->next = *stack;
		*stack->prev->next = node;
		*stack->prev = node;
		*stack = node;
	}
	return (1);
}

void	free_everything(t_stack **stack_a, t_stack **stack_b, t_mq **mq)
{
	free_stack(stack_a);
	free_stack(stack_b);
	free(*mq);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	tmp = NULL;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

int	get_stack_len(t_stack *stack)
{
	int		size;
	t_stack	*nav;

	nav = stack;
	size = 0;
	while (nav->next != stack && nav != NULL)
	{
		nav = nav->next;
		size++;
	}
	return (size);
}

t_stack	*new_node(int num)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = num;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
