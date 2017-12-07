/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 01:34:47 by mosborne          #+#    #+#             */
/*   Updated: 2017/12/06 18:02:06 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int   tet_poscheck(char *array, char *block, int size)
{
    if (block[0] && array[0] == '.')
    {
        array[0] = block[0];
        if (block[5])
        {
            return (1 + tet_poscheck(1 + array, 1 + block, size) +
                tet_poscheck(array - 1, block - 1, size) +
            tet_poscheck(array + size + 1, block + 5, size)); // use recursion to move the pieces
        }
        else
            return (1 + tet_poscheck(array + 1, block + 1, size) +
                    tet_poscheck(array - 1, block - 1, size));
    }
    else
      return (0);
}

void  tet_posremove(char *array, char *block, int size)
{
    if (array[0] == block[0] && array[0] != '\n')
    {
      array[0] = '.';
      tet_posremove(array - size - 1, block, size); // Unsure really how this works besides assigning it a value of .
      tet_posremove(array + 1, block, size);
      tet_posremove(array - 1, block, size);
      tet_posremove(array + size + 1, block, size);
    }
}


int     ft_solvetet(char *array, char **new, int size, int piece)
{
    int i;
    int check;
    char *block;

    i = -1;
    block = ft_piecefinder(*new);
    while (array[++i])
    {
      check = tet_poscheck(&array[i], block, size); // always 4 if valid tetromino
      if (check != 4)
        tet_posremove(&array[i], block, size);
      if (check == 4)
      {
        if (!ft_solvetet(array, &new[1], size, piece))
          tet_posremove(&array[i], block, size);
        else
          return (1);
      }
      i++;
    }
    return (0);
}
