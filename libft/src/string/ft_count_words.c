/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouro-c <tlouro-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:07:42 by tlouro-c          #+#    #+#             */
/*   Updated: 2023/11/26 16:09:42 by tlouro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_words(char const *s, int sep)
{
	int	counter;
	int	i;

	counter = 0;
	i = 0;
	if (s[i] == '\0')
		return (counter);
	if (s[i] != sep)
		counter++;
	i++;
	while (s[i] != '\0')
	{
		if (s[i] != sep && s[i - 1] == sep)
			counter++;
		i++;
	}
	return (counter);
}
