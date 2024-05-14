/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:18:48 by apetitco          #+#    #+#             */
/*   Updated: 2024/05/14 16:33:14 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "algo.h"
#include "push_swap.h"

/**
 * Normal
 * * Important
 * ! Deprecated
 * ? Interrogation
 * TODO: refactor
 * //Fait
 * @param myParam Parameter for this function
*/

/**
 * Check que les arguments passés en CLI sont valides
 * @param ptr Les arguments
 * @param error Flag erreur
*/
int	atoi_check(const char *ptr, int *error)
{
	char	*tmp;
	
	if (ft_strlen(ptr) > 11)
	{
		*error = 1;
		return (1);
	}
	tmp = ft_itoa(ft_atoi(ptr));
	if (!ft_strcmp(tmp, ptr))
	{
		free(tmp);
		*error = 1;
		return (1);
	}
	free(tmp);
	return (ft_atoi(ptr));
}

/**
 * Check s'il y a des doublons dans le tableau et met à jour la structure comportant les quartiles.
 *
 * @param array Le tableau dans lequel la vérification des doublons se fait.
 * @param len La longueur du tableau.
 * @param quartiles Pointeur vers la structure comportant les quartiles.
 */
static void doublon_check(int array[], int len, t_quartiles **quartiles)
{
	int i;
	int tmp;
	int l;

	i = 0;
	tmp = array[0];
	l = 1;
	while (++i < len)
	{
		if (array[i] == tmp)
			l = 0;
		tmp = array[i];
	}
	(*quartiles)->len = len;
	if (!l)
		(*quartiles)->len = l;
	(*quartiles)->med = (len + 1) / 2;
	fill_med_qua(quartiles, len, array);
}

/**
 * Calculates the quartiles of an array and fills the corresponding quartile struct.
 *
 * @param quartiles - A pointer to the quartiles struct.
 * @param len - The length of the array.
 * @param array - The array of integers.
 */
void fill_med_qua(t_quartiles **quartiles, int len, int array[])
{
	if (len % 2 == 0)
		(*quartiles)->med = len / 2;
	(*quartiles)->q1 = (((*quartiles)->med + 1) / 2);
	if ((*quartiles)->med % 2 == 0)
		(*quartiles)->q1 = ((*quartiles)->med) / 2;
	(*quartiles)->q3 = ((*quartiles)->med) + ((*quartiles)->q1);
	if (len > 5)
	{
		(*quartiles)->q1 = array[(*quartiles)->q1];
		(*quartiles)->q3 = array[(*quartiles)->q3];
	}
	else
	{
		(*quartiles)->q1 = 0;
		(*quartiles)->q3 = 0;
	}
}

/**
 * Calculates the quartiles of an array of integers obtained from a string split.
 * 
 * @param split The array of strings obtained from splitting a string.
 * @param quartiles A pointer to a t_quartiles struct to store the quartiles.
 * @param error A pointer to an integer to store any error code.
 */
void	get_med_qua(char **split, t_quartiles **quartiles, int *error)
{
	int	len;
	int	i;
	int	*array;

	len = 0;
		while (split[len] && split != NULL)
		++len;
	array = malloc(sizeof(int) * len);
	if (!array || !split)
	{
		*quartiles = NULL;
		return ;
	}
	i = len;
	while (--i != -1)
	{
		array[i] = atoi_check(split[i], error);
		free(split[i]);
	}
	free(split);
	quick_sort(array, 0, len - 1);
	doublon_check(array, len, quartiles);
	(*quartiles)->med = array[((*quartiles)->med)];
	free(array);
}

static void	swap_el(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * Partitions the given array using the last element as the pivot.
 * 
 * @param array The array to be partitioned.
 * @param low The starting index of the partition.
 * @param high The ending index of the partition.
 * @return The index of the pivot element after partitioning.
 */
static int	partition(int array[], int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = array[high];
	i = (low - 1);
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

/**
 * Effectue un tri à la volée pour savoir comment les valeurs devront être ordonnées
 * @param array Le tableau comportant toutes les valeurs
 * @param low Plus basse valeur
 * @param high Plus haute valeur
*/
void	quick_sort(int array[], int low, int high)
{
	int	pivot;

	if (low < high)
	{
		pivot = partition(array, low, high);
		quick_sort(array, low, pivot - 1);
		quick_sort(array, pivot + 1 , high);
	}
}

void	sort_three(t_stack **to_sort, t_stack **other)
{
	t_stack	*tmp;
	int		min;
	int		max;
	
		min = get_min(*to_sort);
		max = get_max(*to_sort);
	while (is_sorted(*to_sort) != 1)
	{
		tmp = *to_sort;
		if (tmp->value == min)
		{
			if (tmp->next->value == max)
				rotate(to_sort, other, ra);
		}
		else if (tmp->value == max)
			reverse_rotate(to_sort, other, rra);
		else
		{
			if (tmp->next->value == min)
				swap(*to_sort, *other, sa);
			else if (tmp->next->value == max)
				rotate(to_sort, other, ra);
		}	
	}
}
