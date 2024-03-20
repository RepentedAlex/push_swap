/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:40:57 by apetitco          #+#    #+#             */
/*   Updated: 2024/03/20 21:06:41 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/include/libft.h"
#include "../include/stacks.h"
#include "../include/push_swap_utils.h"

t_stack	*ft_lstnew(int	content)
{
	t_stack	*new;

	new = malloc(1 * sizeof(t_stack));
	if (!new)
		return (NULL);
	new->number = content;
	new->next = NULL;
	return (new);
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

t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*last_el;

	last_el = lst;
	if (lst == NULL)
		return (NULL);
	while (last_el->next != NULL)
	{
		last_el = last_el->next;
	}
	return (last_el);
}
