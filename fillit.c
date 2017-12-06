/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 11:54:31 by mosborne          #+#    #+#             */
/*   Updated: 2017/12/06 13:58:40 by mosborne         ###   ########.fr       */
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
	static int i = 0;

	if (ac != 2)
		return (1);
	if (ac == 2)
	{
		grid = ft_opener(av[1]);
		new = ft_splitter(grid, &piece);
		size = ft_mapsize(piece);
		array = ft_strnew(size * (size + 1));
		while(new[i])
		{
			printf("%s", new[i]);
			i++;
		}
	}
	else
	{
		ft_putstr("usage: ");
		ft_putstr(av[0]);
		ft_putstr(" target_file\n");
	}
	return (0);
}