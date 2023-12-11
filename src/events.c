/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouro-c <tlouro-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:54:04 by tlouro-c          #+#    #+#             */
/*   Updated: 2023/12/10 03:29:58 by tlouro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "mlx.h"

int	manage_keyboard_input(int key, t_all *all)
{
	if (key == XK_Escape)
		close_window(all);
	else if (key == XK_Up || key == XK_Down || key == XK_Right || key == XK_Left
		|| key == XK_i || key == XK_o || key == XK_a || key == XK_s
		|| key == XK_z || key == XK_x || key == XK_q || key == XK_w)
		refresh(all -> matrix, all -> data, all -> mlx, key);
	return (0);
}

int	close_window(t_all *all)
{
	mlx_destroy_image(all -> mlx -> mlx, all -> data ->img);
	mlx_destroy_window(all -> mlx -> mlx, all -> mlx -> win);
	mlx_destroy_display(all -> mlx -> mlx);
	free(all -> mlx -> mlx);
	exit (0);
}

int	refresh(t_matrix *matrix, t_data *data, t_mlx *mlx, int key)
{
	chose_event(matrix, key);
	mlx_destroy_image(mlx->mlx, data->img);
	data->img = mlx_new_image(mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	get_matrix(matrix -> filename, matrix, mlx, data);
	draw_vertex(data, matrix);
	join_vertex(data, matrix);
	free_map(matrix);
	mlx_put_image_to_window(mlx->mlx, mlx->win, data->img, 0, 0);
	return (0);
}

void	chose_event(t_matrix *matrix, int key)
{
	if (key == XK_Up)
		matrix -> o_y += 0.03 * SCREEN_HEIGHT;
	else if (key == XK_Down)
		matrix -> o_y -= 0.03 * SCREEN_HEIGHT;
	else if (key == XK_Left)
		matrix -> o_x += 0.03 * SCREEN_HEIGHT;
	else if (key == XK_Right)
		matrix -> o_x -= 0.03 * SCREEN_HEIGHT;
	else if (key == XK_i)
		matrix -> zoom += 0.1;
	else if (key == XK_o)
		matrix -> zoom -= 0.1;
	else if (key == XK_a)
		matrix -> rotation_y += ft_rad(5);
	else if (key == XK_s)
		matrix -> rotation_y -= ft_rad(5);
	else if (key == XK_z)
		matrix -> rotation_x += ft_rad(5);
	else if (key == XK_x)
		matrix -> rotation_x -= ft_rad(5);
	else if (key == XK_q)
		matrix -> z_axis -= 0.01;
	else if (key == XK_w)
		matrix -> z_axis += 0.01;
}
