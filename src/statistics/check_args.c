/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:58:18 by apetitco          #+#    #+#             */
/*   Updated: 2024/05/16 18:07:21 by apetitco         ###   ########.fr       */
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
		{
			split[i - 1] = ft_strdup(argv[i]);
			
		}
		split[argc - 1] = NULL;
		return (split);
	}
}
