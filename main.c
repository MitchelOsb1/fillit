/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: -_- <-_-@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 10:55:52 by -_-               #+#    #+#             */
/*   Updated: 2017/12/07 10:59:19 by -_-              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_opener(char *av)
{
	int x;
	int fd;
	char buf;
	char *str;

	x = 0;
	fd = open(av, O_RDONLY);
	while (read(fd, &buf, 1))
		x++;
	str = (char *)malloc(x);
	close(fd);
	x = 0;
	fd = open(av, O_RDONLY);
	while (read(fd, &buf, 1))
		str[x++] = buf;
	close(fd);
	return (str);
}

int	main(int ac, char **av)
{
	int piece;
	int size;
	char *grid;
	char **new;
	char *array;

	if (ac != 2)
		return (1);
	if (ac == 2)
	{
		grid = ft_opener(av[1]); // Open Reads and Mallocs
		new = ft_splitter(grid, &piece); // Breaking tetros into own arrays
		size = ft_mapsize(piece); // Finding the length of the map
		array = ft_strnew(size * (size + 1)); //Mallocing an array for grid
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
