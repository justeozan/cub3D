/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 00:26:10 by ozasahin          #+#    #+#             */
/*   Updated: 2024/08/19 23:22:42 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

double	to_rad(int degree)
{
	return (degree * PI / 180);
}

/***************************************
 * @brief We calculate the player direction based on the direction angle.
 * @param player: the player structure to store the direction
***************************************/
void	process_player_dir(t_player *player)
{
	player->dir.x = cos(player->dir_angle);
	player->dir.y = sin(player->dir_angle);
}

/***************************************
 * @brief We calculate the player plane based on the direction,
 * and depending on the FOV. The plane is perpendicular to the direction.
 * @param player: the player structure to store the plane
***************************************/
void	process_player_plane(t_player *player)
{
	player->plane.x = player->dir.y * PLANE_FOV;
	player->plane.y = -player->dir.x * PLANE_FOV;
}

/***************************************
 * @brief We calculate the player movement based on the direction angle
 * and the step size.
 * @param player: the player structure to store the movement
***************************************/
void	process_player_movement(t_player *player)
{
	player->movement.x = cos(player->dir_angle) * PLAYER_STEP_SIZE;
	player->movement.y = sin(player->dir_angle) * PLAYER_STEP_SIZE;
}
