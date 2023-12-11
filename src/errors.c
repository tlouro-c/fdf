/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouro-c <tlouro-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:35:21 by tlouro-c          #+#    #+#             */
/*   Updated: 2023/12/10 15:54:44 by tlouro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "mlx.h"

void	input_checker(int argc, char *argv[])
{
	char	*error_msg;

	error_msg = "Please provide a file in format *.fdf as the only argument\n";
	if (argc != 2 || fdf_file_format(argv[1]) != 0)
	{
		ft_putstr_fd(error_msg, STDERR_FILENO);
		exit(1);
	}
}

void	check_connection(void *connection)
{
	if (connection == NULL)
		exit (1);
}

void	check_window(t_mlx *mlx)
{
	if (mlx -> win == NULL)
	{
		mlx_destroy_display(mlx -> mlx);
		free(mlx -> mlx);
		exit (1);
	}
}

void	check_image(t_mlx *mlx, void *image)
{
	if (image == NULL)
	{
		mlx_destroy_window(mlx -> mlx, mlx -> win);
		mlx_destroy_display(mlx -> mlx);
		free(mlx -> mlx);
		exit (1);
	}
}

void	error_quit(t_mlx *mlx, t_data *data)
{
	mlx_destroy_image(mlx -> mlx, data -> img);
	mlx_destroy_window(mlx -> mlx, mlx -> win);
	mlx_destroy_display(mlx -> mlx);
	free(mlx -> mlx);
	exit (1);
}
