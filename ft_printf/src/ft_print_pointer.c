/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:26:59 by apetitco          #+#    #+#             */
/*   Updated: 2024/04/12 18:00:11 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../../Libft/include/libft.h"

int	ft_pointer_len(uintptr_t nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		len++;
		nb /= 16;
	}
	return (len);
}

void	ft_put_pointer(uintptr_t nb)
{
	if (nb >= 16)
	{
		ft_put_pointer(nb / 16);
		ft_put_pointer(nb % 16);
	}
	else
	{
		if (nb <= 9)
			ft_putchar_fd((nb + '0'), 1);
		else
			ft_putchar_fd((nb - 10 + 'a'), 1);
	}
}

int	ft_print_pointer(unsigned long long ptr)
{
	int	print_len;

	print_len = 0;
	if (ptr == 0)
	{
		print_len += write(1, "(nil)", 5);
	}
	else
	{
		print_len += write(1, "0x", 2);
		ft_put_pointer(ptr);
		print_len += ft_pointer_len(ptr);
	}
	return (print_len);
}
