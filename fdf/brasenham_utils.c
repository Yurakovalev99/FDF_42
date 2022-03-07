/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brasenham_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysachiko <ysachiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 14:54:11 by ysachiko          #+#    #+#             */
/*   Updated: 2022/03/07 20:09:34 by ysachiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_shift(t_dots *start, t_dots *end, t_fdf *data)
{
	start->x += data->shift_x;
	start->y += data->shift_y;
	end->x += data->shift_x;
	end->y += data->shift_y;
}

void	get_zoom(t_dots *start, t_dots *end, t_fdf *data)
{
	start->x *= data->zoom;
	start->y *= data->zoom;
	start->z *= data->z_scale;
	end->x *= data->zoom;
	end->y *= data->zoom;
	end->z *= data->z_scale;
}

void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	get_color(t_dots *z_matrix, char *z)
{
	z_matrix->z = ft_atoi(z);
	if (z_matrix->z <= -7)
		z_matrix->color = 0x78ab78;
	if (z_matrix->z > -7)
		z_matrix->color = 0xCAFFCA;
	if (z_matrix->z > -5)
		z_matrix->color = 0xACFFAC;
	if (z_matrix->z > -3)
		z_matrix->color = 0x97FF97;
	if (z_matrix->z > -1)
		z_matrix->color = 0x5CFF5C;
	if (z_matrix->z == 0)
		z_matrix->color = 0x00CC00;
	if (z_matrix->z > 1)
		z_matrix->color = 0x00A300;
	if (z_matrix->z > 3)
		z_matrix->color = 0x008200;
	if (z_matrix->z > 5)
		z_matrix->color = 0x006800;
	if (z_matrix->z > 7)
		z_matrix->color = 0xA30000;
	if (z_matrix->z > 9)
		z_matrix->color = 0xCC2900;
}

void	free_string(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
