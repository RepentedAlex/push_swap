/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:58:18 by apetitco          #+#    #+#             */
/*   Updated: 2024/05/15 14:14:56 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

int	atoi_check(const char *ptr, int *error)
{
	char	*tmp;

	tmp = ft_itoa(ft_atoi(ptr));
	if (ft_strcmp(tmp, ptr))
	{
		free(tmp);
		*error = 1;
		return (1);
	}
	free(tmp);
	return (ft_atoi(ptr));
}
