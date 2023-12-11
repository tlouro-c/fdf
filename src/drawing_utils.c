/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouro-c <tlouro-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 00:01:08 by tlouro-c          #+#    #+#             */
/*   Updated: 2023/12/10 03:02:22 by tlouro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "mlx.h"

void	my_mlx_pixel_put(t_data *data, t_vertex vertex)
{
	char	*dest;

	dest = data -> addr + ((int)round(vertex.y) * data -> line_length
			+ (int)round(vertex.x) * (data -> bits_per_pixel / 8));
	*(unsigned int *)dest = vertex.color;
}

static unsigned int	new_color(int base_color, int end_color, int pos, int steps)
{
	float	incrementor[3];
	int		new_red;
	int		new_green;
	int		new_blue;

	incrementor[0] = ((end_color >> 16) - (base_color >> 16)) / (float)steps;
	incrementor[1] = ((end_color >> 8 & 0xFF) - (base_color >> 8 & 0xFF))
		/ (float)steps;
	incrementor[2] = ((end_color & 0xFF) - (base_color & 0xFF)) / (float)steps;
	new_red = (base_color >> 16) + ((int)roundf(incrementor[0] * pos));
	new_green = (base_color >> 8 & 0xFF) + ((int)roundf(incrementor[1] * pos));
	new_blue = (base_color & 0xFF) + ((int)roundf(incrementor[2] * pos));
	return (new_red << 16 | new_green << 8 | new_blue);
}

void	line_dda(t_data *data, t_vertex v1, t_vertex v2)
{
	float	inc_x;
	float	inc_y;
	int		base_color;
	int		steps;
	int		i;

	if (ft_abs(v2.x - v1.x) > ft_abs(v2.y - v1.y))
		steps = ft_abs(v2.x - v1.x);
	else
		steps = ft_abs(v2.y - v1.y);
	if (steps <= 0)
		return ;
	inc_x = ((float)v2.x - v1.x) / (float)steps;
	inc_y = ((float)v2.y - v1.y) / (float)steps;
	base_color = v1.color;
	i = -1;
	while (++i < steps)
	{
		if (v1.x <= SCREEN_WIDTH && v1.x >= 0
			&& v1.y <= SCREEN_HEIGHT && v1.y >= 0)
			my_mlx_pixel_put(data, v1);
		v1.color = new_color(base_color, v2.color, i, steps);
		v1.x += inc_x;
		v1.y += inc_y;
	}
}

int	is_inside_frame(t_vertex vertex)
{
	return (vertex.x >= 0 && vertex.x <= SCREEN_WIDTH
		&& vertex.y >= 0 && vertex.y <= SCREEN_HEIGHT);
}
