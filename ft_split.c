/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 21:26:50 by mosborne          #+#    #+#             */
/*   Updated: 2017/11/30 19:04:12 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_malloc(char *str, int *piece, char letter)
{
	char **temp;
	char *oldstr;

	oldstr = str;
	temp = (char **)malloc(sizeof(char *) * 27);
	while (*oldstr != '\0')
	{
		temp[*piece] = ft_strnew(21);
		ft_strncpy(temp[*piece], oldstr, 21);
		ft_success(temp[*piece], letter++);
		*piece += 1;
		oldstr += 21;
	}
	temp[*piece] = NULL;
	return (temp);
}

char	**ft_splitter(char *str, int *piece)
{
	char **newstr;

	printf("%s", str);
	if (!(ft_block(str)))
	{
		ft_putstr_fd("error1\n", 1);
		exit(0);
	}
	newstr = ft_malloc(str, piece, 'A');
	return (newstr);
}