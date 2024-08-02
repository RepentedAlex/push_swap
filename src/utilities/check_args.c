/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:58:18 by apetitco          #+#    #+#             */
/*   Updated: 2024/08/02 11:41:57 by apetitco         ###   ########.fr       */
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
	if (!tmp)
		return (*error = 1, 0);
	if (ft_strcmp(tmp, ptr))
		return (free(tmp), *error = 1, 1);
	free(tmp);
	return (ft_atoi(ptr));
}

void free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab[i]);
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
		split = ft_calloc((size_t)argc, sizeof(char *));
		if (!split)
			return (NULL);
		while (++i < argc) {
			split[i - 1] = ft_strdup(argv[i]);
			if (!split[i - 1])
				return (free_tab(split), NULL);
		}
		split[argc - 1] = NULL;
		return (split);
	}
}
