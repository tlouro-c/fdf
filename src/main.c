/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouro-c <tlouro-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 21:51:59 by tlouro-c          #+#    #+#             */
/*   Updated: 2023/12/10 15:38:34 by tlouro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "mlx.h"

int	main(int argc, char *argv[])
{
	t_all		all;
	t_matrix	matrix;
	t_mlx		mlx;	
	t_data		data;

	input_checker(argc, argv);
	mlx.mlx = mlx_init();
	check_connection(mlx.mlx);
	mlx.win = mlx_new_window(mlx.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, argv[1]);
	check_window(&mlx);
	data.img = mlx_new_image(mlx.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	check_image(&mlx, data.img);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
			&data.line_length, &data.endian);
	set_variables(&all, &matrix, &data, &mlx);
	get_matrix(argv[1], &matrix, &mlx, &data);
	draw_vertex(&data, &matrix);
	join_vertex(&data, &matrix);
	free_map(&matrix);
	mlx_hook(mlx.win, 2, 1L << 0, manage_keyboard_input, &all);
	mlx_hook(mlx.win, 17, 0L, close_window, &all);
	mlx_put_image_to_window(mlx.mlx, mlx.win, data.img, 0, 0);
	mlx_loop(mlx.mlx);
}
