/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maker.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 15:35:15 by mosborne          #+#    #+#             */
/*   Updated: 2017/12/07 16:28:34 by mosborne         ###   ########.fr       */
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
	int x;

	x = -1;
	while (++x < (size * (size + 1)))
	{
		if (x % (size + 1) == size)
			array[x] = '\n';
		else
			array[x] = '.';
	}
	array[x] = '\0';
}

char	*ft_piecefinder(char *str)
{
	while (*str && (*str == '.' || *str == '\n'))
		str++;
	return (str);
}

char	ft_currentpiece(char *str)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '\n' && str[i] == '.')
			i++;
		return (str[i]);
	}
	return (0);
}


void	ft_gridmaker(char *array, char **new, int size, int piece)
{
	ft_builder(array, size);
	while (ft_solvetet(array, new, size, piece) != 1)
	{
		free(array);
		size++;
		array = ft_strnew(size * (size + 1));
		ft_builder(array, size);
	}
	ft_putstr(array);
	free(array);
}
