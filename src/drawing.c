/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouro-c <tlouro-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:04:49 by tlouro-c          #+#    #+#             */
/*   Updated: 2023/12/10 03:25:01 by tlouro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "mlx.h"

void	draw_vertex(t_data *data, t_matrix *matrix)
{
	int		row;
	int		column;
	float	x_inc;
	float	y_inc;

	x_inc = (float)matrix -> tile_width / 2;
	y_inc = (float)matrix -> tile_height / 2;
	row = 0;
	while (row < matrix -> rows)
	{
		column = 0;
		while (column < matrix -> columns)
		{
			matrix -> map[row][column].x = matrix -> o_x
				+ (column * x_inc) - (row * x_inc);
			matrix -> map[row][column].y = matrix -> o_y
				+ (column * y_inc) + (row * y_inc)
				- (matrix -> map[row][column].value
					* (matrix -> tile_height * matrix -> z_axis));
			if (is_inside_frame(matrix -> map[row][column]))
				my_mlx_pixel_put(data, matrix -> map[row][column]);
			column++;
		}
		row++;
	}
}

void	join_vertex(t_data *data, t_matrix *matrix)
{
	int	row;
	int	column;

	row = 0;
	while (row < matrix -> rows)
	{
		column = 0;
		while (column < matrix -> columns)
		{
			if (column + 1 < matrix -> columns)
				line_dda(data, matrix -> map[row][column],
					matrix -> map[row][column + 1]);
			if (row + 1 < matrix -> rows)
				line_dda(data, matrix -> map[row][column],
					matrix -> map[row + 1][column]);
			column++;
		}
		row++;
	}
}
