/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avg38 <avg38@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 00:16:03 by ozasahin          #+#    #+#             */
/*   Updated: 2024/08/24 00:28:50 by avg38            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

/***************************************
 * @brief Get the player position from the map.
 * We search the player position in the map and store it in the player structure.
 * Position is stored in the player structure as a t_dvector.
 * The t_dvector is a structure with two double values x and y.
 * Futhermore, we store the cardinal point of the player in the player structure.
 * @see t_dvector in includes/cub3D.h
***************************************/
static void	get_player_pos(t_map map, t_player *player)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map.height)
	{
		j = -1;
		while (++j < map.width && map.content[i][j])
		{
			if (ft_strchr("NSWE", map.content[i][j]))
			{
				player->pos = (t_dvector){.x = j, .y = i};
				if (map.content[i][j] == 'N' )
					player->cardinal = NORTH;
				else if (map.content[i][j] == 'S')
					player->cardinal = SOUTH;
				else if (map.content[i][j] == 'W')
					player->cardinal = WEST;
				else if (map.content[i][j] == 'E')
					player->cardinal = EAST;
				return ;
			}
		}
	}
	ft_exit(ERR_INIT_6);
}

/***************************************
 * @brief Create the angle of the player for set where he is looking.
 * The angle is calculated based on the cardinal point of the player.
 * The angle is stored as a double value (for more precision).
 * And we convert the angle from degree to radian. @see to_rad in player_utils.c
 * @param player: the player structure to store the angle
 * @details The previous version of this function had cardinal_p as a parameter.
***************************************/
static void	create_angle(t_player *player)
{
	if (player->cardinal == EAST)
		player->dir_angle = to_rad(0);
	else if (player->cardinal == SOUTH)
		player->dir_angle = to_rad(90);
	else if (player->cardinal == WEST)
		player->dir_angle = to_rad(180);
	else if (player->cardinal == NORTH)
		player->dir_angle = to_rad(270);
	else
		ft_exit(ERR_INIT_7);
}

/***************************************
 * @brief Adjust the player position to the nearest walls.
 * We check the nearest walls to the player position and
 * we distance the player from the wall.
 * @param player: the player structure to store the direction
***************************************/
static void	adjust_player_pos_to_near_walls(char **map_p, t_player *player)
{
	if (map_p[(int)player->pos.y - 1][(int)player->pos.x])
		player->pos.y += 0.5;
	else if (map_p[(int)player->pos.y + 1][(int)player->pos.x])
		player->pos.y -= 0.5;
	if (map_p[(int)player->pos.y][(int)player->pos.x - 1])
		player->pos.x += 0.5;
	else if (map_p[(int)player->pos.y][(int)player->pos.x + 1])
		player->pos.x -= 0.5;
}

void	init_player(t_data *data, t_player *player)
{
	get_player_pos(data->map, player);
	create_angle(player);
	adjust_player_pos_to_near_walls(data->map.content, player);
	process_player_dir(player);
	process_player_plane(player);
	process_player_movement(player);
}
