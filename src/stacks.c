/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:13:22 by apetitco          #+#    #+#             */
/*   Updated: 2024/04/12 18:43:31 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/include/libft.h"
#include "../include/stacks.h"
#include <unistd.h>

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

static t_stack	*ft_lstnew(int content)
{
	t_stack	*new;

	new = malloc(1 * sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = content;
	new->next = NULL;
	return (new);
}

t_stack	**init_stack_a(int argc, char *argv[])
{
	int		i;
	t_stack	**head;
	t_stack	*node;

	i = 1;
	while (i <= argc)
	{
		node = ft_lstnew(ft_atoi(argv[i]));
		if (i == 1)
			head = &node;
		ft_lstadd_back(head, node);
		i++;
	}
	return (head);
}

t_stack	**init_stack_b(int argc)
{
	int		i;
	t_stack	**head;
	t_stack	*node;

	i = 1;
	while (i <= argc)
	{
		node = ft_lstnew(0);
		if (i == 1)
			head = &node;
		ft_lstadd_back(head, node);
		i++;
	}
	return (head);
}
