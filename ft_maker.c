/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maker.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 01:12:08 by mosborne          #+#    #+#             */
/*   Updated: 2017/11/14 01:42:46 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_mapsize(int *piece)
{
	int i;
	static int x = 0;
	int mapsize;
	char *array;

	i = 1;
	while (i * i < piece * 4)
		i++;
	mapsize = i;
	array = ft_strnew(mapsize * (mapsize + 1))
	while (x < (mapsize * (mapsize + 1)))
	{
		if (x % (mapsize + 1) == mapsize)
			array[x] = '\n';
		else
			array[x] = '.';
		x++;
	}
	array[x] = '\0';
}

char	*ft_piecefinder(char *str)
{
	while (*str && (*str == '.' || *str == '\n'))
		str++;
	return (str);
}