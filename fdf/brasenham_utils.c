/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brasenham_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysachiko <ysachiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 14:54:11 by ysachiko          #+#    #+#             */
/*   Updated: 2022/03/06 17:47:30 by ysachiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_dots_x(int x, int y, t_dots *dots)
{
	dots->x = x;
	dots->x1 = x + 1;
	dots->y = y;
	dots->y1 = y;
}

void	get_dots_y(int x, int y, t_dots *dots)
{
	dots->x = x;
	dots->x1 = x;
	dots->y = y;
	dots->y1 = y + 1;
}

void	get_shift(t_dots *dots, t_fdf *data)
{
	dots->x += data->shift_x;
	dots->y += data->shift_y;
	dots->x1 += data->shift_x;
	dots->y1 += data->shift_y;
}

void	get_zoom(t_dots *dots, t_fdf *data)
{
	dots->z = data->z_matrix[(int)dots->y][(int)dots->x];
	dots->z1 = data->z_matrix[(int)dots->y1][(int)dots->x1];
	get_color(dots->z, dots->z1, data);
	dots->x *= data->zoom;
	dots->y *= data->zoom;
	dots->z *= data->z_scale;
	dots->x1 *= data->zoom;
	dots->y1 *= data->zoom;
	dots->z1 *= data->z_scale;
}

void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
