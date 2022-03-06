/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysachiko <ysachiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:01:25 by ysachiko          #+#    #+#             */
/*   Updated: 2022/03/06 18:43:46 by ysachiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	file_check(char *file_name)
{
	int	i;
	int	size;

	size = ft_strlen(file_name);
	i = size - 4;
	if (file_name[i++] != '.')
		return (1);
	if (file_name[i++] != 'f')
		return (1);
	if (file_name[i++] != 'd')
		return (1);
	if (file_name[i++] != 'f')
		return (1);
	return (0);
}

static int	check_read(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		return (1);
	return (0);
}

static void	init_img(t_fdf *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1800, 1000, "FDF");
	data->img = mlx_new_image(data->mlx_ptr, 1800, 1000);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	if (argc != 2 || file_check(argv[1]) || check_read(argv[1]))
		return (0);
	data = malloc(sizeof(t_fdf));
	if (!data)
		return (0);
	if (ft_read_file(argv[1], data))
	{
		free(data);
		return (0);
	}
	first_init(data);
	init_img(data);
	draw(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
