/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:44:52 by apetitco          #+#    #+#             */
/*   Updated: 2024/05/08 13:46:04 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"

static void dump_node(int val)
{
	ft_printf("val %d\n", val);
}

void debug_stacks(t_stack *a, t_stack *b)
{
	ft_printf("Stack a:\n");
	ft_lstiter(a, dump_node);
	ft_printf("Stack b:\n");
	ft_lstiter(b, dump_node);
}