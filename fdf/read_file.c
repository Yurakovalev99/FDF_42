/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysachiko <ysachiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:01:12 by ysachiko          #+#    #+#             */
/*   Updated: 2022/03/07 19:48:12 by ysachiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_matrix(t_dots *z_matrix, char *line, int y)
{
	char	**nums;
	char	**colors;
	int		i;

	nums = ft_split(line, ' ');
	i = 0;
	while (nums[i])
	{
		if (check_color(nums[i]))
			get_color(&z_matrix[i], nums[i]);
		else
		{
			colors = ft_split(nums[i], ',');
			z_matrix[i].z = ft_atoi(colors[0]);
			z_matrix[i].color = hex_to_dec(colors[1], 1);
			free_string(colors);
		}
		z_matrix[i].x = i;
		z_matrix[i].y = y;
		i++;
	}
	free_string(nums);
}

int	init_matrix(t_fdf *data)
{
	int		i;

	i = 0;
	data->z_matrix = malloc(sizeof(t_dots *) * (data->height + 1));
	if (!data->z_matrix)
		return (1);
	while (i <= data->height)
	{
		data->z_matrix[i] = malloc(sizeof(t_dots) * (data->width + 1));
		if (!data->z_matrix[i])
		{
			free_matrix(data->z_matrix, i);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_read_file(char *file, t_fdf *data)
{
	int		i;
	int		fd;
	int		y;
	char	*line;

	data->height = ft_get_height(file);
	data->width = ft_get_width(file);
	if (init_matrix(data))
		return (1);
	fd = open(file, O_RDONLY);
	i = 0;
	y = 0;
	while (i < data->height)
	{
		line = get_next_line(fd);
		fill_matrix(data->z_matrix[i++], line, y++);
		free(line);
	}
	close(fd);
	return (0);
}

int	ft_get_height(char *file)
{
	char	*line;
	int		fd;
	int		height;

	fd = open(file, O_RDONLY, 0);
	if (fd < 0)
		return (-1);
	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		height++;
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	return (height);
}

int	ft_get_width(char *file)
{
	int		fd;
	char	*line;
	char	**arr;
	int		width;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	width = 0;
	line = get_next_line(fd);
	arr = ft_split(line, ' ');
	free(line);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	while (arr[width])
		width++;
	free_string(arr);
	close(fd);
	return (width);
}
