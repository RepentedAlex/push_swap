/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:36:04 by apetitco          #+#    #+#             */
/*   Updated: 2024/05/14 17:12:16 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	add_to_list(t_stack **stack, int num)
{
	t_stack	*node;

	if (new_node(num, &node) == -1)
		return (-1);
	if ((*stack) == NULL)
	{
		(*stack) = node;
		(*stack)->next = *stack;
		(*stack)->prev = *stack;
	}
	else
	{
		node->prev = (*stack)->prev;
		node->next = (*stack);
		(*stack)->prev->next = node;
		(*stack)->prev = node;
		(*stack) = node;
	}
	return (1);
}

void	free_everything(t_stack **stack_a, t_stack **stack_b, \
t_quartiles **quartiles)
{
	ft_stack_clear(stack_a);
	ft_stack_clear(stack_b);
	free(*quartiles);
}

int	new_node(int num, t_stack **node)
{
	(*node) = malloc(sizeof(t_stack));
	if (!node)
		return (-1);
	(*node)->value = num;
	(*node)->next = NULL;
	(*node)->prev = NULL;
	return (1);
}

int	ft_lstsize(t_stack *stack)
{
	int	size;

	if (stack == NULL)
		return (0);
	size = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

void	ft_stack_clear(t_stack **stack)
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
