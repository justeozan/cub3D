/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_ray_config.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:36:46 by avialle-          #+#    #+#             */
/*   Updated: 2024/08/29 15:36:47 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

void	init_ray(t_ray *ray, t_player player, double camera_x)
{
	ray->true_pos.x = player.pos.x;
	ray->true_pos.y = player.pos.y;
	ray->map_pos.x = (int)player.pos.x;
	ray->map_pos.y = (int)player.pos.y;
	ray->dir.x = player.dir.x + player.plane.x * camera_x;
	ray->dir.y = player.dir.y + player.plane.y * camera_x;
}

void	init_ray_dda(t_ray *r)
{
	r->delta_dist.x = fabs(1 / r->dir.x);
	r->delta_dist.y = fabs(1 / r->dir.y);
	if (r->dir.x < 0)
	{
		r->step_direction.x = -1;
		r->side_dist.x = (r->true_pos.x - r->map_pos.x) * r->delta_dist.x;
	}
	else
	{
		r->step_direction.x = 1;
		r->side_dist.x = (r->map_pos.x - r->true_pos.x + 1) * r->delta_dist.x;
	}
	if (r->dir.y < 0)
	{
		r->step_direction.y = -1;
		r->side_dist.y = (r->true_pos.y - r->map_pos.y)
			* r->delta_dist.y;
	}
	else
	{
		r->step_direction.y = 1;
		r->side_dist.y = (r->map_pos.y - r->true_pos.y + 1) * r->delta_dist.y;
	}
}
