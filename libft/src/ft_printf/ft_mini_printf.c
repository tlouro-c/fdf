/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouro-c <tlouro-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:25:46 by tlouro-c          #+#    #+#             */
/*   Updated: 2023/11/27 12:23:17 by tlouro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_printf_specifiers(va_list *argscpy, const char *address)
{
	char			specifier;
	int				printed;
	char			buffer[12];
	int				c;

	printed = 0;
	specifier = *address;
	if (specifier == 'i' || specifier == 'd')
		printed += ft_putstr_fd(ft_itoa(va_arg(*argscpy, int), buffer, 10), 1);
	else if (specifier == 'u')
		printed += ft_putstr_fd(ft_itoa(va_arg(*argscpy, int), buffer, 10), 1);
	else if (specifier == 'c')
	{
		c = va_arg(*argscpy, int);
		printed += write(1, &c, 1);
	}
	else if (specifier == 's')
		printed += ft_putstr_fd(va_arg(*argscpy, char *), 1);
	else
	{
		write(1, &specifier, 1);
		printed++;
	}
	return (printed);
}

int	ft_mini_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		sum;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	sum = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			sum += ft_printf_specifiers(&args, &format[i + 1]);
			i++;
		}
		else
		{
			write (1, &format[i], 1);
			sum++;
		}
		i++;
	}
	va_end(args);
	return (sum);
}
