/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouro-c <tlouro-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:12:15 by tlouro-c          #+#    #+#             */
/*   Updated: 2023/12/04 19:16:41 by tlouro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*mod_strdup(char const *s, char c)
{
	char	*s2;
	int		i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	s2 = ft_calloc((i + 1), sizeof(char));
	if (!s2)
		return (s2);
	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		s2[i] = s[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	**ft_split(char const *s, int sep)
{
	char	**sarray;
	int		j;
	int		i;

	sarray = ft_calloc((ft_count_words(s, sep) + 1), sizeof(char *));
	if (!sarray)
		return (NULL);
	j = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if ((i == 0 && s[0] != sep && s[0] != '\0')
			|| (i > 0 && s[i] != sep && s[i - 1] == sep))
		{
			sarray[j] = mod_strdup(&s[i], sep);
			if (!sarray[j])
				return (ft_free_str_arr(sarray, j));
			j++;
		}
		i++;
	}
	sarray[j] = NULL;
	return (sarray);
}
