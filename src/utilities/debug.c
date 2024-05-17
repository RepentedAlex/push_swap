/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:16:40 by apetitco          #+#    #+#             */
/*   Updated: 2024/05/17 17:39:50 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"

static void	dump_node(int val)
{
	ft_printf("val %d\n", val);
}

static void	ft_lstiter(t_stack *lst, void (*f)(int))
{
	t_stack	*first;

	if (!lst)
		return ;
	first = lst->prev;
	f(lst->value);
	while (lst != first)
	{
		lst = lst->next;
		f(lst->value);
	}
}

void	debug_stacks(t_stack *a, t_stack *b)
{
	ft_printf("Stack a:\n");
	ft_lstiter(a, dump_node);
	ft_printf("Stack b:\n");
	ft_lstiter(b, dump_node);
}
