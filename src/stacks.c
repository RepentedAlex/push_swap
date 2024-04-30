/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:13:22 by apetitco          #+#    #+#             */
/*   Updated: 2024/04/30 17:38:14 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stacks.h"

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

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*tail;

	tail = ft_lstlast(*lst);
	if (*lst == NULL)
		*lst = new;
	else
		tail->next = new;
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

void	ft_lstiter(t_stack *lst, void (*f)(int))
{
	while (lst)
	{
		f(lst->value);
		lst = lst->next;
	}
}

void	ft_stclear(t_stack **lst)
{
	t_stack	*temp;

	if (!lst)
		return ;
	temp = NULL;
	while (*lst)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
}

t_stack	*init_stack_a(int argc, char *argv[])
{
	int		i;
	t_stack	*head;
	t_stack	*last;
	t_stack	*node;

	i = 1;
	last = NULL;
	while (i <= argc)
	{
		node = ft_lstnew(ft_atoi(argv[i]));
		if (last)
			last->next = node;
		else
			head = node;
		last = node;
		i++;
	}
	return (head);
}
