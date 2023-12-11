/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouro-c <tlouro-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:23:58 by tlouro-c          #+#    #+#             */
/*   Updated: 2023/11/23 14:55:48 by tlouro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	int	n;
	int	i;
	int	negative;

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
