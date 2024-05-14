/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tweak_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:07:06 by apetitco          #+#    #+#             */
/*   Updated: 2024/05/14 17:12:30 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"
#include "push_swap.h"

int	atoi_check(const char *ptr, int *error)
{
	char	*tmp;

	if (ft_strlen(ptr) > 11)
	{
		*error = 1;
		return (1);
	}
	tmp = ft_itoa(ft_atoi(ptr));
	if (!ft_strcmp(tmp, ptr))
	{
		free(tmp);
		*error = 1;
		return (1);
	}
	free(tmp);
	return (ft_atoi(ptr));
}
