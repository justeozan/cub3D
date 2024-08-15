/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 08:46:20 by sei               #+#    #+#             */
/*   Updated: 2024/08/15 05:37:17 by ozasahin         ###   ########.fr       */
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
			while (l[j] && ft_strchr("0NSWE", l[j]) != NULL)
			{
				if (ft_strchr("NSWE", l[j]) != NULL)
					(*nb_player)++;
				j++;
			}
			if (l[j] != '1')
				ft_exit(ERR_MAP_4, EXIT_FAILURE);
		}
		else
			ft_exit(ERR_MAP_5, EXIT_FAILURE);
	}
}

static bool	is_complete_wall(char *line, int width)
{
	int	i;

	i = -1;
	while (++i < width)
		if (line[i] && line[i] != '1' && line[i] != ' ')
			return (false);
	return (true);
}

static void	check_map(char **map, int height, int width)
{
	int	nb_player;
	int nb_wall;
	int	i;
	
	nb_player = 0;
	nb_wall = 0;
	i = -1;
	while (++i < height)
	{
		check_line(map[i], width, &nb_player, i == 0 || i == height - 1);
		if (is_complete_wall(map[i], width))
			nb_wall++;
	}
	if (nb_player != 1)
		ft_exit(ERR_MAP_2, EXIT_FAILURE);
	if (nb_wall != 2)
		ft_exit(ERR_MAP_6, EXIT_FAILURE);
}

static void	get_size_map(t_data *data, char **file)
{
	int	i;
	int	j;

	i = 0;
	// print_file_without_spaces(file);
	while (file[i])
	{
		j = 0;
		while (file[i][j])
			j++;
		if (j > data->mappy.width)
		{
			data->mappy.width = j;
		}
		i++;
	}
	data->mappy.height = i;
}

void	get_map(t_data *data, char **file)
{
	char	**map;
	int		i;

	if (!data->no || !data->so || !data->we || !data->ea)
		ft_exit(ERR_SPRITES_2, EXIT_FAILURE);
	map = NULL;
	get_size_map(data, file);
	map = (char **)gc_malloc(sizeof(char *) * (size_t)(data->mappy.height), MAP);
	if (!map)
		ft_exit(ERR_MALLOC, EXIT_FAILURE);
	i = -1;
	while (++i < data->mappy.height)
	{
		map[i] = (char *)gc_malloc(sizeof(char) * (size_t)(data->mappy.width + 1), MAP);
		if (!map[i])
			ft_exit(ERR_MALLOC, EXIT_FAILURE);
		ft_strlcpy(map[i], file[i], (size_t)(data->mappy.width + 1));
	}
	check_map(map, data->mappy.height, data->mappy.width);
	data->mappy.content = map;
	if (!data->mappy.content[0])
		ft_exit(ERR_MAP_3, EXIT_FAILURE);
}
