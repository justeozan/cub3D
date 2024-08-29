/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 08:46:20 by sei               #+#    #+#             */
/*   Updated: 2024/08/29 18:02:28 by ozasahin         ###   ########.fr       */
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

static void	check_map(char **map, int height, int width)
{
	int	nb_player;
	int	i;
	int	j;

	nb_player = 0;
	i = -1;
	while (++i < height)
	{
		check_line(map[i], width, &nb_player, i == 0 || i == height - 1);
		j = -1;
		while (map[i][++j])
			if (map[i][j] == '0'
					&& (map[i - 1][j] == ' ' || map[i + 1][j] == ' '))
				ft_exit(ERR_MAP_7);
	}
	if (nb_player != 1)
		ft_exit(ERR_MAP_2);
}

/***************************************
 * @brief	Get the size of the map, the width and the height.
 * @param	data: the structure that contains all the data of the game
 * @param	file: the file at the map start
 ***************************************/
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
 * @brief	Main function to get the map,the objectif is to check if the map
 * is valid, if there is only one player, if the map is closed, etc.
 * And we put the map in the structure of the data.
 * @param	data: the structure that contains all the data of the game
 * @param	file: the file without whitespaces (!) and at the map start
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
	check_map(map, data->map.height, data->map.width);
	data->map.content = map;
	if (!data->map.content[0])
		ft_exit(ERR_MAP_3);
}
