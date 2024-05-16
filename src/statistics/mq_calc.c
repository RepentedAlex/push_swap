/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mq_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 12:39:16 by apetitco          #+#    #+#             */
/*   Updated: 2024/05/16 14:12:24 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

void	fill_mq(t_mq **mq, int len, int array[])
{
	if (len % 2 == 0)
		(*mq)->med = len / 2;
	(*mq)->q1 = (((*mq)->med + 1) / 2);
	if ((*mq)->med % 2 == 0)
		(*mq)->q1 = ((*mq)->med / 2);
	(*mq)->q3 = ((*mq)->med + (*mq)->q1);
	if (len > 5)
	{
		(*mq)->q1 = array[(*mq)->q1];
		(*mq)->q3 = array[(*mq)->q3];
	}
	else
	{
		(*mq)->q1 = 0;
		(*mq)->q3 = 0;
	}
}