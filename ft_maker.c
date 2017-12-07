/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maker.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 01:12:08 by mosborne          #+#    #+#             */
/*   Updated: 2017/12/06 16:03:58 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


int		ft_mapsize(int piece)
{
	int i;

	i = 1;
	while (i * i < piece * 4) // check to make sure their is atleast one piece
		i++;
	return (i);
}

void	ft_builder(char *array, int size)
{
	static int x = 0;

	while (x < (size * (size + 1)))
	{
		if (x % (size + 1) == size)
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

void	ft_gridmaker(char *array, char **new, int size, int piece)
{
	ft_builder(array, size);
	while (ft_solvetet(array, new, size, piece))
	{
		
	}
}