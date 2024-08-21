/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 00:10:57 by ozasahin          #+#    #+#             */
/*   Updated: 2024/08/21 03:13:40 by ozasahin         ###   ########.fr       */
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
		ft_exit(ERR_FILE);
	close(fd);
}

void	save_sprite_path(t_data *data, char *texture, t_cardinal cardinal)
{
	// int	i;

	// i = -1;
	// while (data->sprites[++i].path)
	// 	if (cardinal == data->sprites[i].cardinal)
	// 		ft_exit(ERR_SPRITES_5);
	if (data->sprites[cardinal].path)
		ft_exit(ERR_SPRITES_5);
	data->sprites[cardinal].path = gc_strdup(texture, SPRITES);
	data->sprites[cardinal].cardinal = cardinal;
}

/***************************************
 * @file	parse_textures.c
 * @brief	Parse the textures of the map file
 * @param	data: the structure that contains all the data of the game
 * @param	line: the line where the textures are
***************************************/
void	parse_sprites(t_data *data, char *line)
{
	t_cardinal	cardinal;

	// check_double_texture(data, line);
	cardinal = 0;
	check_extension(line);
	if (line[0] == 'N')
		cardinal = NORTH;
	else if (line[0] == 'S')
		cardinal = SOUTH;
	else if (line[0] == 'W')
		cardinal = WEST;
	else if (line[0] == 'E')
		cardinal = EAST;
	else
		ft_exit(ERR_SPRITES_6);
	check_file(&line[3]);
	save_sprite_path(data, &line[3], cardinal);
}
