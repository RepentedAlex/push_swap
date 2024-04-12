/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:08:52 by apetitco          #+#    #+#             */
/*   Updated: 2024/04/12 18:00:27 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../../Libft/include/libft.h"
#include <stdio.h>

int	ft_print_char(int c)
{
	return (write(1, &c, 1));
}

int	ft_eval_format(va_list args, const char format)
{
	int	print_len;

	print_len = 0;
	if (format == 'c')
		print_len += ft_print_char(va_arg(args, int));
	if (format == 's')
		print_len += ft_print_string(va_arg(args, char *));
	if (format == 'p')
		print_len += ft_print_pointer(va_arg(args, unsigned long long));
	if (format == 'd' || format == 'i')
		print_len += ft_print_num(va_arg(args, int));
	if (format == 'u')
		print_len += ft_print_unsigned_num(va_arg(args, unsigned int));
	if (format == 'x' || format == 'X')
		print_len += ft_print_hex(va_arg(args, unsigned int), format);
	if (format == '%')
		print_len += write(1, "%", 1);
	return (print_len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		ret;
	va_list	args;

	if (format == NULL)
		return (-1);
	i = 0;
	ret = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			ret += ft_eval_format(args, format[i + 1]);
			i++;
		}
		else
			ret += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (ret);
}

/*
int	main(void)
{
	int c = -1;
	ft_printf("", c);
	printf("", c);
}
*/
