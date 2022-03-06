/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brasenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysachiko <ysachiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 14:04:09 by ysachiko          #+#    #+#             */
/*   Updated: 2022/03/06 18:30:43 by ysachiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_isometric(float *x, float *y, int z, t_fdf *data)
{
	*x = (*x - *y) * cos(data->angle_cos);
	*y = (*x + *y) * sin(data->angle_sin) - z;
}

void	get_color(int z, int z1, t_fdf *data)
{
	if (z > -9 || z1 > -9)
		data->color = 0x00FF00;
	if (z > -7 || z1 > -7)
		data->color = 0xCAFFCA;
	if (z > -5 || z1 > -5)
		data->color = 0xACFFAC;
	if (z > -3 || z1 > -3)
		data->color = 0x97FF97;
	if (z > -1 || z1 > -1)
		data->color = 0x5CFF5C;
	if (z == 0 || z1 == 0)
		data->color = 0x00CC00;
	if (z > 1 || z1 > 1)
		data->color = 0x00A300;
	if (z > 3 || z1 > 3)
		data->color = 0x008200;
	if (z > 5 || z1 > 5)
		data->color = 0x006800;
	if (z > 7 || z1 > 7)
		data->color = 0xA30000;
	if (z > 9 || z1 > 9)
		data->color = 0xCC2900;
}

void	bresenham(t_dots *dots, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;

	get_zoom(dots, data);
	if (data->flag)
	{
		ft_isometric(&dots->x, &dots->y, dots->z, data);
		ft_isometric(&dots->x1, &dots->y1, dots->z1, data);
	}
	get_shift(dots, data);
	x_step = dots->x1 - dots->x;
	y_step = dots->y1 - dots->y;
	max = ft_max(fabs(x_step), fabs(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(dots->x - dots->x1) || (int)(dots->y - dots->y1))
	{
		if ((int)dots->x < data->scr_x && (int)dots->y < data->scr_y
			&& (int)dots->y >= 0 && (int)dots->x >= 0)
			my_mlx_pixel_put(data, (int)dots->x, (int)dots->y, data->color);
		dots->x += x_step;
		dots->y += y_step;
	}
}

void	print_to_img(t_dots *dots, t_fdf *data)
{
	int		x;
	int		y;

	y = -1;
	while (++y < data->height)
	{
		x = -1;
		while (++x < data->width)
		{
			if (x < data->width - 1)
			{
				get_dots_x(x, y, dots);
				bresenham(dots, data);
			}
			if (y < data->height - 1)
			{
				get_dots_y(x, y, dots);
				bresenham(dots, data);
			}
		}
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	print_menu(data);
	free(dots);
}

void	draw(t_fdf *data)
{
	t_dots	*dots;

	ft_bzero(data->addr, data->scr_x * data->scr_y
		* (data->bits_per_pixel / 8));
	dots = malloc(sizeof(t_dots));
	print_to_img(dots, data);
}
