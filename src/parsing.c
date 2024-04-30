/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:56:15 by apetitco          #+#    #+#             */
/*   Updated: 2024/04/30 15:43:46 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/include/libft.h"
#include "../include/parsing.h"
#include "../include/push_swap.h"

static bool	is_ascii_num(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if ((i == 0 && str[i] == '-') || (str[i] >= '0' && str[i] <= '9'))
			i++;
		else
			return (false);
	}	
	return (true);
}

static bool	check_duplicates(int argc, char **array)
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
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

bool	valid_command(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i <= argc)
	{
		if (is_ascii_num(argv[i]) == false)
			return (false);
		i++;
	}
	if (check_duplicates(argc - 1, argv) == true)
		return (false);
	return (true);
}