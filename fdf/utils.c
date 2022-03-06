/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysachiko <ysachiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 16:48:10 by ysachiko          #+#    #+#             */
/*   Updated: 2022/03/06 17:54:25 by ysachiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_atoi(const char *str)
{
	size_t		i;
	long long	j;
	short		sign;

	i = 0;
	j = 0;
	sign = 1;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		if (j * 10 + (sign * (str[i] - '0')) < j && sign > 0)
			return (-1);
		if (j * 10 + (sign * (str[i] - '0')) > j && sign < 0)
			return (0);
		j = j * 10 + (sign * (str[i] - '0'));
		i++;
	}
	return (j);
}

void	ft_free_data_struct(t_fdf *data)
{
	int	i;

	i = 0;
	while (i <= data->height)
	{
		free(data->z_matrix[i]);
		i++;
	}
	free(data->z_matrix);
	free(data);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	str = s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

float	ft_max(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
