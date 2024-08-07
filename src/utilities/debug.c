/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:16:40 by apetitco          #+#    #+#             */
/*   Updated: 2024/05/21 17:38:29 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

static void	dump_node(int val)
{
	fprintf(stderr, "val %d\n", val);
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
	fprintf(stderr, "Stack a:\n");
	if (!a)
		fprintf(stderr, "tout vide\n");
	else
		ft_lstiter(a, dump_node);
	fprintf(stderr, "Stack b:\n");
	if (!b)
		fprintf(stderr, "tout vide\n");
	else
		ft_lstiter(b, dump_node);
}
