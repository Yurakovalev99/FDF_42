/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brasenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysachiko <ysachiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 14:04:09 by ysachiko          #+#    #+#             */
/*   Updated: 2022/03/07 19:56:32 by ysachiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_isometric(float *x, float *y, int z, t_fdf *data)
{
	*x = (*x - *y) * cos(data->angle_cos);
	*y = (*x + *y) * sin(data->angle_sin) - z;
}

void	make_step(float *x_step, float *y_step, int *max)
{
	*max = ft_max(fabs(*x_step), fabs(*y_step));
	*x_step /= *max;
	*y_step /= *max;
}

void	bresenham(t_dots start, t_dots end, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;

	get_zoom(&start, &end, data);
	if (data->flag)
	{
		ft_isometric(&start.x, &start.y, start.z, data);
		ft_isometric(&end.x, &end.y, end.z, data);
	}
	get_shift(&start, &end, data);
	x_step = end.x - start.x;
	y_step = end.y - start.y;
	make_step(&x_step, &y_step, &max);
	if (start.z < end.z)
		start.color = end.color;
	while ((int)(start.x - end.x) || (int)(start.y - end.y))
	{
		if ((int)start.x < data->scr_x && (int)start.y < data->scr_y
			&& (int)start.y >= 0 && (int)start.x >= 0)
			my_mlx_pixel_put(data, start.x, start.y, start.color);
		start.x += x_step;
		start.y += y_step;
	}
}

void	print_to_img(t_fdf *data, t_dots **z_matrix)
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
				bresenham(z_matrix[y][x], z_matrix[y][x + 1], data);
			if (y < data->height - 1)
				bresenham(z_matrix[y][x], z_matrix[y + 1][x], data);
		}
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	print_menu(data);
}

void	draw(t_fdf *data, t_dots **z_matrix)
{
	ft_bzero(data->addr, data->scr_x * data->scr_y
		* (data->bits_per_pixel / 8));
	print_to_img(data, z_matrix);
}
