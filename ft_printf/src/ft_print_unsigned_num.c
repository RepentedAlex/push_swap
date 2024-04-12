/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_num.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:29:30 by apetitco          #+#    #+#             */
/*   Updated: 2024/04/12 18:00:20 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../../Libft/include/libft.h"

int	ft_nb_len(unsigned int nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*nb;
	int		len;

	len = ft_nb_len(n);
	nb = (char *)malloc(sizeof(char) * (len + 1));
	if (!nb)
		return (0);
	nb[len] = 0;
	while (n != 0)
	{
		nb[len - 1] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (nb);
}

int	ft_print_unsigned_num(unsigned int n)
{
	int		print_len;
	char	*nb;

	print_len = 0;
	if (n == 0)
		print_len += write(1, "0", 1);
	else
	{
		nb = ft_uitoa(n);
		print_len += ft_print_string(nb);
		free(nb);
	}
	return (print_len);
}
