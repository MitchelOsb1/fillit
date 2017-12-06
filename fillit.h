/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 11:51:05 by mosborne          #+#    #+#             */
/*   Updated: 2017/12/02 14:37:14 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "./libft/libft.h"

int		ft_success(char *str, char letter);
int		ft_block(char *str);
int		ft_checker(char *str, char piece);
char	**ft_malloc(char *str, int *piece, char letter);
char	**ft_splitter(char *str, int *piece);
char	*ft_opener(char *av);
int     ft_mapsize(int piece);
void	ft_builder(char *array, int size);
char	*ft_piecefinder(char *str);

#endif
