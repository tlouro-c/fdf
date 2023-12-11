/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouro-c <tlouro-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:55:43 by tlouro-c          #+#    #+#             */
/*   Updated: 2023/12/10 15:49:33 by tlouro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

int	fdf_file_format(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
		i++;
	i -= 4;
	return (ft_strcmp(&(arg[i]), ".fdf"));
}

void	free_map(t_matrix *matrix)
{
	int	row;

	row = 0;
	while (row < matrix -> rows)
	{
		free(matrix -> map[row]);
		matrix -> map[row] = NULL;
		row++;
	}
	free(matrix -> map);
	matrix -> map = NULL;
}

void	free_map_on_error(t_matrix *matrix, int rows)
{
	int	row;

	row = 0;
	while (row < rows)
	{
		free(matrix -> map[row]);
		matrix -> map[row] = NULL;
		row++;
	}
	free(matrix -> map);
	matrix -> map = NULL;
}
