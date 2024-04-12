/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:56:15 by apetitco          #+#    #+#             */
/*   Updated: 2024/04/12 19:08:28 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/include/libft.h"
#include "../include/parsing.h"
#include "../include/push_swap.h"

static enum e_bool	is_ascii_num(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if ((i == 0 && str[i] == '-') || (str[i] >= '0' && str[i] <= '9'))
			i++;
		else
			return (no);
	}	
	return (yes);
}

static enum e_bool	check_duplicates(int argc, char *array)
{
	int	i;
	int	j;
	
	i = 0;
	while (i <= argc)
	{
		j = i;
		while (j <= argc)
		{
			//TO-DO: CONVERTIR ASCII EN INT POUR POUVOIR CHECKER LES DOUBLONS
			if (ft_atoi(array[i]) == ft_atoi(array[j]))
				return (yes);
			j++;
		}
		i++;
	}
	return (no);
}

enum e_bool	valid_command(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i <= argc)
	{
		if (is_ascii_num(argv[i]) == no)
			return (no);
		i++;
	}
	if (check_duplicates(argc - 1, argv[i]) == yes)
		return (no);
	return (yes);
}
