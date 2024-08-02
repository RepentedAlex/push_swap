/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:10:04 by apetitco          #+#    #+#             */
/*   Updated: 2024/08/02 11:32:05 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"
#include "stack_funcs.h"
#include <stdio.h>

int	add_to_list(t_stack **stack, int num)
{
	t_stack	*node;

	node = new_node(num);
	if (!node)
		return (-1);
	if (*stack == NULL)
	{
		*stack = node;
		(*stack)->next = *stack;
		(*stack)->prev = *stack;
	}
	else
	{
		node->prev = (*stack)->prev;
		node->next = *stack;
		(*stack)->prev->next = node;
		(*stack)->prev = node;
		(*stack) = node;
	}
	return (1);
}

void	free_everything(t_stack **stack_a, t_stack **stack_b, t_mq **mq)
{
	if (*stack_a != NULL)
		free_stack(stack_a);
	if (mq != NULL)
		free(*mq);
	if (*stack_b != NULL)
		free_stack(stack_b);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;

	if (*stack == NULL)
		return ;
	tmp = NULL;
	last = (*stack)->prev;
	if (!last)
		return ;
	while (*stack && *stack != last)
	{
		tmp = (*stack)->next;
		if (!tmp)
			break ;
		free(*stack);
		*stack = tmp;
	}
	free(*stack);
}

int	get_stack_len(t_stack **stack)
{
	int		size;
	t_stack	*nav;

	if (!stack)
		return (0);
	nav = *stack;
	size = 1;
	while (nav != NULL && nav->next != *stack)
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
