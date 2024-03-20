/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:35:24 by apetitco          #+#    #+#             */
/*   Updated: 2024/03/20 21:08:28 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/include/libft.h"
#include "../include/stacks.h"
#include "../include/push_swap_utils.h"

int	*ft_atoiv(char *argv[], int n)
{
	int	i;
	int	*array;

	array = (int *)malloc(sizeof(int) * n);
	if (!array)
		return (NULL);
	i = 0;
	while (i < n)
	{
		array[i] = atoi(argv[i + 1]);
		i++;
	}
	return (array);
}
