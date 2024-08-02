/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:58:18 by apetitco          #+#    #+#             */
/*   Updated: 2024/08/01 10:39:11 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

int	atoi_check(const char *ptr, int *error)
{
	char		*tmp;
	long long	val;

	val = ft_atoi(ptr);
	if (!(INT32_MIN <= val && val <= INT32_MAX))
		return (*error = 1, 1);
	tmp = ft_itoa(val);
	if (ft_strcmp(tmp, ptr))
		return (free(tmp), *error = 1, 1);
	free(tmp);
	return (ft_atoi(ptr));
}

char	**args_support(int argc, char *argv[])
{
	int		i;
	char	**split;

	if (argc == 2)
		return (ft_split(argv[1], ' '));
	else
	{
		i = 0;
		split = malloc(sizeof(char *) * argc);
		while (++i < argc)
			split[i - 1] = ft_strdup(argv[i]);
		split[argc - 1] = NULL;
		return (split);
	}
}
