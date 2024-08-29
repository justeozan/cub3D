/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 00:18:45 by ozasahin          #+#    #+#             */
/*   Updated: 2024/08/29 13:53:13 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

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

int	get_height_file(char *file)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 1)
		ft_exit(ERR_FILE);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (i);
}
