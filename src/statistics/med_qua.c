/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   med_qua.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:43:07 by apetitco          #+#    #+#             */
/*   Updated: 2024/05/17 15:36:12 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

static void	swap_el(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	partition(int array[], int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = array[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap_el(&array[i], &array[j]);
		}
		j++;
	}
	swap_el(&array[i + 1], &array[high]);
	return (i + 1);
}

static void	quick_sort(int array[], int low, int high)
{
	int	pivot;

	if (low < high)
	{
		pivot = partition(array, low, high);
		quick_sort(array, low, pivot - 1);
		quick_sort(array, pivot + 1, high);
	}	
}

static void	doublon_check(int array[], int len, t_mq **mq)
{
	int	i;
	int	tmp;
	int	l;

	i = 0;
	tmp = array[0];
	l = 1;
	while (++i < len)
	{
		if (array[i] == tmp)
			l = 0;
		tmp = array[i];
	}
	(*mq)->len = len;
	if (!l)
		(*mq)->len = l;
	(*mq)->med = (len + 1) / 2;
	fill_mq(mq, len, array);
}

void	get_mq(char **split, t_mq **mq, int *error)
{
	int	*array;
	int	i;
	int	len;

	len = 0;
	while (split[len] && split != NULL)
		len++;
	array = malloc(sizeof(int) * len);
	if (!array || !split)
	{
		*mq = NULL;
		return ;
	}
	i = len;
	while (i-- > 0)
	{
		array[i] = atoi_check(split[i], error);
		free(split[i]);
	}
	free(split);
	quick_sort(array, 0, len - 1);
	doublon_check(array, len, mq);
	(*mq)->med = array[((*mq)->med) - 1];
	free(array);
}
