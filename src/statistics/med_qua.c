/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   med_qua.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:43:07 by apetitco          #+#    #+#             */
/*   Updated: 2024/05/15 11:22:16 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

void	get_mq(char **split, t_mq **mq, int *error)
{
	int	*array;
	int	i;
	int	len;

	len = 0;
	while (split[len] && split != NULL)
		++len;
	array = malloc(sizeof(int) * len);
	if (!array || !split)
	{
		*mq = NULL;
		return ;
	}
	i = len;
	while (i-- != 0)
	{
		array[i] = atoi_check(split[i], error);
		free(split[i]);
	}
	free(split);
	//quick_sort
	//doublon_check
	(*mq)->med = array[((*mq)->med)];
	free(array);
}
