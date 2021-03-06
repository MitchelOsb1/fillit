/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 11:09:38 by mosborne          #+#    #+#             */
/*   Updated: 2017/12/07 16:56:37 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_opener(char *rf)
{
	int		x;
	int		fd;
	char	buf;
	char	*str;

	x = 0;
	fd = open(rf, O_RDONLY);
	while (read(fd, &buf, 1))
		x++;
	str = ft_strnew(x);
	close(fd);
	x = 0;
	fd = open(rf, O_RDONLY);
	while (read(fd, &buf, 1))
		str[x++] = buf;
	close(fd);
	return (str);
}

int		main(int ac, char **av)
{
	int		piece;
	int		size;
	char	*grid;
	char	**new;
	char	*array;

	if (ac != 2)
		return (1);
	if (ac == 2)
	{
		grid = ft_opener(av[1]);
		new = ft_splitter(grid, &piece);
		size = ft_mapsize(piece);
		array = ft_strnew(size * (size + 1));
		ft_gridmaker(array, new, size, piece);
		ft_putchar('\n');
	}
	else
	{
		ft_putstr("usage: ");
		ft_putstr(av[0]);
		ft_putstr(" target_file\n");
	}
	return (0);
}
