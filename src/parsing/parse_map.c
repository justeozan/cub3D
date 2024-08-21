/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 08:46:20 by sei               #+#    #+#             */
/*   Updated: 2024/08/21 04:30:38 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	check_line(char *l, int width, int *nb_player, bool ext)
{
	int	j;

	j = -1;
	while (++j < width)
	{
		while (j < width && (l[j] == ' ' || l[j] == '1'))
			j++;
		if (j == width || !l[j])
			break ;
		if (j != 0 && l[j - 1] == '1' && ft_strchr("0NSWE", l[j]) && !ext)
		{
			while (l[j] && ft_strchr("0NSWE", l[j]))
			{
				if (ft_strchr("NSWE", l[j]))
					(*nb_player)++;
				j++;
			}
			if (l[j] != '1')
				ft_exit(ERR_MAP_4);
		}
		else
			ft_exit(ERR_MAP_5);
	}
}

// static bool	is_complete_wall(char *line, int width)
// {
// 	int	i;

// 	i = -1;
// 	while (++i < width)
// 		if (line[i] && line[i] != '1' && line[i] != ' ')
// 			return (false);
// 	return (true);
// }

static void	check_map(char **map, int height, int width)
{
	int	nb_player;
	// int	nb_wall;
	int	i;

	nb_player = 0;
	// nb_wall = 0;
	i = -1;
	while (++i < height)
	{
		check_line(map[i], width, &nb_player, i == 0 || i == height - 1);
		// if (is_complete_wall(map[i], width))
		// 	nb_wall++;
	}
	if (nb_player != 1)
		ft_exit(ERR_MAP_2);
	// if (nb_wall != 2) //REVIEW - Maybe useless.
	// 	ft_exit(ERR_MAP_6);
}

static void	get_size_map(t_data *data, char **file)
{
	int	i;
	int	j;

	i = 0;
	while (file[i])
	{
		j = 0;
		while (file[i][j])
			j++;
		if (j > data->map.width)
			data->map.width = j;
		i++;
	}
	data->map.height = i;
}

/***************************************
 * @file	parse_map.c
 * @brief	Parse the map of the map in file we received
 * @param	data: the structure that contains all the data of the game
 * @param	file: the file without whitespaces (!)
 * @note	Here we check if the map is valid, if there is only one player,
 * 			if the map is closed, etc.
***************************************/
void	get_map(t_data *data, char **file)
{
	char	**map;
	int		i;

	map = NULL;
	get_size_map(data, file);
	map = (char **)gc_malloc(sizeof(char *)
			* (size_t)(data->map.height), MAP);
	if (!map)
		ft_exit(ERR_MALLOC);
	i = -1;
	while (++i < data->map.height)
	{
		map[i] = (char *)gc_malloc(sizeof(char)
				*(size_t)(data->map.width + 1), MAP);
		if (!map[i])
			ft_exit(ERR_MALLOC);
		ft_strlcpy(map[i], file[i], (size_t)(data->map.width + 1));
	}
	check_map(map, data->map.height, data->map.width); //FIXME - Where i check around a 0 ??
	data->map.content = map;
	if (!data->map.content[0])
		ft_exit(ERR_MAP_3);
}
