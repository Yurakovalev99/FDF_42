/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysachiko <ysachiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:07:57 by ysachiko          #+#    #+#             */
/*   Updated: 2022/03/07 18:47:04 by ysachiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_color(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
			return (0);
		i++;
	}
	return (1);
}

int	hex_to_dec(char *hex, int base)
{
	int	decimal;
	int	length;

	decimal = 0;
	length = ft_strlen(hex);
	while (length-- >= 0)
	{
		if (hex[length] >= '0' && hex[length] <= '9')
		{
			decimal += (hex[length] - 48) * base;
			base *= 16;
		}
		else if (hex[length] >= 'A' && hex[length] <= 'F')
		{
			decimal += (hex[length] - 55) * base;
			base *= 16;
		}
		else if (hex[length] >= 'a' && hex[length] <= 'f')
		{
			decimal += (hex[length] - 87) * base;
			base *= 16;
		}
	}
	return (decimal);
}
