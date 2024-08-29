/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_modifs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 00:26:35 by ozasahin          #+#    #+#             */
/*   Updated: 2024/08/29 15:36:42 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

static bool	try_move(t_map *map, t_dvector *pos, double dx, double dy)
{
	t_dvector	new;
	t_ivector	map_pos;
	t_ivector	map_pos2;

	new.x = pos->x + dx;
	new.y = pos->y + dy;
	map_pos.x = (int)(new.x + 0.3);
	map_pos2.x = (int)(new.x - 0.3);
	map_pos.y = (int)(new.y + 0.3);
	map_pos2.y = (int)(new.y - 0.3);
	if (map_pos.x < 0 || map_pos.x >= map->width || map_pos.y < 0
		|| map_pos.y >= map->height || map_pos2.x < 0
		|| map_pos2.x >= map->width || map_pos2.y < 0
		|| map_pos2.y >= map->height)
		return (false);
	if (map->content[map_pos.y][map_pos.x] != '1'
		&& map->content[map_pos2.y][map_pos.x] != '1'
		&& map->content[map_pos.y][map_pos2.x] != '1'
		&& map->content[map_pos2.y][map_pos2.x] != '1')
	{
		pos->x = new.x;
		pos->y = new.y;
		return (true);
	}
	return (false);
}

static void	manage_move(t_keys *key, t_player *player, t_dvector *move_wanted)
{
	if (key->w == 1)
	{
		move_wanted->x = player->movement.x;
		move_wanted->y = player->movement.y;
	}
	else if (key->s == 1)
	{
		move_wanted->x = -player->movement.x;
		move_wanted->y = -player->movement.y;
	}
	else if (key->a == 1)
	{
		move_wanted->x = player->movement.y;
		move_wanted->y = -player->movement.x;
	}
	else if (key->d == 1)
	{
		move_wanted->x = -player->movement.y;
		move_wanted->y = player->movement.x;
	}
}

static void	modif_player_pos(t_keys *key, t_player *player, t_map *map)
{
	t_dvector	move_wanted;
	t_dvector	new;

	new.x = player->pos.x;
	new.y = player->pos.y;
	move_wanted = (t_dvector){0, 0};
	manage_move(key, player, &move_wanted);
	if (!try_move(map, &new, move_wanted.x, move_wanted.y))
	{
		if (!try_move(map, &new, move_wanted.x, 0))
			try_move(map, &new, 0, move_wanted.y);
	}
	player->pos.x = new.x;
	player->pos.y = new.y;
}

static void	modif_player_dir(t_keys *key, t_player *player)
{
	if (key->left == 1)
	{
		player->dir_angle -= PLAYER_ROT_SPEED;
		if (player->dir_angle > 0)
			player->dir_angle += 2 * PI;
	}
	if (key->right == 1)
	{
		player->dir_angle += PLAYER_ROT_SPEED;
		if (player->dir_angle < 0)
			player->dir_angle -= 2 * PI;
	}
	process_player_dir(player);
	process_player_plane(player);
	process_player_movement(player);
}

void	modif_player(t_data *data)
{
	modif_player_pos(&data->keys, &data->player, &data->map);
	modif_player_dir(&data->keys, &data->player);
}
