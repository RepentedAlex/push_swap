/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:36:04 by apetitco          #+#    #+#             */
/*   Updated: 2024/05/14 16:26:11 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

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

int	init_stack(t_stack **stack_a, char **split)
{
	int	i;
	int	j;

	i = 0;
	stack_a = NULL;
	if (!split)
		return (-1);
	while (split[i])
		i++;
	while (--i >= 0)
	{
		j = add_to_list(stack_a, ft_atoi(split[i]));
		if (j == -1)
			return (-1);
		free(split[i]);
	}
		free(split);
		return (1);
}

void	ft_lstiter(t_stack *lst, void (*f)(int))
{
	while (lst)
	{
		f(lst->value);
		lst = lst->next;
	}
}

t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*last_el;

	last_el = lst;
	if (lst == NULL)
		return (NULL);
	while (last_el->next != NULL)
		last_el = last_el->next;
	return (last_el);
}

t_stack	*ft_lstnew(int content)
{
	t_stack	*new;

	new = malloc(1 * sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = content;
	new->next = NULL;
	return (new);
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

void free_everything(t_stack **stack_a, t_stack **stack_b, t_quartiles **quartiles)
{
	ft_stack_clear(stack_a);
	ft_stack_clear(stack_b);
	free(*quartiles);
}