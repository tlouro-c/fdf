/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouro-c <tlouro-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 22:52:45 by tlouro-c          #+#    #+#             */
/*   Updated: 2023/12/10 15:52:37 by tlouro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "mlx.h"

void	get_matrix(char *filename, t_matrix *matrix, t_mlx *mlx, t_data *data)
{
	int				file;

	file = open(filename, O_RDONLY);
	if (file < 0)
	{
		perror(filename);
		error_quit(mlx, data);
	}
	matrix -> filename = filename;
	get_sizes_and_fill_matrix(file, matrix, data, mlx);
}

void	get_sizes_and_fill_matrix(int file, t_matrix *matrix,
		t_data *data, t_mlx *mlx)
{
	int	tile_size1;
	int	tile_size2;

	matrix -> columns = 0;
	matrix -> rows = 0;
	if (matrix -> zoom < 0.5)
		matrix -> zoom = 0.5;
	matrix -> width = SCREEN_WIDTH * matrix -> zoom;
	matrix -> z_max = INT_MIN;
	matrix -> z_min = INT_MAX;
	read_map(matrix, file, mlx, data);
	tile_size1 = matrix -> width * 0.5 / cos(ft_rad(30)) / matrix -> columns;
	tile_size2 = matrix -> width * 0.5 / cos(ft_rad(30)) / matrix -> rows;
	if (tile_size1 < tile_size2)
		matrix -> edge = tile_size1;
	else
		matrix -> edge = tile_size2;
	matrix -> tile_height = (int)roundf(
			(cos(matrix -> rotation_y) * matrix -> edge) * 2);
	matrix -> tile_width = (int)roundf(
			(sin(matrix -> rotation_x) * matrix -> edge) * 2);
}

void	read_map(t_matrix *matrix, int file, t_mlx *mlx, t_data *data)
{
	int			save_height;
	char		*line;

	save_height = 0;
	line = ft_get_next_line(file);
	if (matrix -> rows == 0 && (str_has_digit(line)))
		matrix -> columns = ft_count_words(line, ' ');
	if (line != NULL)
	{
		if (str_has_digit(line))
		{
			save_height = matrix -> rows;
			matrix -> rows += 1;
		}
		read_map(matrix, file, mlx, data);
	}
	else
	{
		alloc_matrix(matrix, mlx, data);
		close (file);
	}
	if (line != NULL)
		fill_map(line, matrix, save_height);
}

void	fill_map(char *line, t_matrix *matrix, int row)
{
	char	**split;
	int		i;
	int		c;

	split = ft_split(line, ' ');
	free(line);
	i = -1;
	while (split[++i] != NULL)
	{
		c = 0;
		matrix -> map[row][i].value = ft_atoi(&split[i][c]);
		if (matrix -> map[row][i].value < matrix -> z_min)
			matrix -> z_min = matrix -> map[row][i].value;
		if (matrix -> map[row][i].value > matrix -> z_max)
			matrix -> z_max = matrix -> map[row][i].value;
		while (split[i][c] != '\0' && ft_isdigit(split[i][c]))
			c++;
		if (split[i][c] == ',')
			matrix -> map[row][i].color = ft_atoi_base(&split[i][c + 1],
					"0123456789abcdef", 16);
		else
			matrix -> map[row][i].color = get_color(matrix -> map[row][i].value,
					0x87CDFF, matrix -> z_max - matrix -> z_min);
	}
	ft_free_str_arr(split, i);
}

void	alloc_matrix(t_matrix *matrix, t_mlx *mlx, t_data *data)
{
	int	i;

	matrix -> map = (t_vertex **)ft_calloc(matrix -> rows,
			sizeof(t_vertex *));
	if (matrix -> map == NULL)
		error_quit(mlx, data);
	i = 0;
	while (i < matrix -> rows)
	{
		matrix -> map[i] = (t_vertex *)ft_calloc(matrix -> columns,
				sizeof(t_vertex));
		if (matrix -> map[i] == NULL)
		{
			free_map_on_error(matrix, i);
			error_quit(mlx, data);
		}
		i++;
	}
}
