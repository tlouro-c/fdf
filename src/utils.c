/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouro-c <tlouro-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:49:02 by tlouro-c          #+#    #+#             */
/*   Updated: 2023/12/10 03:24:41 by tlouro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

int	str_has_digit(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (ft_isdigit(s[i]))
			return (1);
		i++;
	}
	return (0);
}

static unsigned int	get_number_index(char c, char *base)
{
	unsigned int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (INT_MAX);
}

unsigned int	ft_atoi_base(char *s, char *base, unsigned int base_size)
{
	unsigned int	final;
	int				i;

	final = 0;
	i = 0;
	if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
		i += 2;
	while (s[i] != '\0' && !ft_isspace(s[i]))
	{
		final = (final * base_size) + get_number_index(s[i], base);
		i++;
	}
	return (final);
}

unsigned int	get_color(int value, int base_color, int z_ratio)
{
	float	incrementor[3];
	int		hex_color_top;
	int		new_red;
	int		new_green;
	int		new_blue;

	if (value < 0)
		hex_color_top = 0x0000FF;
	else
		hex_color_top = 0xE11584;
	incrementor[0] = (float)((hex_color_top >> 16) - (base_color >> 16))
		/ (float)z_ratio;
	incrementor[1] = (float)((hex_color_top >> 8 & 0xFF)
			- (base_color >> 8 & 0xFF)) / (float)z_ratio;
	incrementor[2] = (float)((hex_color_top & 0xFF) - (base_color & 0xFF))
		/ (float)z_ratio;
	new_red = (base_color >> 16) + ((int)roundf(incrementor[0] * value));
	new_green = (base_color >> 8 & 0xFF)
		+ ((int)roundf(incrementor[1] * value));
	new_blue = (base_color & 0xFF) + ((int)roundf(incrementor[2] * value));
	return (new_red << 16 | new_green << 8 | new_blue);
}

void	set_variables(t_all *all, t_matrix *matrix, t_data *data, t_mlx *mlx)
{
	matrix -> z_max = INT_MIN;
	matrix -> z_min = INT_MAX;
	matrix -> o_x = SCREEN_WIDTH * 0.5;
	matrix -> o_y = SCREEN_HEIGHT * 0.1;
	matrix -> zoom = 1.0;
	matrix -> rotation_x = ft_rad(60);
	matrix -> rotation_y = ft_rad(60);
	matrix -> z_axis = 0.085;
	all -> matrix = matrix;
	all -> data = data;
	all -> mlx = mlx;
}
