/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:30:55 by apetitco          #+#    #+#             */
/*   Updated: 2024/05/07 13:32:07 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

long long	ft_atoi(const char *nptr)
{
	int			i;
	long long	output;
	int			sign;

	i = 0;
	output = 0;
	sign = 1;
	while (nptr[i] == ' ' || nptr[i] <= 13)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
		{
			sign *= (-1);
		}
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		output = output * 10 + (nptr[i] - '0');
		i++;
	}
	return (sign * output);
}

/*
#include <stdio.h>

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (1);
	else
	{
		int	result = ft_atoi(argv[1]);
		printf("%d\n", result);
	}
}
*/
