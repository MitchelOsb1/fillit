/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: -_- <-_-@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 11:51:05 by mosborne          #+#    #+#             */
/*   Updated: 2017/12/07 11:02:22 by -_-              ###   ########.fr       */
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
int     ft_mapsize(int piece);
int     tet_poscheck(char *array, char *block, int size);
int     ft_solvetet(char *array, char **new, int size, int piece);
char	**ft_malloc(char *str, int *piece, char letter);
char	**ft_splitter(char *str, int *piece);
char	*ft_opener(char *av);
void	ft_builder(char *array, int size);
char	*ft_piecefinder(char *str);
void	ft_gridmaker(char *array, char **new, int size, int piece);
void    tet_posremove(char *array, char *block, int size);

#endif
