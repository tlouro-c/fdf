/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouro-c <tlouro-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:12:20 by tlouro-c          #+#    #+#             */
/*   Updated: 2023/11/25 02:16:30 by tlouro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*edge_cases(char *buffer, int base)
{
	if (base < 0 || base > 36)
		return (buffer);
	else
	{
		buffer[0] = '0';
		buffer[1] = '\0';
		return (buffer);
	}
}

static char	*final(char *buffer, int negative, int i)
{
	if (negative)
		buffer[i++] = '-';
	buffer[i] = '\0';
	return (ft_strrev(buffer));
}

char	*ft_itoa(int value, char *buffer, int base)
{
	int	print;
	int	negative;
	int	i;

	i = 0;
	if (base < 0 || base > 36 || value == 0)
		return (edge_cases(buffer, base));
	else if (value == INT_MIN)
	{
		buffer[i++] = '8';
		value++;
	}
	negative = (value < 0) && (base == 10);
	value = ft_abs(value);
	while (value > 0)
	{
		print = (value % base);
		if (print < 10)
			buffer[i++] = print + '0';
		else
			buffer[i++] = print - 10 + 'a';
		value = value / base;
	}
	return (final(buffer, negative, i));
}
