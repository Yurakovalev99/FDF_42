/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysachiko <ysachiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:01:19 by ysachiko          #+#    #+#             */
/*   Updated: 2022/03/06 18:17:39 by ysachiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_menu(t_fdf *data)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = data->mlx_ptr;
	win = data->win_ptr;
	mlx_string_put(mlx, win, 15, y += 30, 0xC2B280, "Move: <- | ->");
	mlx_string_put(mlx, win, 15, y += 30, 0xC2B280, "Zoom: + | -");
	mlx_string_put(mlx, win, 15, y += 30, 0xC2B280, "Scale: Q | W");
	mlx_string_put(mlx, win, 15, y += 30, 0xC2B280, "Rotate: A | S | D | F");
	mlx_string_put(mlx, win, 15, y += 30, 0xC2B280, "Exit: ESC");
	mlx_string_put(mlx, win, 15, y += 30, 0xC2B280, "Reset: TAB");
	mlx_string_put(mlx, win, 15, y += 30, 0xC2B280, "ISO ON/OFF: 1 | 2");
}

void	first_init(t_fdf *data)
{
	data->zoom = 30;
	data->z_scale = 2;
	data->shift_y = 250;
	data->shift_x = 900;
	data->scr_x = WIDTH;
	data->scr_y = HEIGHT;
	data->angle_cos = 0.8;
	data->angle_sin = 0.8;
	data->flag = 1;
}
