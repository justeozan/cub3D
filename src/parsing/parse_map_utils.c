/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 00:11:06 by ozasahin          #+#    #+#             */
/*   Updated: 2024/08/29 18:17:02 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/***************************************
 * @brief	replace all the spaces in the map by walls
 * @param	map: the map checked
 * @param	height: the height of the map, means number of lines (start at 1)
 * @param	width: the width of the map, means number of characters
 * in a line (start at 1)
***************************************/
void	replace_space_by_wall(char **map, int height, int width)
{
	int	i;
	int	j;

	i = -1;
	while (++i < height)
	{
		j = -1;
		while (++j < width && map[i][j])
		{
			if (map[i][j] == ' ')
				map[i][j] = '1';
		}
	}
}
