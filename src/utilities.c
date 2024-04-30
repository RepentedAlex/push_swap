/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:48:08 by apetitco          #+#    #+#             */
/*   Updated: 2024/04/30 15:44:36 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/include/ft_printf.h"

void	exit_handler(int error)
{
	if (error == 1)
	{
		ft_putstr_fd("Wrong command, use as follows:\n", 2);
		ft_putstr_fd("./push_swap [(-)0-9] [(-)0-9] ...\n", 2);
		ft_putstr_fd("USE NUMBERS ONLY, I DON'T KNOW HOW TO SORT LETTERS!\n", 2);
		exit(EXIT_FAILURE);
	}
}
