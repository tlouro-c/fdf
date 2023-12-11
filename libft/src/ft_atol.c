/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouro-c <tlouro-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:49:00 by tlouro-c          #+#    #+#             */
/*   Updated: 2023/11/23 14:55:44 by tlouro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *s)
{
	long	n;
	int		i;
	int		negative;

	n = 0;
	i = 0;
	while (ft_isspace(s[i]))
		i++;
	negative = s[i] == '-';
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] != '\0' && ft_isdigit(s[i]))
		n = n * 10 + (s[i++] - '0');
	if (negative)
		return (n * -1);
	return (n);
}
