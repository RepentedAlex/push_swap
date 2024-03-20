/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:23:23 by apetitco          #+#    #+#             */
/*   Updated: 2024/03/20 21:06:45 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/include/libft.h"
#include "../include/stacks.h"
#include "../include/push_swap_utils.h"

t_stack	**init_a_stack(t_stack *a_stack, int *values, int argc)
{
	int		i;
	t_stack	*node;
	t_stack	**head;

	(void)a_stack;

	i = 0;
	while (i < argc - 1)
	{
		if (i == 0)
		{
			node = ft_lstnew(values[i]);
			head = &node;
		}
		ft_lstadd_back(head, ft_lstnew(values[i]));
	}
	return (head);
}
