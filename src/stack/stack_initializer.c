/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_initializer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 12:52:30 by apetitco          #+#    #+#             */
/*   Updated: 2024/05/16 18:30:05 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

int	init_stack(t_stack **stack_a, char **split, t_stack **stack_b)
{
	int	i;
	int	j;
	
	i = 0;
	*stack_a = NULL;
	*stack_b = NULL;
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