/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysachiko <ysachiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:52:23 by mnathali          #+#    #+#             */
/*   Updated: 2022/03/06 13:11:57 by ysachiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "fdf.h"

static char	**ft_errfree(char **arr, size_t i)
{
	free(arr[i]);
	while (i != 0)
	{
		i--;
		free(arr[i]);
	}
	free(arr);
	return (0);
}

static size_t	ft_lenstr(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s != '\0' && *s != c)
	{
		i++;
		s++;
	}
	return (i);
}

static size_t	ft_row(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		s++;
		if (*s == c || *s == '\0')
			i++;
		while (*s == c)
			s++;
	}
	return (i);
}

static char	*ft_adrofstr(char const *s, char c)
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc(sizeof(char) * (ft_lenstr(s, c) + 1));
	if (!str)
		return (0);
	while (s[i] != c && s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**arr;

	if (!s)
		return (0);
	i = 0;
	arr = malloc(sizeof(arr) * (ft_row(s, c) + 1));
	if (!arr)
		return (0);
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			break ;
		arr[i] = ft_adrofstr(s, c);
		if (arr[i] == 0)
			return (ft_errfree(arr, i));
		while (*s != '\0' && *s != c)
			s++;
		i++;
	}
	arr[i] = 0;
	return (arr);
}
