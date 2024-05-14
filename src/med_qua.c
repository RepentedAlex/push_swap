/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   med_qua.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:06:08 by apetitco          #+#    #+#             */
/*   Updated: 2024/05/14 17:08:02 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"
#include "push_swap.h"

void	fill_med_qua(t_quartiles **quartiles, int len, int array[])
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
