/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 01:34:47 by mosborne          #+#    #+#             */
/*   Updated: 2017/12/06 16:37:25 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int     tet_poscheck(char *array, char *block, int size)
{
    if (block[0] && array[0] == '.')
    {
        array[0] = block[0];
        if (block[5])
        {
            return (1 + tetposcheck(1 + array, 1 + block, size) + 
                tet_poscheck(array - 1, block - 1, size) +
            tet_poscheck(array + size + 1, block + 5, size));
        }
        else
            
    }
}

void    tet_posremove(char *array, char block, int size)
{

}

int     ft_solvetet(char *array, char **new, int size, int piece)
{
    char *block;

    block = ft_piecefinder(*array);
    while ()
}
