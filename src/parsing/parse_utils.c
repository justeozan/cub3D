/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 00:10:54 by ozasahin          #+#    #+#             */
/*   Updated: 2024/08/17 04:08:08 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/***************************************
 * @file	parse_utils.c
 * @brief	Parse the textures of the map file
 * @param	file: the file without whitespaces
***************************************/
int	count_line(char **file)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	return (i);
}
