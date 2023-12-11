/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouro-c <tlouro-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:39:59 by tlouro-c          #+#    #+#             */
/*   Updated: 2023/11/26 15:43:03 by tlouro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	j;
	int	i;

	j = -1;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			j = i;
		i++;
	}
	if (s[i] == (unsigned char)c)
		j = i;
	if (j != -1)
		return ((char *)&s[j]);
	return (NULL);
}
