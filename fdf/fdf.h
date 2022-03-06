/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysachiko <ysachiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:03:55 by ysachiko          #+#    #+#             */
/*   Updated: 2022/03/06 18:40:56 by ysachiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "get_next_line.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>

# define WIDTH			1800
# define HEIGHT			1000

# define UP				126
# define DOWN			125
# define LEFT			123
# define RIGHT			124
# define ESC			53
# define ZOOM_UP		24
# define ZOOM_DOWN		27
# define ANGLE_COS_DOWN	1
# define ANGLE_COS_UP	0
# define ANGLE_SIN_DOWN	2
# define ANGLE_SIN_UP	3
# define Z_UP			13
# define Z_DOWN			12
# define ISO_ON			18
# define ISO_OFF		19
# define RESET			48

typedef struct s_dots
{
	float	x;
	float	y;
	float	x1;
	float	y1;
	int		z;
	int		z1;

}	t_dots;

typedef struct s_fdf
{
	int		width;
	int		height;
	int		**z_matrix;
	int		zoom;
	int		color;
	double	angle_cos;
	double	angle_sin;
	double	z_scale;
	int		flag;
	int		shift_x;
	int		shift_y;
	int		scr_x;
	int		scr_y;

	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*addr;
}	t_fdf;

int		ft_get_height(char *file);
int		ft_get_width(char *file);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char	*str);
int		ft_read_file(char *file_name, t_fdf *data);
void	bresenham(t_dots *dots, t_fdf *data);
float	ft_max(float a, float b);
void	first_init(t_fdf *data);
void	draw(t_fdf *data);
void	ft_isometric(float *x, float *y, int z, t_fdf *data);
void	print_menu(t_fdf *data);
int		deal_key(int key, t_fdf *data);
int		move(int key, t_fdf *data);
int		zoom(int key, t_fdf *data);
int		angle(int key, t_fdf *data);
int		z_scale(int key, t_fdf *data);
void	first_init(t_fdf *data);
void	ft_free_data_struct(t_fdf *data);
size_t	ft_strlen(char *str);
void	get_dots_y(int x, int y, t_dots *dots);
void	get_dots_x(int x, int y, t_dots *dots);
void	get_shift(t_dots *dots, t_fdf *data);
void	get_zoom(t_dots *dots, t_fdf *data);
void	get_color(int z, int z1, t_fdf *data);
void	ft_free_data_struct(t_fdf *data);
void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color);
void	ft_bzero(void *s, size_t n);
float	ft_max(float a, float b);

#endif
