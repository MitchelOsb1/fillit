/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 11:54:31 by mosborne          #+#    #+#             */
/*   Updated: 2017/11/09 15:38:00 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

int	ft_validate(char **grid)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while (*grid[i])
	{
		while (grid[i][x])
		{
			if (grid[i][x] == '#')
			{
				if (grid[i][x + 1] == '#' && grid[i][x + 3] == '#')
					return (1);
				if (grid[i][x] == '#' && grid[i][x + 3] == '#')
					return (1);
			}
			x++;
		}
		i++;
	}
	return (0);
}

char	**ft_opener(char *av)
{
	int x;
	int fd;
	char buf;
	char *str;

	x = 0;
	fd = open(av, O_RDONLY);
	while (read(fd, &buf, 1))
		x++;
	str = (char *)malloc(sizeof(x));
	close(fd);
	x = 0;
	fd = open(av, O_RDONLY);
	while (read(fd, &buf, 1))
		str[x++] = buf;
	str = *ft_strsplit(str, '\n');
	return (&str);
}

int	main(int ac, char **av)
{
	char **grid;

	if (ac != 2)
		return (1);
	if (ac == 2)
	{
		printf("er\n");
		grid = ft_opener(av[1]);
		printf("%s", *grid);
		ft_validate(grid);
	}
}