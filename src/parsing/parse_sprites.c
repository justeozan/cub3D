/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 00:10:57 by ozasahin          #+#    #+#             */
/*   Updated: 2024/08/17 04:07:54 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	check_extension(char *line)
{
	if (!ft_strnstr2(line, ".xpm", 4))
		ft_exit(ERR_SPRITES_3);
}

static void	check_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 1)
	{
		ft_exit(ERR_FILE);
	}
	close(fd);
}

void	save_sprite_path(t_data *data, char *texture, t_cardinal point)
{
	int	i;

	i = -1;
	while (data->sprites[++i].path)
		if (point == data->sprites[i].point)
			ft_exit(ERR_SPRITES_5);
	if (point == NORTH)
		data->sprites[i].path = gc_strdup(texture, SPRITES);
	else if (point == SOUTH)
		data->sprites[i].path = gc_strdup(texture, SPRITES);
	else if (point == WEST)
		data->sprites[i].path = gc_strdup(texture, SPRITES);
	else if (point == EAST)
		data->sprites[i].path = gc_strdup(texture, SPRITES);
	data->sprites[i].point = point;
}

/***************************************
 * @file	parse_textures.c
 * @brief	Parse the textures of the map file
 * @param	data: the structure that contains all the data of the game
 * @param	line: the line where the textures are
***************************************/
void	parse_sprites(t_data *data, char *line)
{
	t_cardinal	point;

	// check_double_texture(data, line);
	point = 0;
	check_extension(line);
	if (line[0] == 'N')
		point = NORTH;
	else if (line[0] == 'S')
		point = SOUTH;
	else if (line[0] == 'W')
		point = WEST;
	else if (line[0] == 'E')
		point = EAST;
	else
		ft_exit(ERR_SPRITES_6);
	check_file(&line[3]);
	save_sprite_path(data, &line[3], point);
}
