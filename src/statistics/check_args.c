/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:58:18 by apetitco          #+#    #+#             */
/*   Updated: 2024/05/15 12:35:14 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

char	**args_support(int argc, char *argv[])
{
	int		i;
	char	**ret;

	if (argc == 2)
		return (ft_split(argv[1], ' '));
	return (NULL);
}

int	atoi_check(const char *ptr, int *error)
{
	char	*tmp;

	if (ft_strlen(ptr) > 11)
	{
		*error = 1;
		return (1);
	}
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
