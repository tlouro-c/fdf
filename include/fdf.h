/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouro-c <tlouro-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 21:51:59 by tlouro-c          #+#    #+#             */
/*   Updated: 2023/12/02 21:51:59 by tlouro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <fcntl.h>
# include <X11/keysym.h>

# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080

typedef struct s_rgb
{
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;
}	t_rgb;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vertex
{
	int				value;
	unsigned int	color;
	t_rgb			rgb;
	float			x;
	float			y;
}	t_vertex;

typedef struct s_matrix
{
	t_vertex	**map;
	int			columns;
	int			rows;
	int			width;
	int			edge;
	int			tile_height;
	int			tile_width;
	int			z_min;
	int			z_max;
	int			o_x;
	int			o_y;
	float		zoom;
	float		rotation_y;
	float		rotation_x;
	float		z_axis;
	char		*filename;
}	t_matrix;

typedef struct s_all
{
	t_matrix	*matrix;
	t_data		*data;
	t_mlx		*mlx;
}	t_all;

/* -------------------------------------------------------------------------- */
/*                                   ERRORS                                   */
/* -------------------------------------------------------------------------- */

void			input_checker(int argc, char *argv[]);
void			check_connection(void *connection);
void			check_window(t_mlx *mlx);
void			check_image(t_mlx *mlx, void *image);
void			error_quit(t_mlx *mlx, t_data *data);

/* -------------------------------------------------------------------------- */
/*                                ERRORS UTILS                                */
/* -------------------------------------------------------------------------- */
int				fdf_file_format(char *arg);
void			free_map(t_matrix *matrix);
void			free_map_on_error(t_matrix *matrix, int rows);

/* -------------------------------------------------------------------------- */
/*                                 MATRIX INFO                                */
/* -------------------------------------------------------------------------- */

void			get_matrix(char *filename, t_matrix *matrix, t_mlx *mlx,
					t_data *data);
void			read_map(t_matrix *matrix, int file, t_mlx *mlx, t_data *data);
void			get_sizes_and_fill_matrix(int file, t_matrix *matrix,
					t_data *data, t_mlx *mlx);
void			fill_map(char *line, t_matrix *matrix, int row);
void			alloc_matrix(t_matrix *matrix, t_mlx *mlx, t_data *data);

/* -------------------------------------------------------------------------- */
/*                                    UTILS                                   */
/* -------------------------------------------------------------------------- */

unsigned int	ft_atoi_base(char *s, char *base, unsigned int base_size);
int				str_has_digit(char *s);
unsigned int	get_color(int value, int base_color, int z_ratio);
void			set_variables(t_all *all, t_matrix *matrix, t_data *data,
					t_mlx *mlx);

/* -------------------------------------------------------------------------- */
/*                                DRAWING UTILS                               */
/* -------------------------------------------------------------------------- */

void			my_mlx_pixel_put(t_data *data, t_vertex vertex);
void			line_dda(t_data *data, t_vertex v1, t_vertex v2);
int				is_inside_frame(t_vertex vertex);

/* -------------------------------------------------------------------------- */
/*                                   EVENTS                                   */
/* -------------------------------------------------------------------------- */

int				close_window(t_all *all);
int				refresh(t_matrix *matrix, t_data *data, t_mlx *mlx, int key);
void			chose_event(t_matrix *matrix, int key);
int				manage_keyboard_input(int key, t_all *all);

/* -------------------------------------------------------------------------- */
/*                                   DRAWING                                  */
/* -------------------------------------------------------------------------- */

void			draw_vertex(t_data *data, t_matrix *matrix);
void			join_vertex(t_data *data, t_matrix *matrix);

#endif /* FDF_H */
