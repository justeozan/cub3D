/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 00:18:45 by ozasahin          #+#    #+#             */
/*   Updated: 2024/08/17 04:06:57 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	handle_map_line(char **file, int *i, int *value)
{
	int	j;

	j = 0;
	while (file[*i] && file[*i][j])
	{
		while (file[*i][j] == ' ')
			j++;
		if (!ft_strchr("01", file[*i][j]))
			break ;
		(*i)++;
	}
	(*i)--;
	(*value)++;
}

/***************************************
 * @brief	Check the format of the map file (order of the elements)
 * @param	file: the entire file
 * @note	The order of the elements in the file must be: Four textures,
 * 			Two color, and Map
***************************************/
void	check_file_format(char **file)
{
	int	value;
	int	i;
	int	j;

	value = 0;
	i = -1;
	while (file[++i])
	{
		j = -1;
		while (file[i][++j] == ' ')
			;
		if (ft_strchr("NSWEFC", file[i][j]))
			value++;
		else if (ft_strchr("01", file[i][j]))
		{
			if (value >= 7)
				ft_exit(ERR_FILE_3);
			else if (value == 6)
				handle_map_line(file, &i, &value);
			else if (value < 6)
				ft_exit(ERR_FILE_1);
		}
	}
	if (value == 6)
		ft_exit(ERR_FILE_5);
}

// void	check_file_format(char **file)
// {
// 	int	value;
// 	int	i;
// 	int	j;

// 	value = 0;
// 	i = -1;
// 	while (file[++i])
// 	{
// 		j = -1;
// 		while (file[i][++j] == ' ')
// 			;
// 		if (ft_strchr("NSWEFC", file[i][j]))
// 			value++;
// 		while (file[i] && ft_strchr("NSWEFC", file[i][j]))
// 			i++;
// 		if (ft_strchr("01", file[i][j]))
// 		{
// 			if (value >= 3)
// 				ft_exit(ERR_FILE_3);
// 			else if (value == 2)
// 				handle_map_line(file, &i, &value);
// 			else if (value < 2)
// 				ft_exit(ERR_FILE_4);
// 		}
// 	}
// 	if (value == 6)
// 		ft_exit(ERR_FILE_5);
// }
