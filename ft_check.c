/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 21:05:23 by mosborne          #+#    #+#             */
/*   Updated: 2017/12/02 12:52:41 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_checker(char *str, char piece)
{
	if (str[0] && str[0] == '#')
	{
		str[0] = piece;
		return (1 + ft_checker(str - 1, piece) + ft_checker(str + 1, piece)
		+ ft_checker(str + 5, piece));
	}
	else
		return (0);
}

int	ft_block(char *str)
{
	int i;
	static int a = 0;
	static int x = 0;

	i = 0;
	while (str[i] == '.' || str[i] == '#' || str[i] == '\n')
	{
		if (str[i] == '#' || str[i] == '.')
			x++;
		if (str[i] == '#')
			a++;
		i++;
	}
	if (x % 16 != 0)
		return (0);
	if (a % 4 != 0 || a == 0)
		return (0);
	return (((i + 1) % 21 != 0) ? 0 : 1);
}

int		ft_success(char *str, char letter)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '#' && ft_checker(&str[i], letter) == 1)
		{
			return (1);
		}
		i++;
	}
	return (0);
}
